
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

void arrayAppend(int * &arr, int num, int &pos, int &size)
{
	if (size < pos + 1) {
		size *= 2;
		arr = (int*)realloc(arr, size * sizeof(int));
	}
	arr[pos] = num;
}

void sortByBubble(int * &arr, int size)
{
	bool notSorted = true;
	while (notSorted) {
		notSorted = false;
		for (size_t j = 0; j < size; j++) {
			if (arr[j] > arr[j + 1]) {
				arr[j] ^= arr[j + 1] ^= arr[j] ^= arr[j + 1];
				notSorted = true;
			}
		}
	}
}

void sortByBubble(char * arr[N], int rows)
{
	//Повторяем, пок не отсортируем массив.
	bool notSorted = true;
	while (notSorted) {
		//Предполагаем, что не правильных пар нет.
		notSorted = false;
		for (size_t i = 0; i < (rows - 1); i++) {
			std::cout << "CMP: " << strcmp(arr[i], arr[i + 1]) << std::endl;
			if (strcmp(arr[i], arr[i + 1]) > 0) {
				// Меняем их местами
				char *temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;

				// Масив еще не отсортирован.
				notSorted = true;
			}
		}
	}
}

bool arrayExist(int *& arr, int num, int size)
{
	for (size_t j = 0; j < size; j++) {
		if (arr[j] == num) {
			return true;
		}
	}
	return false;
}

void fillArrayThroughCin(char arr[N][M], int rows, int columns)
{	
	std::cout << "N: " << rows << " M: " << columns << std::endl;

	//Цикл ввода строк:
	for (size_t nIndex = 0; nIndex < rows; nIndex++) {
		//а) выведите приглашение для ввода		
		std::cout << "Please enter string " << nIndex + 1 << " (len<=" << columns << "): " << std::endl;
		std::cout << "=> ";
		//б) пока не введена строка STOP_STRING или не заполнен весь массив
		size_t mIndex = 0;
		char strBuff[] = { " " };
		while (strcmp(strBuff, STOP_STRING) && mIndex < columns) {
			//ввод строки в массив cBuffer:
			std::cin.read(strBuff, 1);
			//если в из потока вывода приходит знак переноса строки переходим к следующей итерации
			if (!strcmp(strBuff, END_LINE)) {
				continue;
			}
			//если введена строка - признак окончания, то выйти из цикла
			if (!strcmp(strBuff, STOP_STRING)) {
				break;
			}
			std::cout << "(N:" << nIndex + 1 << "|M:" << mIndex + 1 << "): " << strBuff << std::endl;
			arr[nIndex][mIndex] = strBuff[0];
			mIndex++;
		}
	}
}