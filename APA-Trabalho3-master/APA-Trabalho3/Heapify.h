#pragma once

void MaxHeapify(int *vet, int pai, int fim) {
	int aux = vet[pai];
	int filho = (pai * 2) + 1;
	while (filho<=fim) {
		if (filho < fim) {
			if (vet[filho] < vet[filho + 1]) {
				filho++;
			}
		}
		if (aux < vet[filho]) {
			vet[pai] = vet[filho];
			pai = filho;
			filho = (pai * 2) + 1;
		}
		else {
			filho = fim + 1;
		}
	}
	vet[pai] = aux;
	
}

void MinHeapify(int *vet, int pai, int fim) {
	int aux = vet[pai];
	int filho = (pai * 2) + 1;
	while (filho <= fim) {
		if (filho < fim) {
			if (vet[filho] > vet[filho + 1]) {
				filho++;
			}
		}
		if (aux > vet[filho]) {
			vet[pai] = vet[filho];
			pai = filho;
			filho = (pai * 2) + 1;
		}
		else {
			filho = fim + 1;
		}
	}
	vet[pai] = aux;
}