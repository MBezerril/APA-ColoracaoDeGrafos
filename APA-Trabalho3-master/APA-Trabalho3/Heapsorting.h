#pragma once

#include "Heapify.h"

void HeapSorting(int* vet, int tamanho) {
	int i, aux;
	for (i = (tamanho - 1) / 2; i >= 0; i--) {
		MaxHeapify(vet, i, tamanho - 1);
	}
	for (i = tamanho - 1; i >= 1; i--) {
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		MaxHeapify(vet, 0, i - 1);
	}
}
