
#include <cstdio>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>

#if defined(_WIN16) | defined(_WIN32) | defined(_WIN64)
#define SEPERATOR "\\"
#else
#define SEPERATOR "/"
#endif

const char
COMMAND_PRINT[] = "print",
COMMAND_ADD[] = "add",
COMMAND_DELETE[] = "delete",
COMMAND_SAVE[] = "save",
COMMAND_LOAD[] = "load",
COMMAND_HELP[] = "help",
COMMAND_EXIT[] = "exit",
COMMAND_ENDL[] = "\n";

// run запускает выбор команд
void run();

// Card структура книжной картотеки
struct Card {
	std::vector<BOOK> bookVector;

	// Card конструктор, срабатывающий при инициализации экземпл€ра карты
	Card() {

		BOOK newBook;
		newBook.authorFirstName.append("¬ита");
		newBook.authorLastName.append("—ергеевна");
		newBook.bookTitle.append(" ак научитс€ кодить на с++ за 14 дней?");
		newBook.bookYear = 1999;
		newBook.bookPrice = 28;
		newBook.bookCategory = BOOK_CATEGORY_TRAVEL;

		this->bookVector.push_back(newBook);
	}
	
	// print печатает содержимое картотеки на экран
	void print();

	// add добавл€ет новую книгу в картотеку
	void add();

	// deleteCards удал€ет одну или несколько книг из картотеки
	void deleteCards();

	// saveToFile сохран€ет данные в файл
	void saveToFile();

	// readFromFile считывает данные из файла
	void readFromFile();
};

// alignCenter печатает содержимое €чейки табицы по центру
std::string alignCenter(const std::string s, const int w);
// alignCenter печатает содержимое €чейки табицы по правому краю
std::string alignRight(const std::string s, const int w);
// alignCenter печатает содержимое €чейки табицы с левого кра€
std::string alignLeft(const std::string s, const int w);