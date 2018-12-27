#include "stdafx.h"
#include "node.h"


node::node() {
	LinkedNodes.clear();
	checked = false;
}


node::~node() {
}

node* node::getMaster() {
	return master;
}

void node::setMaster(node * n) {
	master = n;
}

std::vector<node *> node::getLinkedNodes() {
	return LinkedNodes;
}

void node::addNode(node * n) {
	LinkedNodes.push_back(n);
}

void node::addLink(node *n, int w) {
	LinkedNodes.push_back(n);
	LinkedNodesValues.push_back(w);
}

int node::getLikedNodeValue(int p) {
	return LinkedNodesValues[p];
}

node * node::getLikedNode(int p) {
	return LinkedNodes[p];
}

int node::getValue() {
	return value;
}
void node::setValue(int v) {
	value = v;
}
bool node::isChecked() {
	return checked;
}
void node::setCheked(bool c) {
	checked = c;
}
//returns how many links were made
int node::getLinksNumber() {
	return LinkedNodesValues.size();
}

int node::getNodePosition(node * n) {
	for (int i = 0; i < LinkedNodes.size(); i++) if (LinkedNodes[i] == n) return i;
}

void node::passValue(int v) {
	value = v;
	for (int i = 0; i < LinkedNodes.size(); i++) {
		if (LinkedNodes[i]->getValue() != value)
			LinkedNodes[i]->passValue(v);
	}
}

