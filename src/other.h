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

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
// DEFAULT_PATH_TO_FILE константа хранящая путь для сохраняемого/считываемого файла по умолчанию
const char DEFAULT_PATH_TO_FILE[] = "C:\\Users\\Public\\rectangleSet.txt";
#else
// DEFAULT_PATH_TO_FILE константа хранящая путь для сохраняемого/считываемого файла по умолчанию
const char DEFAULT_PATH_TO_FILE[] = "./rectangleSet.txt";
#endif
// SORT_ASC сотировака в порядке возрастания
const char SORT_ASC[] = "ASC";
// SORT_DESC сортировака в порядке  убывания
const char SORT_DESC[] = "DESC";

// RectangleDLL структура набора прямоугольников (DLL -> doubly linked list)
struct RectangleDLL
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
};

// run запускает программы
void run();

// printRectangleDLL печатает содержимое набора прямоуголников в консоль
void printRectangleDLL(RectangleDLL *&recDLL);

/* printRecVector печатает содержимое промежуточного вектора прямоуголников в консоль */
void printRecVector(RectangleDLL *&recleDLL); // TODO:: Сделать сэтим что-то
// printSortMap печатает содержимое карты для сортировки в консоль
void printSortMap(RectangleDLL *&recDLL); // TODO:: Сделать сэтим что-то
// print печатает содержимое вектора для сортировки в консоль
void printSortVector(RectangleDLL *&recDLL); // TODO:: Сделать сэтим что-то

// add добавляет новый прямоугольник в набор
void addRectangle(RectangleDLL *&recDLL);
// deleteRectangle удаляет один или несколько прямоугольников из набора
void deleteRectangle(RectangleDLL *&recDLL);
// saveToFile сохраняет данные в файл
void saveToFile(RectangleDLL *&recDLL);
// readFromFile считывает данные из файла
void readFromFile(RectangleDLL *&recDLL);
/*
		search находит один или несколько прямоугольников из набора площадь
		которых соответствует указанному (stdin) числу
*/
void searchRectangle(RectangleDLL *&recDLL);
// searchFromIndex находит прямоугольник по индексу
Rectangle *searchRectangleFromIndex(RectangleDLL *&recDLL, size_t index);

// clearDLL очищает память от данных по прямоугольнику
void clearDLL(RectangleDLL *&recDLL);
// initRectangleSort сортирует прямоугольники в определенном порядке
void initRectangleSort(RectangleDLL *&recDLL);
// fillRecVectorFromDoublyLinkedList формирует вектор recVector из данных двухсвязанного списка
void fillRecVectorFromDoublyLinkedList(RectangleDLL *&recDLL);
// fillDoublyLinkedListFromRecVector формирует двухсвязанный список из вуктора recVector
void fillDoublyLinkedListFromRecVector(RectangleDLL *&recDLL);

/*
	parseRectangleSortString преобразует строку(std:cin) в данные необходимые для сортировки,
	заполняет поля sortMap и sortVector, возвращает false в случае ошибки
*/
bool parseRectangleSortString(RectangleDLL *&recDLL, std::string str);
// sortRectangleDLL сортирует прямоугольники
void sortRectangleDLL(RectangleDLL *&recDLL);
/*
	cmpRectangleRecursive рекурсивно проходит по sortVector проверяя какое из значений больше
	1 если firstVectorIndex > secondVectorIndex
	0 если firstVectorIndex == secondVectorIndex
	-1 если firstVectorIndex < secondVectorIndex
*/
std::pair<int, bool> cmpRectangleRecursive(
	RectangleDLL *&recDLL,
	const size_t firstVectorIndex,
	const size_t secondVectorIndex,
	const size_t sortIndex);

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
