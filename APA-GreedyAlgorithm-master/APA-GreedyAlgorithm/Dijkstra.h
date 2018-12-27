#pragma once
#include <limits>
#include <queue>
#include "node.h"

class Dijkstra
{
public:
	Dijkstra();
	~Dijkstra();
	int getMSTValue();
	int StartSolution(std::string fileName);
	void ClearSolution();
private:
	std::vector<node> Nodes;
	int FinalSolution;
	int graphSize;
	std::string line;
};


