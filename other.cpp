
#include <iostream>
#include "other.h"

int arraySum(int * arr, int n, int m)
{
	int sum = 0;
	for (int i = 0; i < n*m; i++) {
		sum += arr[i];
	}
	return sum;
}

void sortByChoice(int *&arr, int n, int m)
{
	for (size_t i = 0; i < (n*m) - 1; i++) {
		int intMax = arr[i], intIndex = i;
		for (int j = 1; (i + j) % m > 0; j++) {
			//std::cout << "i: " << i << " j: " << j << "| " << arr[i+j] << " < " << intMax << std::endl;
			if (arr[i + j] > intMax) {
				//std::cout << "i: " << i << " j: " << j << "| " << arr[i + j] << " > " << intMax << std::endl;
				intMax = arr[i + j];
				intIndex = i + j;
			}
		}
		if (i != intIndex) {
			int buff = arr[i];
			arr[i] = arr[intIndex];
			arr[intIndex] = buff;
		}
		//std::cout << std::endl;
	}
}

double * columnAverage(int * p, int n, int m)
{
	double *resArr = new double[n];
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < m; j++)
		{
			//std::cout << p[i*m + j] << " ";
			sum += p[i*m + j];
		}
		resArr[i] = sum / m;
		//std::cout << std::endl << "Row average: " << resArr[i] << std::endl;
	}
	return resArr;
}

void arrayAppend(int * &arr, int num, int &pos, int &size) {

	std::cout << "Positin: " << pos << std::endl;

	if (pos == 0) {
		arr[0] = num;
		pos++;
		return;
	}
	if (size < pos + 1) {
		size *= 2;
		arr = (int*)realloc(arr, size * sizeof(int));
	}
	arr[pos] = num;
}