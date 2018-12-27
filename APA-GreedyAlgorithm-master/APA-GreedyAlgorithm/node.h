#pragma once
#include <vector>
class node
{
public:
	node();
	~node();
	node* getMaster();
	void setMaster(node *n);
	std::vector<node *> getLinkedNodes();
	void addNode(node *n);
	void addLink(node *n, int w);
	//Returns the value to node in the position p of the vector
	int getLikedNodeValue(int p);
	//Returns the pointer to node in the position p of the vector
	node * getLikedNode(int p);
	int getLinksNumber();
	int getNodePosition(node * n);
	int getValue();
	void passValue(int g);
	void setValue(int g);
	bool isChecked();
	void setCheked(bool c);
private:
	int value;
	node* master;
	bool checked = false;
	std::vector<node *> LinkedNodes;
	std::vector<int> LinkedNodesValues;
};

