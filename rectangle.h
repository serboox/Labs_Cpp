#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

const std::string COLUMN_INDEX_TITLE = "Index";
const std::string COLUMN_WIDTH_TITLE = "������";
const std::string COLUMN_HEIGHT_TITLE = "������";
const std::string COLUMN_AREA_TITLE = "�������";

// Rectangle, ��������� �������������
// ���� � ������ �� ��������� ����� ����������� ������� public
struct Rectangle {

	float width; // 4 bytes
	float height; // 4 bytes
	// area ������������� ������������� area=width*height
	float area; // 4 bytes
	
	// *prevRectangle - ��������� �� ���������� �������������
	Rectangle *prevRectangle = NULL;
	// *nextRectangle - ��������� �� ��������� �������������
	Rectangle *nextRectangle = NULL;

	// fillBookFields, ������� ��������� ���� ��������������� ����� stdin
	void fillFromStdIn();
	// print, ����� ������ �������������� � stdout
	void print();
};

/* validateColumnTitle ���������� �������� ������������� �� ������ 
	�������� ����� ����� �� ������� */
bool validateColumnTitle(const std::string str);