
template<typename T>
void printOneDimArray(const T arr, size_t rows);
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns);

// addInArray, добавляет значение в конец массива
void addInArray(int* &arr, size_t &index, size_t &arrSize, int num);
// sumWithRecursion, рекурсивная функцию вычисления
// суммы первых N натуральных чисел
int sumWithRecursion(int startNum, int maxNum);
// VarArgs, принимает переменное число аргументов
// типа int и выводит на печать число принятых параметров и
// их значения.
void VarArgs(int n, ...);
// addInArray принимает переменное число аргументов
// типа int и выводит на печать число принятых параметров и
// их значения
void addInArrayEndless(int* &arr, size_t &index, size_t &arrSize, int count, ...);
// MyMin, находит минимальное значение в массиве,
// таким образом, чтобы ее вызов можно было использовать слева от знака равенства
int *MyMin(int* &arr, size_t arrSize);