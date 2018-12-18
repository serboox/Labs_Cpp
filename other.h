
#include <cstdio>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

const char
COMMAND_PRINT[] = "print",
COMMAND_SET[] = "set",
COMMAND_DELETE[] = "delete",
COMMAND_WRITE[] = "write",
COMMAND_READ[] = "read",
COMMAND_HELP[] = "help",
COMMAND_EXIT[] = "exit",
COMMAND_ENDL[] = "\n";

// run ��������� ����� ������
void run();

// Card ��������� ������� ��������
struct Card {
	std::vector<BOOK> bookVector;

	// Card �����������, ������������� ��� ������������� ���������� �����
	Card() {

		BOOK newBook;
		newBook.authorFirstName.append("������");
		newBook.authorLastName.append("����������");
		newBook.bookTitle.append("��� �������� ������ �� �++ �� 14 ����?");
		newBook.bookYear = 1990;
		newBook.bookPrice = 28;
		newBook.bookCategory = BOOK_CATEGORY_TRAVEL;

		this->bookVector.push_back(newBook);
	}

	// set ��������� ����� ����� � ��������
	void set();

	// print �������� ���������� �������� �� �����
	void print();
};

// alignCenter �������� ���������� ������ ������ �� ������
std::string alignCenter(const std::string s, const int w);
// alignCenter �������� ���������� ������ ������ �� ������� ����
std::string alignRight(const std::string s, const int w);
// alignCenter �������� ���������� ������ ������ � ������ ����
std::string alignLeft(const std::string s, const int w);