
/*
Para iniciar digite 0 para usar o QUICK sort ou 1 para usar o MERGE sort.
Após escolhido o tipo de ordenação, escreva o nome do arquivo seguido da extensão do arquivo (Ex.: dados.txt),
que deverá sem encontrar no formato que contem apenas e números e somente um unico número em cada linha do arquivo
ex.: 1
4
3
2
-------------------------------------------
Arquivos contendo dados devem ser colocados na pasta "Data" que se encontra no diretório raiz do projeto.
Cada algoritmo se encontra separado em um arquivo de cabeçalho com o respectivo nome.
Os resultados são salvos na pasta "Dados" do diretório raiz em arquivos com o nome do algoritmo usado.
*/
#include "stdafx.h"
#include <time.h>

#include "QuickSorting.h"
#include "MergeSorting.h"

int main() {
	int tipo;
	std::string arquivoNome, aux; //String para conter strings temporarias auxiliares
	std::ifstream arquivoBase; //Objeto que contem o ponteiro para o arquivo de entrada
	std::ofstream results; //Objeto que contem o ponteiro para o arquivo de saida dos resultados
	std::vector<int> numeros;
	clock_t timeTotal = 0;//contador de clocks

	std::cout << "Digite o nome do arquivo com a lista dos alunos(sem a extensao): ";
	std::cin >> arquivoNome;
	arquivoNome.insert(0, "Dados/");//Colocando o endereço correto da pasta
	arquivoBase.open(arquivoNome.data(), std::fstream::in);

	//Testa se o arquivo foi aberto (verdadeiro caso exista)
	if (!arquivoBase.is_open()) {
		std::cout << "Arquivo inexistente!" << std::endl;
		system("pause");
		return 0;
	}
	std::cout << "Carregando arquivo!" << std::endl;
	while (!arquivoBase.eof()) {
		std::getline(arquivoBase, aux);
		if (!aux.empty()) {
			int numero = std::stoll(aux);
			numeros.push_back(numero);
		}
	}
	std::cout << "Digite o tipo de algoritmo a ser usado: 0- Quick , 1- Merge:  ";
	std::cin >> tipo;
	switch (tipo) {
	case 0:
		timeTotal = clock();
		QuickSort(numeros.data(), 0, numeros.size());
		timeTotal = clock() - timeTotal;
		results.open("Dados/resultadosQuick.txt", std::ofstream::out); // arquivo de saida dos vetores ordenados e dos dados da ordenação
		break;
	case 1:
		timeTotal = clock();
		MergeSorting(numeros.data(), 0, numeros.size());
		timeTotal = clock() - timeTotal;
		results.open("Dados/resultadosMerge.txt", std::ofstream::out); // arquivo de saida dos vetores ordenados e dos dados da ordenação
		break;
	default:
		std::cout << "Opção inválida!" << std::endl;
		break;
	}

	for (int i = 0; i < numeros.size(); i++) {
		std::cout << numeros[i] << std::endl;
	}
	std::cout << "Tempo total: " << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	results << "Tempo total: " << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	results << "Organização final:" << std::endl;
	for (int i = 0; i < numeros.size(); i++) {
		results << numeros.at(i) << std::endl;
	}
	system("pause");

	return 0;
	/*
	std::ofstream results("resultadosInsertion.txt", std::ofstream::out); // arquivo de saida dos vetores ordenados e dos dados da ordenação
	timeTotal = clock() - timeTotal;
	//Seção de escrita de resultados em arquivo
	results << "Tempo total: " << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	results << "Organização final:" << std::endl;
	for (int i = 0; i<targetList.size(); i++) {
	results << targetList.at(i) << std::endl;
	}
	*/
}
