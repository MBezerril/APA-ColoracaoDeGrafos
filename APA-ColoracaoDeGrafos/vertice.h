#pragma once

#include <vector>

class vertice
{
public:
	vertice();
	~vertice();
	// Retorna todas os vertices adjacentes
	int getAdjacente(int i);
	void InserirAdjacente(int adj);
	void setCor(int i);
	int getCor();
	void setStatus(int i);
	int getStatus();
	int getQuantidadeAdjacentes();

private:
	int cor;
	int status;
	std::vector<int> adjacentes;
};

