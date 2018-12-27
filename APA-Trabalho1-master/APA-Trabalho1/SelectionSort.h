#pragma once
void SelectionSort(long long int *targetList, int size) {
	for (int i = 0; i <size; i++) {
		int menor = i;
		for (int j = i; j < size; j++) {
			if (targetList[menor] > targetList[j])
				menor = j;
		}
		int aux = targetList[i];
		targetList[i] = targetList[menor];
		targetList[menor] = aux;
	}
}