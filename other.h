
template<typename T>
void printOneDimArray(const T arr, size_t rows);
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns);

// addInArray, ��������� �������� � ����� �������
void addInArray(int* &arr, size_t &index, size_t &arrSize, int num);
// sumWithRecursion, ����������� ������� ����������
// ����� ������ N ����������� �����
int sumWithRecursion(int startNum, int maxNum);
// VarArgs, ��������� ���������� ����� ����������
// ���� int � ������� �� ������ ����� �������� ���������� �
// �� ��������.
void VarArgs(int n, ...);
// addInArray ��������� ���������� ����� ����������
// ���� int � ������� �� ������ ����� �������� ���������� �
// �� ��������
void addInArrayEndless(int* &arr, size_t &index, size_t &arrSize, int count, ...);
// MyMin, ������� ����������� �������� � �������,
// ����� �������, ����� �� ����� ����� ���� ������������ ����� �� ����� ���������
int *MyMin(int* &arr, size_t arrSize);