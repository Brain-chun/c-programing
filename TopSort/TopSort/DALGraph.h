#pragma once
#include "ALGraph.h"

class DALGraph : public ALGraph {
public:
	DALGraph(int size) : ALGraph(size) { }  virtual void addEdge(int fromV, int toV);
};
	