#pragma once

void InsertionSorting(long long int *targetList, int size) {
	for (int i = 0; i < size - 1; i++) {
		int aux = i;
		for (int j = i + 1; j<size; j++) {
			if (targetList[j]<targetList[aux]) {
				aux = j;
			}
		}
		int troca = targetList[aux];
		targetList[aux] = targetList[i];
		targetList[i] = troca;
	}
}
