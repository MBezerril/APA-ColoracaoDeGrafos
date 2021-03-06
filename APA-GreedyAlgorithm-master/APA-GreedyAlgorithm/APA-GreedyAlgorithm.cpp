// APA-GreedyAlgorithm.cpp : defines the application entry point
/* Errors:
-100 : Wrong file name or file doesn't exist
-200 : error in some point of the processing
*/
#include "stdafx.h"
#include "APA-GreedyAlgorithm.h"
#include "Kruskal.h"
#include "Prim.h"
#include "Dijkstra.h"

int main() {
	Kruskal k;
	Prim p;
	Dijkstra d;
	std::string fileName;
	std::cin >> fileName;
	std::vector<edge> FinalSolution;
	fileName.insert(0, "Data/");
	if (k.StartSolution(fileName.data()) == 0) {
		std::cout << k.getMSTValue() << std::endl;

	}

	if (p.StartSolution(fileName.data()) == 0) {
		std::cout << p.getMSTValue() << std::endl;
	}

	if (d.StartSolution(fileName.data()) == 0) {
		std::cout << d.getMSTValue() << std::endl;
	}

	system("pause");
}