// в этом заголовке я обьявляю все константы, библиотеки,структуры,методы и функции.
#include <cstdio> // стандартная библиотека
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
// SORT_ASC сотировака в порядке возрастания
const std::string SORT_ASC = "ASC";
// SORT_DESC сортировака в порядке  убывания
const std::string SORT_DESC = "DESC";

// RectangleSet структура набора прямоугольников
struct RectangleSet
{

	// *firstRectangle - указатель на первый прямоугольник в двухсвязанном списке
	Rectangle *firstRectangle = nullptr;
	// *lastRectangle - указатель на последний прямоугольник в двухсвязанном списке
	Rectangle *lastRectangle = nullptr;
	// size - хранит количество прямоугольников в наборе
	size_t size = 0;

	// recVector содержит вектор с промежуточным буффером прямоугольников (структур Rectangle),
	std::vector<Rectangle> recVector;
	// sortMap содержит данные для сортировки map[название поля]isDesc
	std::map<std::string, bool> sortMap;
	// sortVector хранит имена колонок в порядке котором следует производить сортировку
	std::vector<std::string> sortVector;

	// RectangleSet конструктор, срабатывающий при инициализации структуры
	RectangleSet()
	{
		// Определяем прямоугольник по умолчанию
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

	// RectangleSet дуструктор, срабатывающий при выгрузке структуры из памяти структуры
	~RectangleSet()
	{
		this->clear();
	}

	// print печатает содержимое набора прямоуголников в консоль
	void print();
	/* print печатает содержимое промежуточного вектора прямоуголников в консоль */
	void printRecVector();
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
	// searchFromIndex находит прямоугольник по индексу
	Rectangle *searchFromIndex(size_t index);

	// clear находит прямоугольник по индексу
	void clear();
	// sort сортирует прямоугольники в определенном порядке
	void initSort();
	// fillRecVectorFromDoublyLinkedList формирует вектор recVector из данных двухсвязанного списка
	void fillRecVectorFromDoublyLinkedList();
	// fillDoublyLinkedListFromRecVector формирует двухсвязанный список из вуктора recVector
	void fillDoublyLinkedListFromRecVector();
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
std::vector<std::string> split(const std::string &s, const char sep);
