#pragma once
#include <limits>
#include <queue>
#include "node.h"

class Prim
{
public:
	Prim();
	~Prim();
	int getMSTValue();
	int StartSolution(std::string fileName);
	void ClearSolution();
private:
	std::vector<node> Nodes;
	int FinalSolution;
	int graphSize;
	std::string line;

};

