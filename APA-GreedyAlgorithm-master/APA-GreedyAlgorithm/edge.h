#pragma once
#include "node.h"

class edge
{
public:
	//
	edge(node * o, node * t, int v);
	edge();
	~edge();
	node *getNode2();
	node *getNode1();
	int getWeight();
private:
	int weight = 0;
	node *node1 = NULL;
	node *node2 = NULL;
};

