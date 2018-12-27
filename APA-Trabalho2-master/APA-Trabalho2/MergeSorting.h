#pragma once

void MergeSorting(int *valor, int esquerda, int direita) {
	int meio = (esquerda + direita) / 2;
	int x = esquerda, y = meio, aux = 0;
	int *auxCopy = new int[direita - esquerda];
	if (direita - esquerda > 1) {
		for (int i = esquerda, j = 0;  i < direita; i++) {
			auxCopy[j++] = valor[i];
		}
		MergeSorting(valor, esquerda, meio);
		MergeSorting(valor, meio, direita);
		while (x < meio && y < direita) {
			if (valor[x] < valor[y]) 
				auxCopy[aux++] = valor[x++];
			else
				auxCopy[aux++] = valor[y++];
		}
		while (x<meio) auxCopy[aux++] = valor[x++];
		while (y<direita) auxCopy[aux++] = valor[y++];

		for (int i = esquerda, j = 0; i < direita; i++) {
			valor[i] = auxCopy[j++];
		}

	}
}
