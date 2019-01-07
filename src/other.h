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
#include <cstring> // библиотека для работы со строками (используем для strcmp(), strlen())
#include <string.h>
#include <cmath> // для округления float значений

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

	// recDinArr содержит структуру с промежуточным буффером прямоугольников (структур Rectangle)
	RectangleDinArr *recDinArr;

	// recVector содержит вектор с промежуточным буффером прямоугольников (структур Rectangle)
	std::vector<Rectangle> recVector; //FIXME:Deprecated
	// sortMap содержит данные для сортировки map[название поля]isDesc
	std::map<std::string, bool> sortMap; //FIXME:Deprecated
	// sortVector хранит имена колонок в порядке котором следует производить сортировку
	std::vector<std::string> sortVector; //FIXME:Deprecated
};

/*
* StringDinArr структура описывающая динамический массив char строк
*/
struct StringDinArr
{
	size_t size = 0;
	char **arr = new char *[0];
};

// run запускает программы
void run();

// printRectangleDLL печатает содержимое набора прямоуголников в консоль
void printRectangleDLL(RectangleDLL *&recDLL);
/* printRectangleDinArr печатает содержимое промежуточного буфера прямоуголников в консоль */
void printRectangleDinArr(RectangleDLL *&recDLL);

/* printRecVector печатает содержимое промежуточного вектора прямоуголников в консоль */
void printRecVector(RectangleDLL *&recleDLL); //FIXME:Deprecated
// printSortMap печатает содержимое карты для сортировки в консоль
void printSortMap(RectangleDLL *&recDLL); //FIXME:Deprecated
// print печатает содержимое вектора для сортировки в консоль
void printSortVector(RectangleDLL *&recDLL); //FIXME:Deprecated

// add добавляет новый прямоугольник в набор
void addRectangle(RectangleDLL *&recDLL);
// deleteRectangle удаляет один или несколько прямоугольников из набора
void deleteRectangle(RectangleDLL *&recDLL);
// saveToFile сохраняет данные в файл
void saveToFile(RectangleDLL *&recDLL);
// loadFromFile считывает данные из файла
void loadFromFile(RectangleDLL *&recDLL);
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
// fillDoublyLinkedListFromRecVector формирует двухсвязанный список из вектора recVector
void fillDoublyLinkedListFromRecVector(RectangleDLL *&recDLL); //FIXME:Deprecated
// fillDoublyLinkedListFromRecDinArray формирует двухсвязанный список из динамического массива recDinArr
void fillDoublyLinkedListFromRecDinArray(RectangleDLL *&recDLL);

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
const char *strSpaceWrap(const char *str);
// alignCenter печатает содержимое ячейки табицы по центру
const char *alignCenter(const char *s, const int w);
// split разбивает строку по разделителю
StringDinArr *split(const char *s, const char sep);
