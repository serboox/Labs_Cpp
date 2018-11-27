
#include <iostream>
#include <string>
#include "cmath"
#include "other.h"

#define      stop __asm nop

int main() {
	std::cout << "Hello World" << std::endl;
	stop;
	return 0;
}

template<typename T>
void printOneDimArray(const T arr, size_t values) {
	std::cout << "/ -----" << " Print one-dimensional Array with";
	std::cout << " Values: " << values << std::endl << "[";
	for (size_t i = 0; i < values; i++) {
		std::cout << arr[i];
		if (i != (values - 1)) {
			std::cout << " ";
		}
	}
	std::cout << "]" << std::endl;
	std::cout << "/ -----" << std::endl;
}

template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns) {
	std::cout << "/ -----" << " Print two-dimensional Array with";
	std::cout << " Rows: " << rows << " Columns: " << columns << std::endl;
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			if (j == 0) {
				std::cout << "/ ";
			}
			std::cout << arr[i][j];
			if (j == (columns - 1)) {
				std::cout << " /" << std::endl;
			}
		}
	}
	std::cout << "/ -----" << std::endl;
}