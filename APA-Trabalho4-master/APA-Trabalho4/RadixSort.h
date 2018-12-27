#pragma once

void RadixSorting(int* vet, int tamanho) {
	int *ordenado = new int[tamanho];
	int *contador;
	int maior = vet[0], exp = 1;
	for (int i = 0; i < tamanho; i++) {
		if (maior < vet[i]) {
			maior = vet[i];
		}
	}
	while ( maior/ exp > 0) {
		contador = new int[10];
		for (int i = 0; i < tamanho; i++)
			contador[i] = 0;

		for (int i = 0; i < tamanho; i++)
			contador[(vet[i] / exp) % 10]++;

		for (int i = 1; i < tamanho; i++)
			contador[i] += contador[i - 1];

		for (int i = tamanho - 1; i >= 0; i--)
			ordenado[--contador[(vet[i] / exp) % 10]] = vet[i];

		for (int i = 0; i < tamanho; i++)
			vet[i] = ordenado[i];
		exp *= 10;
	}
}
