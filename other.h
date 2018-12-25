
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

#include "rectangle.h"

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
COMMAND_SEARCH[] = "search",
COMMAND_SORT[] = "sort",
COMMAND_HELP[] = "help",
COMMAND_EXIT[] = "exit",
COMMAND_ENDL[] = "\n";

// DEFAULT_PATH_TO_FILE константа хранящая путь для сохраняемого/считываемого файла по умолчанию
const std::string DEFAULT_PATH_TO_FILE = "C:\\Users\\Public\\rectangleSet.txt";
// SORT_ASC сотировака в порядке убывания
const std::string SORT_ASC = "ASC";
// SORT_DESC сортировака в порядке возрастания
const std::string SORT_DESC = "DESC";

// RectangleSet структура набора прямоугольников
struct RectangleSet {
	// recVector содержит вектор прямоугольников (структур Rectangle)
	std::vector<Rectangle> recVector;

	// sortMap содержит данные для сортировки map[название поля]isDesc
	std::map<std::string, bool> sortMap;
	// sortVector хранит имена колонок в порядке котором следует производить сортировку
	std::vector<std::string> sortVector;

	// RectangleSet конструктор, срабатывающий при инициализации структуры
	RectangleSet() {
		// Определяем прямоугольник по умолчанию
		/*Rectangle newRectangle;
		newRectangle.width = 2.14;
		newRectangle.height = 4.71;
		newRectangle.area = newRectangle.width * newRectangle.height;
		this->recVector.push_back(newRectangle);*/
	}

	// print печатает содержимое набора прямоуголников в консоль
	void print();
	// print печатает содержимое карты для сортировки в консоль
	void printSortMap();
	// print печатает содержимое вектора для сортировки в консоль
	void printSortVector();
	// add добавляет новый прямоугольник в набор
	void add();
	// deleteCards удаляет один или несколько прямоугольников из набора
	void deleteCards();
	// saveToFile сохраняет данные в файл
	void saveToFile();
	// readFromFile считывает данные из файла
	void readFromFile();
	/* 
		search находит один или несколько прямоугольников из набора площадь
		которых соответствует указанному (stdin) числу
	*/
	void search();
	// sort сортирует прямоугольники в определенном порядке
	void initSort();
	/*
		parseSortString преобразует строку(std:cin) в данные необходимые для сортировки,
		заполняет поля sortMap и sortVector, возвращает false в случае ошибки
	 */
	bool parseSortString(std::string str);
	// sortBook сортирует имеющиеся в картатеке книги
	void sortBook();
	/*
		cmpRectangleRecursive рекурсивно проходит по sortVector проверяя какое из значений больше
		1 если firstVectorIndex > secondVectorIndex
		0 если firstVectorIndex == secondVectorIndex
		-1 если firstVectorIndex < secondVectorIndex
	*/
	std::pair<int, bool> cmpRectangleRecursive(
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
