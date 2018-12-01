

const size_t N = 3;
const size_t M = 80;
const char STOP_STRING[] = "*";
const char END_LINE[] = "\n";
// ������ malloc ��� ��������������
const size_t INITIALISATION_SIZE = 1;

// printOneDimArray, �������� ������������� ������
template<typename T> 
void printOneDimArray(const T arr, size_t values);
// printOneDimArrayWitnEndl, ������� ������������� ������ �� ��������������
template<typename T> 
void printOneDimArrayWitnEndl(const T arr, size_t values, size_t delimiter);
// printTwoDimArray, ��������� ������������ ������
template<typename T> 
void printTwoDimArray(const T arr, size_t rows, size_t columns);
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
// sortByBubble, ��������� ��������� ������ ���������� �� ������
void sortByBubble(char * arr[N], int rows);
// arrayExist, ��������� ������� �������� � �������
bool arrayExist(int *& arr, int num, int size);
// fillArrayThroughCin, ��������� ������ ����� ���������� �� stdinput
void fillArrayThroughCin(char arr[N][M], int rows, int columns);