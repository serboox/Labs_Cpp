#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

const std::string COLUMN_INDEX_TITLE = "Index";
const std::string COLUMN_WIDTH_TITLE = "Высота";
const std::string COLUMN_HEIGHT_TITLE = "Ширина";
const std::string COLUMN_AREA_TITLE = "Площадь";

// Rectangle, структура прямугольника
// Поля и методы по умолчанию имеют модификатор доступа public
struct Rectangle {

	float width; // 4 bytes
	float height; // 4 bytes
	// area высчитывается автоматически area=width*height
	float area; // 4 bytes
	
	// *prevRectangle - указатель на предыдущий прямоугольник
	Rectangle *prevRectangle = NULL;
	// *nextRectangle - указатель на следующий прямоугольник
	Rectangle *nextRectangle = NULL;

	// fillBookFields, функция заполняет поля прямогулольника через stdin
	void fillFromStdIn();
	// print, метод печати прямоугольника в stdout
	void print();
};

/* validateColumnTitle производит проверку соответствует ли строка 
	названию одной одной из колонок */
bool validateColumnTitle(const std::string str);