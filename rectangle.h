#include <iostream> // ������������ ���� ����������� ���������� ��� ������ � ������/�������
#include <string>   // ������������ ���� ����������� ���������� ��� ������ �� ��������
#include <stdlib.h> // ������������ ���� ����������� ����������

#if !defined(WIN32) && !defined(_WIN32) && !defined(_WIN64)
#include <unistd.h> // ���������� ��� ������� sleep() ������������ � Unix
#endif

// ����������� ��������� ��������� ��� ���������� �������� �������
// ������� ������������ ��� ������ ������� � ������� � ��� ����� �������� ������� ��� ����������
const std::string COLUMN_INDEX_TITLE = "Index";
const std::string COLUMN_WIDTH_TITLE = "������";
const std::string COLUMN_HEIGHT_TITLE = "������";
const std::string COLUMN_AREA_TITLE = "�������";

// Rectangle, ��������� �������������
// ���� � ������ �� ��������� ����� ����������� ������� public
struct Rectangle
{

	// width ������ ��������������
	float width;  // 4 bytes
				  // height ������ ��������������
	float height; // 4 bytes
	// area ������� ��������������, ������������� ������������� area=width*height
	float area; // 4 bytes

	// *prevRectangle - ��������� �� ���������� �������������
	Rectangle *prevRectangle = nullptr;
	// *nextRectangle - ��������� �� ��������� �������������
	Rectangle *nextRectangle = nullptr;

	// fillBookFields ����� ��������� ���� ��������������� ����� stdin
	void fillFromStdIn();
	// print ����� ������ �������������� � stdout
	void print();
};

/* validateColumnTitle ���������� �������� ������������� �� ������ 
	�������� ����� ����� �� ������� */
bool validateColumnTitle(const std::string str);