// TopSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <cassert>
#include "DALGraph.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;
int main()
{
	cout << "Hello 20180622 천범수" << endl;
	// read graph from a file
	// first entry is size of graph
	const char* inFileName = "graph.dat";
	ifstream ifs(inFileName);
	assert(ifs); // make sure graph exists
	int n;
	ifs >> n;  DALGraph G(n);
	cout << "Created graph; n = " << G.vertexSize() << endl;
	// now read in the edges and add to the graph  
	int u, v;
	while (ifs >> u) {
		ifs >> v;
		G.addEdge(u, v);
	}
	cout << "Edges in graph: m = " << G.edgeSize() << endl;
	// count the number of in-edges for each vertex  
	int * vertices(new int[n]);
	assert(vertices);
	for (u = 0; u < n; u++)
		vertices[u] = 0;
	for (u = 0; u < n; u++) {
		NeighborIter ni(G, u);  while ((v = ++ni) != n)
			vertices[v]++;
	}
	// put vertices with no in-edge onto a stack  
	Stack < int > s;
	for (u = 0; u < n; u++)
		if (vertices[u] == 0)  s.push(u);
	if (s.isEmpty()) {
		cout << "graph has a cycle!\n";
		return 0;
	}
	// begin topological sort
	// As each vertex is identified, put it into a queue and
	// decrement the number of in-edges for its neighbors  
	int count = 0; // number of vertices found so far  
	Queue < int > sortedEdges;
	while (!s.isEmpty()) {
		count++;
		u = s.pop();  sortedEdges.enqueue(u);
		// reduce in count for u's neighbors;
		// for each that goes to zero, put on stack  
		NeighborIter ni(G,u);
		while ((v = ++ni) != n) {
			--vertices[v];
			if (vertices[v] == 0)  s.push(v);
		}
	}

	// check results  if (count < n)
	cout << "Couldn't complete top sort -- cycle present.\n";  cout << "Ordering for top sort: \n";
	while (!sortedEdges.isEmpty())
		cout << sortedEdges.dequeue() << '\t';  cout << endl;
	return n;
}
