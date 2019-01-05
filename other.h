// � ���� ��������� � �������� ��� ���������, ����������,���������,������ � �������.
#include <cstdio> // ����������� ����������
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <utility>
#include <map>

#include "rectangle.h"

// ����������� �������� ��� ������� ������������ � �������
const char
	COMMAND_PRINT[] = "print",
	COMMAND_ADD[] = "add",
	COMMAND_DELETE[] = "delete",
	COMMAND_SAVE[] = "save",
	COMMAND_LOAD[] = "load",
	COMMAND_SEARCH[] = "search",
	COMMAND_SORT[] = "sort",
	COMMAND_HELP[] = "help",
	COMMAND_EXIT[] = "exit",
	COMMAND_ENDL[] = "\n";

// DEFAULT_PATH_TO_FILE ��������� �������� ���� ��� ������������/������������ ����� �� ���������
const std::string DEFAULT_PATH_TO_FILE = "C:\\Users\\Public\\rectangleSet.txt";
// SORT_ASC ���������� � ������� �����������
const std::string SORT_ASC = "ASC";
// SORT_DESC ����������� � �������  ��������
const std::string SORT_DESC = "DESC";

// RectangleSet ��������� ������ ���������������
struct RectangleSet
{

	// *firstRectangle - ��������� �� ������ ������������� � ������������� ������
	Rectangle *firstRectangle = nullptr;
	// *lastRectangle - ��������� �� ��������� ������������� � ������������� ������
	Rectangle *lastRectangle = nullptr;
	// size - ������ ���������� ��������������� � ������
	size_t size = 0;

	// recVector �������� ������ � ������������� �������� ��������������� (�������� Rectangle),
	std::vector<Rectangle> recVector;
	// sortMap �������� ������ ��� ���������� map[�������� ����]isDesc
	std::map<std::string, bool> sortMap;
	// sortVector ������ ����� ������� � ������� ������� ������� ����������� ����������
	std::vector<std::string> sortVector;

	// RectangleSet �����������, ������������� ��� ������������� ���������
	RectangleSet()
	{
		// ���������� ������������� �� ���������
		/*Rectangle *newRectangle;
		newRectangle = (struct Rectangle*)malloc(sizeof(struct Rectangle));
		newRectangle->width = 2.14;
		newRectangle->height = 4.71;
		newRectangle->area = newRectangle->width * newRectangle->height;
		newRectangle->prevRectangle = nullptr;
		newRectangle->nextRectangle = nullptr;
		
		++this->size;
		this->firstRectangle = newRectangle;
		this->lastRectangle = newRectangle;

		Rectangle *newRectangle2;
		newRectangle2 = (struct Rectangle*)malloc(sizeof(struct Rectangle));
		newRectangle2->width = 7.14;
		newRectangle2->height = 9.71;
		newRectangle2->area = newRectangle2->width * newRectangle2->height;
		
		newRectangle2->nextRectangle = nullptr;
		newRectangle2->prevRectangle = this->lastRectangle;
		this->firstRectangle->nextRectangle = newRectangle2;
		this->lastRectangle = newRectangle2;
		++this->size;*/
	}

	// RectangleSet ����������, ������������� ��� �������� ��������� �� ������ ���������
	~RectangleSet()
	{
		this->clear();
	}

	// print �������� ���������� ������ �������������� � �������
	void print();
	/* print �������� ���������� �������������� ������� �������������� � ������� */
	void printRecVector();
	// print �������� ���������� ����� ��� ���������� � �������
	void printSortMap();
	// print �������� ���������� ������� ��� ���������� � �������
	void printSortVector();
	// add ��������� ����� ������������� � �����
	void add();
	// deleteCards ������� ���� ��� ��������� ��������������� �� ������
	void deleteCards();
	// saveToFile ��������� ������ � ����
	void saveToFile();
	// readFromFile ��������� ������ �� �����
	void readFromFile();
	/* 
		search ������� ���� ��� ��������� ��������������� �� ������ �������
		������� ������������� ���������� (stdin) �����
	*/
	void search();
	// searchFromIndex ������� ������������� �� �������
	Rectangle *searchFromIndex(size_t index);

	// clear ������� ������������� �� �������
	void clear();
	// sort ��������� �������������� � ������������ �������
	void initSort();
	// fillRecVectorFromDoublyLinkedList ��������� ������ recVector �� ������ �������������� ������
	void fillRecVectorFromDoublyLinkedList();
	// fillDoublyLinkedListFromRecVector ��������� ������������� ������ �� ������� recVector
	void fillDoublyLinkedListFromRecVector();
	/*
		parseSortString ����������� ������(std:cin) � ������ ����������� ��� ����������,
		��������� ���� sortMap � sortVector, ���������� false � ������ ������
	 */
	bool parseSortString(std::string str);
	// sortBook ��������� ��������� � ��������� �����
	void sortBook();
	/*
		cmpRectangleRecursive ���������� �������� �� sortVector �������� ����� �� �������� ������
		1 ���� firstVectorIndex > secondVectorIndex
		0 ���� firstVectorIndex == secondVectorIndex
		-1 ���� firstVectorIndex < secondVectorIndex
	*/
	std::pair<int, bool> cmpRectangleRecursive(
		const size_t firstVectorIndex,
		const size_t secondVectorIndex,
		const size_t sortIndex);
};

// run ��������� ����� ������
void run();
// strSpaceWrap ��������� ������ � ������ � ����� ������
std::string strSpaceWrap(std::string str);
// alignCenter �������� ���������� ������ ������ �� ������
std::string alignCenter(const std::string s, const int w);
// alignCenter �������� ���������� ������ ������ �� ������� ����
std::string alignRight(const std::string s, const int w);
// alignCenter �������� ���������� ������ ������ � ������ ����
std::string alignLeft(const std::string s, const int w);
// split ��������� ������ �� �����������
std::vector<std::string> split(const std::string &s, const char sep);
