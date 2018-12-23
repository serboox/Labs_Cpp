
#include <cstdio>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <utility>
#include <map>

// Определяем константы используемые в качестве разделителей при определении пути к файлу
#if defined(_WIN16) | defined(_WIN32) | defined(_WIN64)
#define SEPERATOR "\\"
#else
#define SEPERATOR "/"
#endif

// Перечисляем констаны для комманд используемых в консоли
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

// DEFAULT_PATH_TO_FILE константа хранящая путь для сохраняемого/считываемого файла по умолчанию
const std::string DEFAULT_PATH_TO_FILE = "C:\\Users\\Public\\card.txt";
// SORT_ASC сотировака в порядке убывания
const std::string SORT_ASC = "ASC";
// SORT_DESC сортировака в порядке возрастания
const std::string SORT_DESC = "DESC";

// Card структура книжной картотеки
struct Card {
	// bookVector содержит список книг (структур BOOK)
	std::vector<BOOK> bookVector;

	// sortMap содержит данные для сортировки map[название поля]isDesc
	std::map<std::string, bool> sortMap;
	// sortVector хранит имена колонок в порядке котором следует производить сортировку
	std::vector<std::string> sortVector;

	// Card конструктор, срабатывающий при инициализации экземпляра карты
	Card() {
		// Определяем книгу по умолчанию
		BOOK newBook;
		newBook.authorFirstName.append("Вита");
		newBook.authorLastName.append("Сергеевна");
		newBook.bookTitle.append("Как научится кодить на с++ за 14 дней?");
		newBook.bookYear = 1999;
		newBook.bookPrice = 28;
		newBook.bookCategory = BOOK_CATEGORY_TRAVEL;
		this->bookVector.push_back(newBook);
	}

	// print печатает содержимое картотеки в консоль
	void print();
	// print печатает содержимое карты для сортировки в консоль
	void printSortMap();
	// print печатает содержимое вектора для сортировки в консоль
	void printSortVector();
	// add добавляет новую книгу в картотеку
	void add();
	// deleteCards удаляет одну или несколько книг из картотеки
	void deleteCards();
	// saveToFile сохраняет данные в файл
	void saveToFile();
	// readFromFile считывает данные из файла
	void readFromFile();
	// sort сортирует книги в картотеке в определенной последовательности
	void initSort();
	/*
		parseSortString преобразует строку(std:cin) в данные необходимые для сортировки,
		заполняет поля sortMap и sortVector, возвращает false в случае ошибки
	 */
	bool parseSortString(std::string str);
	// sortBook сортирует имеющиеся в картатеке книги
	void sortBook();
	/*
		cmpBookRecursive рекурсивно проходит по sortVector проверяя какое из значений больше
		1 если firstVectorIndex > secondVectorIndex
		0 если firstVectorIndex == secondVectorIndex
		-1 если firstVectorIndex < secondVectorIndex
	*/
	std::pair<int, bool> cmpBookRecursive(
		const size_t firstVectorIndex, 
		const size_t secondVectorIndex, 
		const size_t sortIndex);
};

// run запускает выбор команд
void run();
// strSpaceWrap добавляет пробел в начало и конец строки
std::string strSpaceWrap(std::string str);
// alignCenter печатает содержимое ячейки табицы по центру
std::string alignCenter(const std::string s, const int w);
// alignCenter печатает содержимое ячейки табицы по правому краю
std::string alignRight(const std::string s, const int w);
// alignCenter печатает содержимое ячейки табицы с левого края
std::string alignLeft(const std::string s, const int w);
// split разбивает строку по разделителю
std::vector<std::string> split(const std::string& s, const char sep);
