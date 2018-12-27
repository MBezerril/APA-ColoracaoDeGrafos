#include "stdafx.h"
#include "Dijkstra.h"


Dijkstra::Dijkstra() {
}


Dijkstra::~Dijkstra() {
}

int Dijkstra::getMSTValue() {
	return FinalSolution;
}

int Dijkstra::StartSolution(std::string fileName) {
	FinalSolution = 0;
	try {
		// open the file
		std::ifstream file(fileName, std::fstream::in);
		if (!file.is_open()) return -100;

		//get the size and initialize the nodes array
		std::getline(file, line);
		graphSize = atoi(line.data());
		Nodes.resize(graphSize);
		//setting the root to value 0
		Nodes[0].setValue(0);
		Nodes[0].setMaster(NULL);
		//setting the values to "infinity"
		for (int i = 1; i < graphSize; i++) {
			Nodes[i].setValue(std::numeric_limits<int>::max());
			Nodes[i].setMaster(NULL);
		}
		//connect them
		//adding the link to others nodes and the weights
		for (int i = 0; i < graphSize - 1; i++) {
			std::getline(file, line);
			std::stringstream ss(line);
			for (int j = i + 1; j < graphSize; j++) {
				ss >> line;
				if (std::stoi(line) != 0) {
					Nodes[i].addLink(&Nodes[j], std::stoi(line));
					Nodes[j].addLink(&Nodes[i], std::stoi(line));
				}
			}
		}
		//Create the priority queue
		auto comp = [](node *a, node *b) { return a->getValue() > b->getValue(); };

		std::vector<node*> priority;
		priority.push_back(&Nodes[0]);

		while (!priority.empty()) {
			std::sort(priority.begin(), priority.end(), [](node *obj1, node *obj2) {return (obj1->getValue() < obj2->getValue()); });
			node* actual = priority.front();
			actual->setCheked(true);
			for (int i = 0; i < actual->getLinksNumber(); i++) {
				if (!actual->getLikedNode(i)->isChecked()) {
					node* aux = actual->getLikedNode(i);
					if (aux->getValue() != std::numeric_limits<int>::max()) {
						if ((actual->getLikedNodeValue(i) + actual->getValue()) < aux->getValue()) {
							aux->setMaster(actual);
							aux->setValue(actual->getLikedNodeValue(i) + actual->getValue());
						}
					}
					else {
						aux->setMaster(actual);
						aux->setValue((actual->getLikedNodeValue(i) + actual->getValue()));
						priority.push_back(actual->getLikedNode(i));
					}
				}
			}
			priority.erase(priority.begin());
		}
	}
	catch (std::exception& e) {
		return -200;
	}
	FinalSolution = Nodes.back().getValue();
	return 0;
}

void Dijkstra::ClearSolution() {
	Nodes.clear();
	FinalSolution = 0;
}