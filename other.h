
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

// run запускает выбор команд
void run();

// Card структура книжной карточки
struct Card {
	std::vector<BOOK> bookVector;

	// Card конструктор, срабатывающий при инициализации экземпл€ра карты
	Card() {

		BOOK newBook;
		newBook.authorFirstName.append("—ергей");
		newBook.authorLastName.append("Ќиколаевич");
		newBook.bookTitle.append(" ак научитс€ кодить на с++ за 14 дней?");
		newBook.bookYear = 1990;
		newBook.bookPrice = 28;
		newBook.bookCategory = BOOK_CATEGORY_TRAVEL;

		this->bookVector.push_back(newBook);
	}

	// set добавл€ет новую книгу в карточку
	void set();

	// print печатает содержимое карточки на экран
	void print();
};

// alignCenter печатает содержимое €чейки табицы по центру
std::string alignCenter(const std::string s, const int w);
// alignCenter печатает содержимое €чейки табицы по правому краю
std::string alignRight(const std::string s, const int w);
// alignCenter печатает содержимое €чейки табицы с левого кра€
std::string alignLeft(const std::string s, const int w);