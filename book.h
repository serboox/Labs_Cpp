
#include <iostream>

// ����������� ��������� ��������� ��������� � ����� 
const char
BOOK_CATEGORY_ERROR_STRING[] = "",
BOOK_CATEGORY_HIST_STRING[] = "hist",
BOOK_CATEGORY_MIDEVAL_STRING[] = "mideval",
BOOK_CATEGORY_DETECT_STRING[] = "detect",
BOOK_CATEGORY_ACTION_STRING[] = "action",
BOOK_CATEGORY_TRAVEL_STRING[] = "travel";

// ��������� enum � ������������� ��������� �����
enum BookCategoryEnum {
	BOOK_CATEGORY_ERROR = -1, // ��� ��� ������
	BOOK_CATEGORY_HIST, // ������������ �����
	BOOK_CATEGORY_MIDEVAL, // ���������� �������� � ������� �����
	BOOK_CATEGORY_DETECT, //  ���������, ��������
	BOOK_CATEGORY_ACTION, // ������, ����� � �����
	BOOK_CATEGORY_TRAVEL, // �����������, �����������
};

const std::string COLUMN_INDEX_TITLE = "Index";
const std::string COLUMN_AUTHOR_FIRST_NAME_TITLE = "���";
const std::string COLUMN_AUTHOR_LAST_NAME_TITLE = "�������";
const std::string COLUMN_BOOK_TITLE_TITLE = "���������";
const std::string COLUMN_BOOK_YEAR_TITLE = "���";
const std::string COLUMN_BOOK_PRICE_TITLE = "����";
const std::string COLUMN_BOOK_CATEGORY_TITLE = "���������";

// BOOK, ��������� �����
// ���� � ������ �� ��������� ����� ����������� ������� public
struct BOOK {

	std::string authorFirstName; // 28 bytes
	std::string authorLastName; // 28 bytes
	std::string bookTitle; // 28 bytes
	short int bookYear; // 2 bytes
	/* 2 padding byte */
	float bookPrice; // 4 bytes
	BookCategoryEnum bookCategory; // 4 bytes

	// fillBookFields, ������� ��������� ���� ����� ����� stdin
	void fillFromStdIn();
	// getBookCategory, ����� ��� ��������� ���������� ����� �� ����� �������� ���������
	std::string getBookCategory();
	// ����������� ����� getBookCategory ��� ��������� �������� �������� �� ����� ���������� �����
	BookCategoryEnum getBookCategory(std::string category);
	// print, ����� ������ ����� �� �����
	void print();
};

/* validateColumnTitle ���������� �������� ������������� �� ������ 
	�������� ����� ����� �� ������� */
bool validateColumnTitle(const std::string str);
// semicolonToSpace ��� ����� ';' �� �������
void semicolonToSpace(std::string &text);
// printOneDimArray �������� � stdout ������������� ������
template<typename T>
void printOneDimArray(const T arr, size_t values);
// printTwoDimArray �������� � stdout ������������� ������
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns);