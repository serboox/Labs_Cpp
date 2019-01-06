#include <iostream> // заголовочный файл стандартной библиотеки для работы с вводом/выводом
#include <string>   // заголовочный файл стандартной библиотеки для работы со строками
#include <stdlib.h> // заголовочный файл стандартной библиотеки

#if !defined(WIN32) && !defined(_WIN32) && !defined(_WIN64)
#include <unistd.h> // библиотека для функции sleep() используемая в Unix
#endif

// Перечисляем строковые константы для определеня названия колонок
// Колонки используются при печати таблицы в консоль и при вводе названия колонки для сортировки
const char COLUMN_INDEX_TITLE[] = "Index",
		   COLUMN_WIDTH_TITLE[] = "Высота",
		   COLUMN_HEIGHT_TITLE[] = "Ширина",
		   COLUMN_AREA_TITLE[] = "Площадь";

// Rectangle, структура прямугольника
// Поля и методы по умолчанию имеют модификатор доступа public
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

/* fillRectangleFromStdIn заполняет поля прямогулольника через stdin */
void fillRectangleFromStdIn(Rectangle *&rectangle);
/* printRectangle печатает информацию о прямоугольнике в stdout */
void printRectangle(Rectangle *&rectangle);
/* validateColumnTitle производит проверку соответствует ли строка
	названию одной одной из колонок */
bool validateColumnTitle(const std::string str);