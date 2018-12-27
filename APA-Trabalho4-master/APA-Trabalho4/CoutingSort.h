#pragma once

void CountingSorting(int* vet, int tamanho) {
	int *ordenado = new int[tamanho];
	int *contador;
	int tamCounter;
	int maior = vet[0], menor = vet[0];
	for (int i = 0; i < tamanho; i++) {
		if (maior < vet[i]) {
			maior = vet[i];
		}
		else if (menor > vet[i]) {
			menor = vet[i];
		}
	}
	tamCounter = maior - menor + 1;
	contador = new int[tamCounter];

	for (int i = 0; i < tamCounter; i++) 
		contador[i] = 0;

	for (int i = 0; i < tamanho; i++) 
		contador[vet[i] - menor]++;

	for (int i = 1; i < tamCounter; i++) 
		contador[i]+= contador[i-1];

	for (int i = tamanho - 1; i >= 0; i--)
		ordenado[--contador[vet[i] - menor]] = vet[i];

	for (int i = 0; i < tamanho; i++)
		vet[i] = ordenado[i];
}