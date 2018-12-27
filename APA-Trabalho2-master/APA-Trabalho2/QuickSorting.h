#pragma once
void QuickSort(int *valor, int esquerda, int direita) {
	int i, j, x, y;
	i = esquerda;
	j = direita;
	x = valor[(esquerda + direita) / 2];

	while (i <= j) {
		while (valor[i] < x && i < direita) i++;
		while (valor[j] > x && j >= esquerda) j--;
		if (i <= j) {
			y = valor[i];
			valor[i] = valor[j];
			valor[j] = y;
			i++;
			j--;
		}
	}
	if (j > esquerda) QuickSort(valor, esquerda, j);
	if (i < direita) QuickSort(valor, i, direita);
}