#include "stdafx.h"
#include "Kruskal.h"

Kruskal::Kruskal() {
}


Kruskal::~Kruskal() {
}


// Returns the value of the minimum spamming tree found
int Kruskal::getMSTValue() {
	int size = 0;
	for (auto& var : FinalSolution) {
		size += var.getWeight();
	}
	return size;
}


// Return the list of nodes with the edges of the MST solution
std::vector<edge> Kruskal::getMST() {
	return FinalSolution;
}


int Kruskal::StartSolution(std::string fileName) {

	try {
		std::ifstream file(fileName, std::fstream::in);
		if (!file.is_open()) return -100;

		std::getline(file, line);
		graphSize = atoi(line.data());
		Nodes = new node[graphSize]();
		for (int i = 0; i < graphSize - 1; i++) {
			std::getline(file, line);
			std::stringstream ss(line);
			for (int j = i + 1; j < graphSize; j++) {
				ss >> line;
				if (std::stoi(line) != 0) {
					edge aux(&Nodes[i], &Nodes[j], std::stoi(line));
					Edges.push_back(aux);
				}
			}
		}
		for (int i = 0; i < graphSize; i++) {
			Nodes[i].setValue(i);
		}
		std::sort(Edges.begin(), Edges.end(), [](edge obj1, edge obj2) {return (obj1.getWeight() < obj2.getWeight()); });
		int actual = 0;
		while (!finish && actual < Edges.size()) {
			int group1 = Edges[actual].getNode1()->getValue();
			int group2 = Edges[actual].getNode2()->getValue();
			if (Nodes[group1].getValue() != Nodes[group2].getValue()) {
				Nodes[group2].passValue(Nodes[group1].getValue());
				Nodes[group2].addNode(&Nodes[group1]);
				Nodes[group1].addNode(&Nodes[group2]);
				FinalSolution.push_back(Edges[actual]);
			}
			actual++;
			int aux = Nodes[0].getValue();
			finish = true;
			for (int i = 1; i < graphSize; i++) {
				if (Nodes[i].getValue() != aux)
					finish = false;
			}
		}
	}
	catch (std::exception& e) {
		return -200;
	}
	return 0;
}

void Kruskal::ClearSolution() {
	delete[] Nodes;
	Edges.clear();
	FinalSolution.clear();
}

