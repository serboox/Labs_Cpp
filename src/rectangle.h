#include <iostream> // заголовочный файл стандартной библиотеки для работы с вводом/выводом
#include <stdlib.h> // заголовочный файл стандартной библиотеки
#include <cstring>  // библиотека для работы со строками (используем для strcmp();)

#if !defined(WIN32) && !defined(_WIN32) && !defined(_WIN64)
#include <unistd.h> // библиотека для функции sleep() используемая в Unix
#endif

// Перечисляем строковые константы для определения названия колонок
// Колонки используются при печати таблицы в консоль и при вводе названия колонки для сортировки
const char COLUMN_INDEX_TITLE[] = "Index",
		   COLUMN_WIDTH_TITLE[] = "Высота",
		   COLUMN_HEIGHT_TITLE[] = "Ширина",
		   COLUMN_AREA_TITLE[] = "Площадь";

// COLUMN_COUNT константа определяющая число колонок в таблице
const size_t COLUMN_COUNT = 4;

/*
* Rectangle, структура прямугольника
*/
struct Rectangle
{
	// width ширина прямоугольника
	float width;  // 4 bytes
				  // height высота прямоугольника
	float height; // 4 bytes
	// area площадь прямоугольника, высчитывается автоматически area=width*height
	float area; // 4 bytes
	// *prevRectangle - указатель на предыдущий прямоугольник
	Rectangle *prevRectangle = nullptr;
	// *nextRectangle - указатель на следующий прямоугольник
	Rectangle *nextRectangle = nullptr;
};

/*
* RectangleDinArr структура описывающая динамический массив прямоугольников
*/
struct RectangleDinArr
{
	size_t size = 0;
	struct Rectangle **arr = new struct Rectangle *[0];
};

/* fillRectangleFromStdIn заполняет поля прямоугольника через stdin */
void fillRectangleFromStdIn(struct Rectangle *&rectangle);
/* printRectangle печатает информацию о прямоугольнике в stdout */
void printRectangle(struct Rectangle *&rectangle);
/* validateColumnTitle производит проверку соответствует ли строка
	названию одной одной из колонок */
bool validateColumnTitle(const char str[]);