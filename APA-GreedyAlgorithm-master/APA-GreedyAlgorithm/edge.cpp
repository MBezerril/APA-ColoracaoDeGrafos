#include "stdafx.h"
#include "edge.h"

edge::edge(node *n1, node *n2, int v) {
	node1 = n1;
	node2 = n2;
	weight = v;
}

edge::edge(){}

edge::~edge() {
}

node * edge::getNode1() {
	return node1;
}

node * edge::getNode2() {
	return node2;
}

int edge::getWeight() {
	return weight;
}
