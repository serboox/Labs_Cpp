

const size_t N = 3;
const size_t M = 80;
const char STOP_STRING[] = "*";
const char END_LINE[] = "\n";

// printOneDimArray, �������� ������������� ������
template<typename T>
void printOneDimArray(const T arr, size_t rows);
// printOneDimArrayWitnEndl, ������� ������������� ������ �� ��������������
template<typename T>
void printOneDimArrayWitnEndl(const T arr, size_t rows, size_t delimiter);
// printTwoDimArray, ��������� ������������� ������
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns);
// printTwoDimArray, ��������� ������������� ������
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t * arrStrLen);
// arraySum, ���������� ��� �������� � ������� � ���������� ���������
int arraySum(int * arr, int n, int m);
// sortByChoice, ��������� �������� ������� �� ������
void sortByChoice(int *&p, int n, int m);
// columnAverage, ������� ������� �������������� ����� ���������� ������� 
// � ���������� �������� � ���� �������
double * columnAverage(int * p, int n, int m);
// arrayAppend, ��������� ���� �������� � ����� �������
void arrayAppend(int * &arr, int num, int &pos, int &size);
// sortByBubble, ��������� ��������� ������ ������������ ������ �� ����� ����� 
void sortByBubble(int * &arr, int size);
// sortByBubble, ��������� ��������� ������ �����
void sortByBubble(char * arr[N], int rows);
// sortByBubbleDynArr, ��������� ������� "������������ ��������" �
//������� ����������� ���� ������� �������
void sortByBubbleDynArr(char **& arr, int rows, size_t *&strLen);
// arrayExist, ��������� ������� �������� � �������
bool arrayExist(int *& arr, int num, int size);
// fillStaticArrayThroughCin, ��������� ������ ����� ���������� �� stdinput
void fillStaticArrayThroughCin(char arr[N][M], int rows, int columns);
// fillDynamicArrayThroughCin, ��������� ������ ����� ���������� �� stdinput
void fillDynamicArrayThroughCin(char **&arr, int rows, size_t *&strLen);