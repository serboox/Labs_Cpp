
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

	// getBookCategory, ����� ��� ��������� ���������� ����� �� ����� �������� ���������
	std::string getBookCategory();
	// ����������� ����� getBookCategory ��� ��������� �������� �������� �� ����� ���������� �����
	BookCategoryEnum getBookCategory(std::string category);
	// print, ����� ������ ����� �� �����
	void print();
};

// fillBookFields, ������� ��� ���������� ����� ����� ����� stdin
void fillBookFields(BOOK &book);

// ������� ����� ���������� �� ��������� BOOK
class MyBook : public BOOK {
public:
	// ���������� ��� super ��� ��������� � ��������
	typedef BOOK super;

	// ��������� ����������� ������
	MyBook(std::string authorFirstName,
		std::string authorLastName,
		std::string bookTitle,
		short int bookYear,
		float bookPrice,
		BookCategoryEnum bookCategory);

	void print();
protected:
	// ��� ���������� ����� � �������
private:
	// ��� ��������� ����� � �������
};

// printOneDimArray, �������� � stdout ������������� ������
template<typename T>
void printOneDimArray(const T arr, size_t values);

// printTwoDimArray, �������� � stdout ������������� ������
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns);