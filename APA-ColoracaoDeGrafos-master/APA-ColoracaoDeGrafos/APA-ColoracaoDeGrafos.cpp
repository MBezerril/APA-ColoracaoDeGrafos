// APA-ColoracaoDeGrafos.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "vertice.h"

struct Cor
{
	std::vector<int> itens;
};

vertice *vertices;
int loopzaco = 0;
int quantidade;

std::vector<Cor> cores;

bool inicializar() {
	std::ifstream arquivo("entrada.txt", std::ifstream::in);
	if (!arquivo.is_open())
		return false;
	std::string linhaLida, pedaco;
	std::stringstream linhaProcessar;
	std::getline(arquivo, linhaLida);
	linhaProcessar << linhaLida;
	linhaProcessar >> pedaco;
	if (pedaco != "p")
		return false;
	linhaProcessar >> pedaco;
	if (pedaco != "edge")
		return false;
	linhaProcessar >> pedaco;
	quantidade = std::stoi(pedaco);
	vertices = new vertice[quantidade];
	linhaProcessar >> pedaco;
	loopzaco = std::stoi(pedaco);

	for (int i = 0; i < loopzaco; i++) {
		int primeiro, segundo;
		std::getline(arquivo, linhaLida);
		linhaProcessar.clear();
		linhaProcessar.str(linhaLida);
		linhaProcessar >> pedaco; // tirar o 'e'
		linhaProcessar >> pedaco; // pega o primeiro
		primeiro = std::stoi(pedaco);
		linhaProcessar >> pedaco; // pega o segundo
		segundo = std::stoi(pedaco);
		//std::cout << primeiro << " : " << segundo << std::endl;
		primeiro--;
		segundo--;
		vertices[primeiro].InserirAdjacente(segundo);
		vertices[segundo].InserirAdjacente(primeiro);
	}
	return true;
}

int retornaPossivel(int pos);

int main() {

	if (!inicializar())
		return -1;
	std::vector<int> trancados;
	bool continua = 1;
	int cor = 0;

	while (continua) {
		continua = 0;
		Cor corAux;
		cores.push_back(corAux);
		for (int i = 0; i < quantidade; i++) {
			if (vertices[i].getCor() == -1 && vertices[i].getStatus() == 0) {
				// Adiciona u a classe i 
				vertices[i].setCor(cor);
				cores[cor].itens.push_back(i);
				for (int j = 0; j < vertices[i].getQuantidadeAdjacentes(); j++) {
					if (vertices[vertices[i].getAdjacente(j)].getStatus() == 0 && vertices[vertices[i].getAdjacente(j)].getCor() == -1) {
						vertices[vertices[i].getAdjacente(j)].setStatus(1);
						trancados.push_back(vertices[i].getAdjacente(j));
						continua = 1;
					}
				}
			}
		}
		cor++;
		for (auto qqr : trancados) {
			vertices[qqr].setStatus(0);
		}
		trancados.clear();
	}

	/*for (int i = 0; i < quantidade; i++) {
		std::cout << "vertice: " << i << " -------------cor: " << vertices[i].getCor()
			<< " ----------------quantidade de Ligacoes: " << vertices[i].getQuantidadeAdjacentes() << std::endl;
	}*/

	for (int i = 0; i < cores.size(); i++) {
		std::cout << "cor: " << i << std::endl;
		for (int j = 0; j < cores[i].itens.size(); j++)
			std::cout << cores[i].itens[j] << std::endl;
	}

	// onde i irá iterar sobre as cores ( i = cor)
	// onde j irá iterar sobre os vertices que pertencem a aquela cor ( j = a vertice da cor i)
	bool trocou = true;
	for (int i = cores.size() - 1; i >= 0; i--) {
	//for (int i = 0; i < cores.size(); i++) {
		trocou = true;
		for (int j = 0; j < cores[i].itens.size(); j++) {
			int retorno = retornaPossivel(cores[i].itens[j]);
			if (retorno == -1) {
				for (int k = 0; k < j; k++) {
					vertices[cores[i].itens[k]].setCor(i);
				}
				trocou = false;
				break;
			}
			else {
				vertices[cores[i].itens[j]].setCor(retorno);
			}
		}
		if (trocou) {
			//l é os itens da cor i
			for (int l = 0; l < cores[i].itens.size(); l++) {
				cores[vertices[cores[i].itens[l]].getCor()].itens.push_back(cores[i].itens[l]);
			}
			cores[i].itens.clear();
		}
	}

	/*for (int i = 0; i < quantidade; i++) {
		std::cout << "vertice: " << i << " -------------cor: " << vertices[i].getCor()
			<< " ----------------quantidade de Ligacoes: " << vertices[i].getQuantidadeAdjacentes() << std::endl;
	}*/
	std::cout << " -------------------*----------------"<< std::endl;
	for (int i = 0; i < cores.size(); i++) {
		std::cout << "cor: " << i << std::endl;
		for (int j = 0; j < cores[i].itens.size(); j++)
			std::cout << cores[i].itens[j] << std::endl;
	}

	int contador = 0;
	for (int i = 0; i < cores.size(); i++) {
		std::cout << cores[i].itens.size() << std::endl;
		if (cores[i].itens.size() > 0)
			contador++;
	}
	std::cout << "quantidade final de cores: " << contador << std::endl;

	system("pause");
	return 0;
}

int retornaPossivel(int pos) {
	int j;

	for (int i = 0; i < cores.size(); i++) {
		if (vertices[pos].getCor() != i && cores[i].itens.size() != 0) {
			for (j = 0; j < vertices[pos].getQuantidadeAdjacentes(); j++) {
				if (vertices[vertices[pos].getAdjacente(j)].getCor() == i)
					break;
			}
			if (j == vertices[pos].getQuantidadeAdjacentes())
				return i;
		}
	}
	return -1;
}