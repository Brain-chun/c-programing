#pragma once
#include "amGraph.h"
class UAMGraph : public amGraph {
public:
	UAMGraph(int size, int initialValue = 0) :
		amGraph(size) { }
	virtual void addEdge(int fromV, int toV);
};
