

const size_t N = 3;
const size_t M = 80;
const char STOP_STRING[] = "*";
const char END_LINE[] = "\n";

// printOneDimArray, печатает одноуровневый массив
template<typename T>
void printOneDimArray(const T arr, size_t rows);
// printOneDimArrayWitnEndl, печатет двухуровневый массив из одноуровневого
template<typename T>
void printOneDimArrayWitnEndl(const T arr, size_t rows, size_t delimiter);
// printTwoDimArray, печататет двухуровневый массив
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns);
// printTwoDimArray, печататет двухуровневый массив
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t * arrStrLen);
// arraySum, складываем все значения в массиве и возвращает результат
int arraySum(int * arr, int n, int m);
// sortByChoice, сортирует значения массива по выбору
void sortByChoice(int *&p, int n, int m);
// columnAverage, находит среднее арифметическое строк двумерного массива 
// и возвращает значения в виде массива
double * columnAverage(int * p, int n, int m);
// arrayAppend, добавляет одно значение в конец массива
void arrayAppend(int * &arr, int num, int &pos, int &size);
// sortByBubble, сортирует пузырьком массив динамический массив из целых чисел 
void sortByBubble(int * &arr, int size);
// sortByBubble, сортирует пузырьком массив строк
void sortByBubble(char * arr[N], int rows);
// sortByBubbleDynArr, сортирует методом "всплывающего пузырька" в
//порядке возрастания кода первого символа
void sortByBubbleDynArr(char **& arr, int rows, size_t *&strLen);
// arrayExist, проверяет наличие значения в массиве
bool arrayExist(int *& arr, int num, int size);
// fillStaticArrayThroughCin, заполняет массив строк значениями из stdinput
void fillStaticArrayThroughCin(char arr[N][M], int rows, int columns);
// fillDynamicArrayThroughCin, заполняет массив строк значениями из stdinput
void fillDynamicArrayThroughCin(char **&arr, int rows, size_t *&strLen);