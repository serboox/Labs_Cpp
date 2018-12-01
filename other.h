

const size_t N = 3;
const size_t M = 80;
const char STOP_STRING[] = "*";
const char END_LINE[] = "\n";
// размер malloc при инициализациии
const size_t INITIALISATION_SIZE = 1;

// printOneDimArray, печатает одноуровневый массив
template<typename T> 
void printOneDimArray(const T arr, size_t values);
// printOneDimArrayWitnEndl, печатет даузуровневый массив из одноуровневого
template<typename T> 
void printOneDimArrayWitnEndl(const T arr, size_t values, size_t delimiter);
// printTwoDimArray, печататет дузуровневый массив
template<typename T> 
void printTwoDimArray(const T arr, size_t rows, size_t columns);
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
// sortByBubble, сортирует пузырькои массив указателей на строки
void sortByBubble(char * arr[N], int rows);
// arrayExist, проверяет наличие значения в массиве
bool arrayExist(int *& arr, int num, int size);
// fillArrayThroughCin, заполняет массив строк значениями из stdinput
void fillArrayThroughCin(char arr[N][M], int rows, int columns);