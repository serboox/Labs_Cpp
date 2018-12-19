
#include <cstdio>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

// ���������� ��������� ������������ � �������� ������������ ��� ����������� ���� � �����
#if defined(_WIN16) | defined(_WIN32) | defined(_WIN64)
#define SEPERATOR "\\"
#else
#define SEPERATOR "/"
#endif

// ����������� �������� ��� ������� ������������ � �������
const char
COMMAND_PRINT[] = "print",
COMMAND_ADD[] = "add",
COMMAND_DELETE[] = "delete",
COMMAND_SAVE[] = "save",
COMMAND_LOAD[] = "load",
COMMAND_HELP[] = "help",
COMMAND_SORT[] = "sort",
COMMAND_EXIT[] = "exit",
COMMAND_ENDL[] = "\n";

// DEFAULT_PATH_TO_FILE ��������� �������� ���� ��� ������������/������������ ����� �� ���������
const std::string DEFAULT_PATH_TO_FILE = "C:\\Users\\Public\\card.txt";

// run ��������� ����� ������
void run();

// Card ��������� ������� ���������
struct Card {
	std::vector<BOOK> bookVector;

	// Card �����������, ������������� ��� ������������� ���������� �����
	Card() {
		// ���������� ����� �� ���������
		BOOK newBook;
		newBook.authorFirstName.append("����");
		newBook.authorLastName.append("���������");
		newBook.bookTitle.append("��� �������� ������ �� �++ �� 14 ����?");
		newBook.bookYear = 1999;
		newBook.bookPrice = 28;
		newBook.bookCategory = BOOK_CATEGORY_TRAVEL;
		this->bookVector.push_back(newBook);
	}
	
	// print �������� ���������� ��������� �� �����
	void print();
	// add ��������� ����� ����� � ���������
	void add();
	// deleteCards ������� ���� ��� ��������� ���� �� ���������
	void deleteCards();
	// saveToFile ��������� ������ � ����
	void saveToFile();
	// readFromFile ��������� ������ �� �����
	void readFromFile();
	// sort ��������� ����� � ��������� � ������������ ������������������
	void sort();
};

// alignCenter �������� ���������� ������ ������ �� ������
std::string alignCenter(const std::string s, const int w);
// alignCenter �������� ���������� ������ ������ �� ������� ����
std::string alignRight(const std::string s, const int w);
// alignCenter �������� ���������� ������ ������ � ������ ����
std::string alignLeft(const std::string s, const int w);

// split ��������� ������ �� �����������
std::vector<std::string> split(const std::string& s, const char sep);