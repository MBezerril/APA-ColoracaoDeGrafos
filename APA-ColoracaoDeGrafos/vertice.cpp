#include "stdafx.h"
#include "vertice.h"


vertice::vertice() {
	cor = -1;
	status = 0;
}

vertice::~vertice() {
}

// Retorna todas os vertices adjacentes

int vertice::getQuantidadeAdjacentes() {
	return adjacentes.size();
}

int vertice::getAdjacente(int i) {
	return adjacentes[i];
}

int vertice::getCor() {
	return cor;
}

void vertice::setStatus(int i) {
	status = i;
}

int vertice::getStatus() {
	return status;
}

void vertice::setCor(int i) {
	cor = i;
}

void vertice::InserirAdjacente(int adj) {
	adjacentes.push_back(adj);
}

