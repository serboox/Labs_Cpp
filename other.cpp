
#include <iostream>
#include <stdarg.h>

void addInArray(int* &arr, size_t &index, size_t &arrSize, int num) {
	if (index == 0) {
		arr[index] = num;
		index++;
		return;
	}

	bool numberIsExist = false;
	for (size_t j = 0; j < index; j++) {
		if (arr[j] == num) {
			numberIsExist = true;
			std::cout << "This number is exist" << std::endl;
			break;
		}
	}
	if (numberIsExist) {
		return;
	}
	if (arrSize < index + 1) {
		//arrSize *= 2;
		arrSize++;
		arr = (int*)realloc(arr, arrSize * sizeof(int));
	}
	arr[index] = num;
	index++;
}

int sumWithRecursion(int startNum, int maxNum) {
	if (startNum == (maxNum - 1)) {
		return startNum + maxNum;
	}
	return startNum + sumWithRecursion(startNum + 1, maxNum);
}

void VarArgs(int n, ...)
{
	int *p = &n, num = 0, count = 0;
	std::cout << "Received numbers: [";
	while (*p) {
		num = (*p);
		p++;
		count++;
		std::cout << num << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Count numbers: " << count << std::endl;
}

void addInArrayEndless(int* &arr, size_t &index, size_t &arrSize, int count, ...)
{
	if (count <= 0) return;
	int num = 0;
	va_list argptr;
	va_start(argptr, count); // инициализация argptr
	while (count) {
		--count;
		// получаем следующее значение в последовательности
		num = va_arg(argptr, int);

		std::cout << "Receive number: '" << num << "'" << std::endl;
		if (index == 0) {
			arr[index] = num;
			index++;
			continue;
		}

		bool numberIsExist = false;
		for (size_t j = 0; j < index; j++) {
			if (arr[j] == num) {
				numberIsExist = true;
				std::cout << "Number " << num << " is exist" << std::endl;
				break;
			}
		}
		if (numberIsExist) {
			continue;
		}
		if (arrSize < index + 1) {
			//arrSize *= 2;
			arrSize++;
			arr = (int*)realloc(arr, arrSize * sizeof(int));
		}
		arr[index] = num;
		index++;
	}
	// вызвать функцию va_end(), что гарантирует правильное восстановление стека
	va_end(argptr);
}

int *MyMin(int* &arr, size_t arrSize) {
	int indexMinValue = 0;
	for (size_t i = 0; i < arrSize; i++) {
		if (arr[indexMinValue] > arr[i]) {
			indexMinValue = i;
		}
	}
	std::cout << "Min value: " << arr[indexMinValue] << std::endl;
	return &arr[indexMinValue];
}