#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <wait.h>
#include <pthread.h>
#include <signal.h>
#include <syslog.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

#define true 1
#define false 0

#define NAMEMAX 255
#define BUFLEN 64
#define FILELEN 256

FILE *log_fp;
char *monitor_list = "monitor_list.txt";
char **arglist = NULL;
char *tree_tab = "│   ";
char *tree_mid = "├── ";
char *tree_end = "└── ";
volatile sig_atomic_t signal_received = 0;
int argcnt = 0;

//명령어별 함수 처리를 위한 배열
char *commanddata[7]={
    "add",
    "delete",
    "tree",
    "help",
    "exit"
  };

//tree 구조체 
typedef struct tree {
    char path[BUFLEN]; //각 노드의 realpath가 저장됨 
    bool isEnd; //노드가 최종임을 확인
    mode_t mode; //각 노드(path)의 st_mode 저장 
    time_t mtime; //각 노드(path)의 st_mtime 저장 
    struct tree *next; //현재 노드에서 같은 가지 레벨에 붙어있는 다음 노드
    struct tree *prev; //현재 노드에서 같은 가지 레벨에 붙어있는 이전 노드
    struct tree *child; //현재 노드에서 붙어있는 다음 가지 레벨의 노드
    struct tree *parent; //현재 노드에서 붙어있는 이전 가지 레벨의 노드
} tree;

typedef struct command_parameter {
  char *command;
	char *filename;
	char *tmpname;
	int commandopt;
  char *argv[10];
} command_parameter;

void help();

//monitor_list 파일에 해당 디렉토리가 monitoring중인제 확인하는 함수
//False : 모니터링 X True : 모니터링 O
bool monitored(const char* path) {
    FILE* file = fopen(monitor_list, "r");

    if (file != NULL) {
        char line[PATH_MAX];
        while (fgets(line, sizeof(line), file) != NULL) {
	    //line에서 path 정보만 추출하는 부분 " " 뒷 부분 제거
	    // line : 모니터링중인 경로 path : 입력한 경로
	    char* space = strchr(line, ' ');
	    if (space != NULL) {
		    *space = '\0';
	    }
	    // 경로가 다른거나 어느 한쪽에 포함되는 경우 가지치기
            if (strstr(line, path) != NULL) {
                fclose(file);
		if (strcmp(line, path)) 
			return false;
		else
                	return true;
            } else if (strstr(path, line) != NULL) {
		fclose(file);
		if (strcmp(line, path))
			return false;
		else
			return true;
	    }
        }
        fclose(file);
    }
    return false;
}


char *QuoteCheck(char **str, char del) {
  char *tmp = *str+1;
  int i = 0;

  while(*tmp != '\0' && *tmp != del) {
    tmp++;
    i++;
  }
  if(*tmp == '\0') {
    *str = tmp;
    return NULL;
  }
  if(*tmp == del) {
    for(char *c = *str; *c != '\0'; c++) {
      *c = *(c+1);
    }
    *str += i;
    for(char *c = *str; *c != '\0'; c++) {
      *c = *(c+1);
    }
  }
}

char *Tokenize(char *str, char *del) {
  int i = 0;
  int del_len = strlen(del);
  static char *tmp = NULL;
  char *tmp2 = NULL;

  if(str != NULL && tmp == NULL) {
    tmp = str;
  }

  if(str == NULL && tmp == NULL) {
    return NULL;
  }

  char *idx = tmp;

  while(i < del_len) {
    if(*idx == del[i]) {
      idx++;
      i = 0;
    } else {
      i++;
    }
  }
  if(*idx == '\0') {
    tmp = NULL;
    return tmp;
  }
  tmp = idx;

  while(*tmp != '\0') {
    if(*tmp == '\'' || *tmp == '\"') {
      QuoteCheck(&tmp, *tmp);
      continue;
    }
    for(i = 0; i < del_len; i++) {
      if(*tmp == del[i]) {
        *tmp = '\0';
        break;
      }
    }
    tmp++;
    if(i < del_len) {
      break;
    }
  }

  return idx;
}

char **GetSubstring(char *str, int *cnt, char *del) {
  *cnt = 0;
  int i = 0;
  char *token = NULL;
  char *templist[100] = {NULL, };
  token = Tokenize(str, del);
  if(token == NULL) {
    return NULL;
  }

  while(token != NULL) {
    templist[*cnt] = token;
    *cnt += 1;
    token = Tokenize(NULL, del);
  }
  
	char **temp = (char **)malloc(sizeof(char *) * (*cnt + 1));
	for (i = 0; i < *cnt; i++) {
		temp[i] = templist[i];
	}
	return temp;
}


