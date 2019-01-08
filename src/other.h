// в этом заголовке я обьявляю все константы, библиотеки,структуры,методы и функции.
#include <cstdio> // стандартная библиотека
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cctype>
#include <utility>
#include <cstring> // библиотека для работы со строками (используем для strcmp(), strlen())
#include <string.h>
#include <cmath> // библиотека с математическими функциями, например для округления float значений

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
// SORT_ASC сортировка в порядке возрастания
const char SORT_ASC[] = "ASC";
// SORT_DESC сортировка в порядке  убывания
const char SORT_DESC[] = "DESC";

/*
* SortMapItem содержит struct{название поля, сортировать по DESC?}
* columnName - значение одной из констант с названием колонки
* isDesc - нужно ли сортировать эту колонку по убыванию (DESC)
*/
struct SortMapItem
{
	char *columnName = new char[100];
	bool isDesc = false;
};

/*
* SortMap содержит данные для сортировки
* size - содержит значение размера динамического массива указателей на SortMapItem
* arr - содержит динамический массив уникальных значений SortMapItem
*/
struct SortMap
{
	size_t size = 0;
	SortMapItem **arr = new SortMapItem *[COLUMN_COUNT];
};

/*
* RectangleDLL структура набора прямоугольников (DLL -> doubly linked list)
*/
struct RectangleDLL
{
	// *firstRectangle - указатель на первый прямоугольник в двухсвязанном списке
	struct Rectangle *firstRectangle = nullptr;
	// *lastRectangle - указатель на последний прямоугольник в двухсвязанном списке
	struct Rectangle *lastRectangle = nullptr;
	// size - хранит количество прямоугольников в наборе
	size_t size = 0;

	// recDinArr содержит структуру с промежуточным буффером прямоугольников (структур Rectangle)
	RectangleDinArr *recDinArr = new RectangleDinArr;
	// sortMap содержит данные для сортировки struct{название поля, тип сортировки}
	SortMap *sortMap = new SortMap;
};

/*
* SortPair используется для передачи результирующего значения у функции cmpRectangleRecursive
* resCmp - содержит результат сравнения текущей и предыдущей колонки (-1<=resCmp<=1)
* isDesc - содержит true если колонку необходимо сортировать по убыванию
*/
struct SortPair
{
	int resCmp = 0;
	bool isDesc = false;
};

/*
* StringDinArr структура содержащая динамический массив строк и размер массива
* size - содержит значение числа строк в динамическом массиве
* arr - динамический массив строк
*/
struct StringDinArr
{
	size_t size = 0;
	char **arr = new char *[0];
};

// run запускает работу программы
void run();

// printRectangleDLL печатает содержимое набора прямоугольников в консоль
void printRectangleDLL(RectangleDLL *&recDLL);

/* printRectangleDinArr печатает содержимое промежуточного буфера прямоугольников в консоль */
void printRectangleDinArr(RectangleDLL *&recDLL);

// printSortMap печатает содержимое карты для сортировки в консоль
void printSortMap(RectangleDLL *&recDLL);

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
struct Rectangle *searchRectangleFromIndex(RectangleDLL *&recDLL, size_t index);

// clearDLL очищает память от данных по прямоугольнику
void clearDLL(RectangleDLL *&recDLL);

// initRectangleSort сортирует прямоугольники в определенном порядке
void initRectangleSort(RectangleDLL *&recDLL);

// fillRecDinArrayFromDoublyLinkedList формирует вектор recDinArray из данных двухсвязанного списка
void fillRecDinArrayFromDoublyLinkedList(RectangleDLL *&recDLL);

// fillDoublyLinkedListFromRecDinArray формирует двухсвязанный список из динамического массива recDinArr
void fillDoublyLinkedListFromRecDinArray(RectangleDLL *&recDLL);

/*
*	parseRectangleSortString преобразует строку(std:cin) в данные необходимые для сортировки,
*	заполняет поля sortMap и возвращает false в случае ошибки
*/
bool parseRectangleSortString(RectangleDLL *&recDLL, const char *str);

/*
*	addToSortMap добавляет новый SortMapItem в динамический массив sortMap,
*	если значение поля SortMapItem->columnName уже есть в массиве то просто
*	обновляется значение SortMapItem->isDesc
*/
void addToSortMap(RectangleDLL *&recDLL, char *columnName, bool isDesc);

// sortRectangleDLL сортирует прямоугольники
void sortRectangleDLL(RectangleDLL *&recDLL);

/*
*	cmpRectangleRecursive рекурсивно проходит по sortMap проверяя которое из значений больше
*	1 если firstSortIndex > secondSortIndex
*	0 если firstSortIndex == secondSortIndex
*	-1 если firstSortIndex < secondSortIndex
*/
SortPair *cmpRectangleRecursive(
	RectangleDLL *&recDLL,
	const size_t firstSortIndex,
	const size_t secondSortIndex,
	const size_t sortIndex);

// strSpaceWrap добавляет пробел в начало и конец строки
const char *strSpaceWrap(const char *str);

// alignCenter печатает содержимое ячейки табицы по центру
const char *alignCenter(const char *s, const int w);

// split разбивает строку по разделителю
StringDinArr *split(const char *s, const char sep);
