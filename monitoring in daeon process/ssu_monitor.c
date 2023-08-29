#include "ssu_header.h"

// 노드를 만들고 각 변수들 초기화 
tree *create_node(char *path, mode_t mode, time_t mtime) {
        tree *new;

        new = (tree *)malloc(sizeof(tree));
        strcpy(new->path, path);
        new->isEnd = false;
        new->mode = mode;
        new->mtime = mtime;
        new->next = NULL;
        new->prev = NULL;
        new->child = NULL;
        new->parent = NULL;

        return new;
}

// 하위 디렉토리 검사시 현재 디렉토리, 상위 디렉토리, log.txt, monitor_list 제외
int scandir_filter(const struct dirent *file) {
        if (!strcmp(file->d_name, ".") || !strcmp(file->d_name, "..")
                        || !strcmp(file->d_name, "log.txt")
                        || !strcmp(file->d_name, monitor_list)) {
                return 0;
        }
        else
                return 1;
}

// 디몬 프로세스 생성
pid_t make_daemon(void) {
  pid_t pid;
  int fd, maxfd;

  if ((pid = fork()) < 0) {
    fprintf(stderr, "fork error\n");
    exit(1);
  }
  else if (pid != 0)
    exit(0);

  pid = getpid();
  setsid();
  signal(SIGTTIN, SIG_IGN);
  signal(SIGTTOU, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  maxfd = getdtablesize();

  for (fd = 3; fd < maxfd; fd++)
    close(fd);

  umask(0);
  //chdir("/");
  fd = open("/dev/null", O_RDWR);
  dup(0);
  dup(0);
  return getpid();
}

// 트리만들기
void make_tree(tree *dir, char *path) {
	struct dirent **filelist;
	struct stat statbuf;
	char new_path[BUFLEN];
	int count;
	int i;

	//printf("make tree func start\n");
	//path에 있는 유효한 파일 갯수 확인
	if ((count = scandir(path, &filelist, scandir_filter, alphasort)) < 0) {
		fprintf(stderr, "in function make_tree: scandir error for %s\n", path);
		return;
	}
	
	for (i = 0; i < count; i++) {
		tree *new_node;
		tree *temp;

		bzero(new_path, BUFLEN);
		strcpy(new_path, path);
		strcat(new_path, "/");
		strcat(new_path, filelist[i]->d_name);
		//sprintf(new_path, "%s/%s", path, filelist[i]->d_name);

		if (stat(new_path, &statbuf) < 0) {
			fprintf(stderr, "stat error for %s\n", new_path);
			return;
		}

		//for 문을 돌며 한번의 루프 당 노드를 만들어 링크드 리스트로 연결
		new_node = create_node(new_path, statbuf.st_mode, statbuf.st_mtime);

		//최초의 노드일때 (디렉토리 내부로 들어온 경우 포함)
		if (i == 0) {
			//부모노드와 자식노드로 서로를 연결
			dir->child = new_node;
			new_node->parent = dir;
		}
		else {
			temp = dir->child; // 임시 노드에 자식노드를 복사

			while (temp->next != NULL) {
				temp = temp->next; // 이미 붙어있는 노드가 있을 시 마지막까지 이동
			}

			// 노드가 마지막인 경우 새 노드를 서로 연결
			temp->next = new_node;
			new_node->prev = temp;
		}

		if (i == count - 1)
			new_node->isEnd = true;

		if (S_ISDIR(statbuf.st_mode)) {
			// 노드가 디렉토리인 경우 낮은 단으로 새로운 트리 연결
			make_tree(new_node, new_path);
		}
	}
}

// 트리 비교
void compare_tree(tree *old, tree *new) {
	time_t curtime;
	struct tm* t;
	char daystr[FILELEN];
	char message[BUFLEN];

	curtime = time(NULL);
	t = localtime(&curtime);

	memset(daystr, 0, FILELEN);
	sprintf(daystr, "%d-%02d-%02d %02d:%02d:%02d", t->tm_year+1900, t->tm_mon+1,
			t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

	if (old == NULL && new == NULL) {//old new가 모두 NULL 인 경우 유일하게 종료되는 부분
		return;
	} else if (old != NULL && new == NULL) {//old에서 있던 노드가 없어짐
		if (S_ISREG(old->mode)) {//정규 파일인 경우에만 작성
			fprintf(log_fp, "[%s][remove][%s]\n", daystr, old->path);
		}
		//현재 노드에서 next, child로 비교 
		//next가 이미 null 이므로 두 번째 인자로 NULL 입력
		compare_tree(old->next, NULL);
		compare_tree(old->child, NULL);
	} else if (old == NULL && new != NULL) {//old에 없던 노드가 생김
		if (S_ISREG(new->mode)) {//정규 파일의 경우에만 기록
			fprintf(log_fp, "[%s][create][%s]\n", daystr, new->path);
		}
		//현재 노드에서 next, child 비교
		//old가 이미 null 이므로 첫 번째 인자로 NULL 입력
		compare_tree(NULL, new->next);
		compare_tree(NULL, new->child);
	} else {
		if (!strcmp(old->path, new->path)) {//파일 자체가 그대로 있는 경우
			if (S_ISREG(old->mode) && S_ISREG(new->mode)) {//두 노드가 모두 정규 파일인 경우
			    if (old->mtime != new->mtime) {//두 노드의 수정시간이 다른 경우 수정 기록
				fprintf(log_fp, "[%s][modify][%s]\n", daystr, new->path);
			    }
			}
			//두 노드의 모드가 다른경우
			else if ((old->mode & S_IFMT) != (new->mode & S_IFMT)) {
			    fprintf(log_fp, "[%s][modify][%s]\n", daystr, old->path);
			}
			compare_tree(old->next, new->next);
			compare_tree(old->child, new->child);
		} else if (strcmp(old->path, new->path) < 0) { // 파일이 삭제되어 다음 붙어있던 노드가 당겨졌을 경우
			if (S_ISREG(old->mode)) {
			    fprintf(log_fp, "[%s][remove][%s]\n", daystr, old->path);
			}/*
			compare_tree(old->next, NULL);
			compare_tree(old->child, NULL);
			*/
		} else {
			if (S_ISREG(new->mode)) { // 파일이 생성되어 먼저 붙어있던 노드가 밀렸을 경우
			    fprintf(log_fp, "[%s][create][%s]\n", daystr, new->path);
			}/*
			compare_tree(NULL, new->next);
			compare_tree(NULL, new->child);
			*/
		}
	}
}

// 링크드 리스트로 연결되어있던 트리 해제
void free_tree(tree *cur) {
	if (cur->child != NULL)
		free_tree(cur->child);

	if (cur->next != NULL)
		free_tree(cur->next);

	if (cur != NULL) {
		cur->prev = NULL;
		cur->next = NULL;
		cur->parent = NULL;
		cur->child = NULL;
		free(cur);
	}
}

// 디몬프로세스 상에서 동작하는 경우
void init_daemon(char *dirpath, time_t mn_time) {
	pid_t pid, dpid;
	char path[BUFLEN];
	FILE *fp;
	tree *head;
	tree *new_tree;
	struct stat st;
	
        if ((pid = fork()) < 0) {
                fprintf(stderr, "fork error\n");
                exit(1);
        }
        else if (pid == 0) { //child
                if ((dpid = make_daemon()) < 0) {
                        fprintf(stderr, "make_daemon error\n");
                        exit(1);
                }

		// 디몬이 정상적으로 생성되면 해당 파일에 path와 pid를 기록 
		fp = fopen(monitor_list, "a+");
		fprintf(fp, "%s %d\n", dirpath, dpid);
		fclose(fp);

		// 루프를 돌기 전 최초의 디렉토리 상태를 트리로 기록
		head = create_node(dirpath, 0, 0);
		make_tree(head, dirpath);

                while (!signal_received) {
			if ((log_fp = fopen("log.txt", "a+")) == NULL) {
				fprintf(stderr, "fopen error for %s\n", "log.txt");
				return;
			}
			// 루프를 돌며 지속적으로 새로운 디렉토리 구조를 모니터링
			new_tree = create_node(dirpath, 0, 0);
			make_tree(new_tree, dirpath);

			//기존의 트리구조와 새로운 트리 구조를 비교
			compare_tree(head, new_tree);

			free_tree(head); // 기존의 트리를 해제
			head = new_tree; // 새로운 트리 구조를 head에 복사
			new_tree = NULL; // 복사한 후 트리를 초기화
			
			fclose(log_fp);
			sleep(mn_time); // -t 옵션으로 정한 모니터링 시간 간격만큼 sleep
    		}
                exit(0);
        }
	else {
		//부모프로세스는 자식이 끝날때 까지 대기
		sleep(0.5);
		int status;
		waitpid(pid, &status ,0);
		return;
	}
}	

// 단순 help func을 exec 함수로 출력
void HelpExec() {
  pid_t pid;

  if((pid = fork()) < 0) {
    fprintf(stderr, "ERROR: fork error\n");
    exit(1);
  } else if(pid == 0) {
    execl("/bin/sh","sh","-c","./help",NULL);
    exit(0);
  } else {
    pid = wait(NULL);
  }
}

void exe_add() {
	char path[BUFLEN];
	char real_path[BUFLEN];
	char line[BUFLEN];
	struct stat st;
	pid_t pid;
	FILE *fp;
	time_t mn_time;

	if (argcnt != 2 && argcnt != 4) { // 단순 add와 t옵션의 시간이 포함되어있지 않는 경우 프롬프트 재출력
		fprintf(stderr, "Usage:\n > add <DIRPATH> [OPTION]\n");
		return;
	}
	strcpy(path, arglist[1]);
	
	if (stat(path, &st) < 0) { // 올바르지 않은 경로가 주어졌을 시 프롬프트 재출력
		fprintf(stderr, "Usage:\n > add <DIRPATH> [OPTION]\n");
		return;
	}

	if (!S_ISDIR(st.st_mode)) { // 경로가 디렉토리가 아닌경우 프롬프트 재출력
		fprintf(stderr, "Usage:\n > add <DIRPATH> [OPTION]\n");
		return;
	}

	// path를 절대 경로화
	if (path[0] != '/')
		realpath(path, real_path);
	else
		strcpy(real_path, path);

	if (argcnt == 4) {
		// 올바르지 않은 옵션이 입력되었을 경우 프롬프트 재출력
		if (strcmp(arglist[2], "-t")) {
			fprintf(stderr, "Usage:\n > add <DIRPATH> [OPTION]\n");
			return;
		}

		if ((mn_time = atol(arglist[3])) <= 0) { // -t옵션 인자로 음수나 숫자가 아닌 문자가 들어왔을 경우 프롬프트 재출력
			fprintf(stderr, "Usage:\n > add <DIRPATH> [OPTION]\n");
			return;
		}
	} else
		mn_time = 1; // 옵션이 지정되지 않은 경우는 1초마다 모니터링

	//모니터링 관리 파일을 fp append로 fopen
	if ((fp = fopen(monitor_list, "a+")) == NULL) {
		fprintf(stderr, "in fucntions exe_add: fopens error for %s\n", monitor_list);
		return;
	}

	fseek(fp, 0, SEEK_SET);
	
	while (fscanf(fp, "%[^\n]%*c", line) != EOF) {
		char *token = strtok(line, " ");
	}

	fclose(fp);

	if (monitored(real_path)) {//monitored 함수를 통해 해당 path가 이미 실행중인 
				   //디몬 프로세스인지 확인, 에러처리
		fprintf(stderr, "%s is already monitoring!!\n", real_path);
		exit(1);
	} else {// 디몬 프로세스 생성
		init_daemon(real_path, mn_time);
	}
	printf("monitoring started (%s)\n", real_path);
	return;
}


void exe_del() {
	//printf("del func start\n");
	char line[BUFLEN];
	char path[BUFLEN];
	char *tmpfile = "__tmp.txt";
	pid_t pid, dpid;
	FILE *fp, *fp2;

	if (argcnt != 2) { // 잘못된 인자 수 입력
		fprintf(stderr, "Usage : delete <DAEMON_PID>\n");
		return;
	}

	if ((pid = atoi(arglist[1])) <= 0) { // 올바르지 않은 pid 가 들어왔을 경우 에러처리
		fprintf(stderr, "invalid pid num\n");
		return;
	}

	if ((fp = fopen(monitor_list, "r")) == NULL) {
		fprintf(stderr, "fopen error for %s\n", monitor_list);
		exit(1);
	}

	if ((fp2 = fopen(tmpfile, "w+")) == NULL) {
		fprintf(stderr, "fopen error for %s\n", monitor_list);
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	bzero(line, BUFLEN);

	int cnt = 0;
	while (fscanf(fp, "%[^\n]%*c", line) != EOF) {
		sscanf(line, "%s %d", path, &dpid);
		if (pid == dpid) {
			kill(dpid, SIGUSR1); //delete하려는 pid가 동일 한 경우 SIGUSR1을 보내 디몬프로세스 종료
                	printf("monitoring ended (%s)\n", path);
			cnt += 1;
			continue;
		} else {
			fprintf(fp2, "%s %d\n", path, dpid);
		}
	}
	if (cnt == 0) // 모든 라인을 검색해도 해당 PID가 없는 경우 
		fprintf(stderr, "<DAEMON PID> : %d doesn't exist in %s\n", pid, monitor_list);

	fclose(fp);
	fclose(fp2);
	// 기존 monitor_list를 지우고 임시 저장한 tmpfile 이름 변경 
	remove(monitor_list);
	rename(tmpfile, monitor_list);

	return;
}

// tree 함수의 실질적 출력 부분
void __execute_tree(tree *node, int level) {
	char *filename;

	if (node == NULL)
		return;

	filename = strrchr(node->path, '/');
	filename++;
	//printf("current level : %d\n", level);

	if (level == 0) { // 최초의 레벨에 들어왔을 경우 (path) 출력 디렉토리 노드에서 들어온 경우 포함
		printf("%s\n", filename);
		__execute_tree(node->child, level + 1); // 자식 노드로 이동 
		__execute_tree(node->next, level); // 같은 레벨의 다음 노드로 이동
		return;
	}

	if (level > 1) // 레벨이 1 보다 큰 경우 tree tab 출력
		printf("%s", tree_tab);

	// 공백 출력
	for (int i = 1; i < level - 1; i++) {
		printf("    ");
	}

	if (node->next != NULL) {
		printf("%s %s\n", tree_mid, filename); // 같은 레벨에서 노드가 연결되어 있을 경우
	} else {
		printf("%s %s\n", tree_end, filename); // 같은 레벨에서 마지막 노드인 경우
	}

	__execute_tree(node->child, level + 1);
	__execute_tree(node->next, level);
}

void exe_tree() {
	struct stat statbuf;
	char path[BUFLEN];
	char real_path[BUFLEN];
	char line[BUFLEN];
	FILE *fp;
	tree *head;
	int check = 0;

	if (argcnt != 2) {
		fprintf(stderr, "Usage : tree <DIRPATH>\n");
		return;
	}

	bzero(path, BUFLEN);
	bzero(real_path, BUFLEN);
	bzero(line, BUFLEN);
	strcpy(path, arglist[1]);

	if (stat(path, &statbuf) < 0) {
		fprintf(stderr, "stat error for %s\n", path);
		return;
	}

	if (!S_ISDIR(statbuf.st_mode)) {
		fprintf(stderr, "%s is  not directory\n", path);
		return;
	}

	if (path[0] != '/')
		realpath(path, real_path);
	else
		strcpy(real_path, path);

	if ((fp = fopen(monitor_list, "r")) == NULL) {
		fprintf(stderr, "fopen error for %s\n", monitor_list);
		return;
	}

	fseek(fp, 0, SEEK_SET);


	//tree 출력을 위한 현재 상태 make tree
	head = create_node(real_path, 0, 0);
	make_tree(head, real_path);
	
	while (fscanf(fp, "%[^\n]%*c", line) != EOF) {
		char *token = strtok(line, " ");
		
		if (!strcmp(line, real_path)) { // 라인과 입력한 경로가 동일한 경우에만 출력
			check = 1; // 있으면 플래그 변경
			__execute_tree(head, 0);
		}
	}

	if (!check) // 입력한 경로가 모니터링 중 이지 않은 경우
		fprintf(stderr, "\"%s\" must be in \"monitor_list.txt\"\n",real_path);
	
	fclose(fp);
}

// 프롬프트 출력 각 명령어들을 입력받고 명령어 별로 함수 실행
int Prompt() {
  char input[NAMEMAX];

  while(true) {
    printf("20180622> ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';

                if((arglist = GetSubstring(input, &argcnt, " \t")) == NULL) {
      continue;
    }

    if(argcnt == 0) continue;

                if(!strcmp(arglist[0], commanddata[0])) {
			exe_add();
                } else if(!strcmp(arglist[0], commanddata[1])) {
			exe_del();
                }       else if(!strcmp(arglist[0], commanddata[2])) {
			exe_tree();
                }       else if(!strcmp(arglist[0], commanddata[3])) {
			HelpExec();
                }       else if(!strcmp(arglist[0], commanddata[4])) {
   			fprintf(stdout, "Program exit(0)\n");
      			exit(0);
                }       else {
			HelpExec();
                }
  }
}

int main(int argc, char* argv[])
{
	if (argc != 1) {
		fprintf(stderr, "Doesn't need any other arguments\n");
		exit(1);
	}

	Prompt();
        exit(0);
}
