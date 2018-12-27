#pragma once
#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "edge.h"
#include "node.h"

class Kruskal
{
public:
	Kruskal();
	~Kruskal();
	// Returns the value of the minimum spamming tree found
	int getMSTValue();
	// Return the list of nodes with the edges of the MST solution
	std::vector<edge> getMST();
	int StartSolution(std::string fileName);
	void ClearSolution();
private:
	bool finish = false;
	node *Nodes;
	std::vector<edge> Edges;
	std::vector<edge> FinalSolution;
	int graphSize;
	std::string line;
};

