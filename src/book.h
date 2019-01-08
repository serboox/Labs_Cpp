#include <iostream> // заголовочный файл стандартной библиотеки для работы с вводом/выводом
#include <stdlib.h> // заголовочный файл стандартной библиотеки
#include <cstring>  // библиотека для работы со строками (используем для strcmp();)
#include <sstream>  // библиотека для работы с потоком строк
#if !defined(WIN32) && !defined(_WIN32) && !defined(_WIN64)
#include <unistd.h> // библиотека для функции sleep() используемая в Unix
#endif

// Перечисляем строковые константы категорий у книги
const char
	BOOK_CATEGORY_ERROR_STRING[] = "",
	BOOK_CATEGORY_HIST_STRING[] = "hist",
	BOOK_CATEGORY_MIDEVAL_STRING[] = "mideval",
	BOOK_CATEGORY_DETECT_STRING[] = "detect",
	BOOK_CATEGORY_ACTION_STRING[] = "action",
	BOOK_CATEGORY_TRAVEL_STRING[] = "travel";

// Объявляем enum с перечислением категорий книги
enum BookCategoryEnum
{
	BOOK_CATEGORY_ERROR = -1, // Тип для ошибки
	BOOK_CATEGORY_HIST,		  // Исторический роман
	BOOK_CATEGORY_MIDEVAL,	// Литература античная и средних веков
	BOOK_CATEGORY_DETECT,	 //  Детективы, триллеры
	BOOK_CATEGORY_ACTION,	 // Боевик, книга о войне
	BOOK_CATEGORY_TRAVEL,	 // Приключения, путешествия
};

// Перечисляем строковые константы для определеня названия колонок
// Колонки используются при печати таблицы в консоль, при вводе названия колонки и для сортировки
const char COLUMN_INDEX_TITLE[6] = "Index",
		   COLUMN_AUTHOR_FIRST_NAME_TITLE[4] = "Имя",
		   COLUMN_AUTHOR_LAST_NAME_TITLE[8] = "Фамилия",
		   COLUMN_BOOK_TITLE_TITLE[10] = "Заголовок",
		   COLUMN_BOOK_YEAR_TITLE[4] = "Год",
		   COLUMN_BOOK_PRICE_TITLE[5] = "Цена",
		   COLUMN_BOOK_CATEGORY_TITLE[10] = "Категория";

// COLUMN_COUNT константа определяющая число колонок в таблице
const size_t COLUMN_COUNT = 7;

/*
* BOOK определяющая структуру для книги
*/
struct BOOK
{
	char *authorFirstName = new char[256];
	char *authorLastName = new char[256];
	char *bookTitle = new char[1024];
	short int bookYear;
	float bookPrice;
	BookCategoryEnum bookCategory;
};

// getBookCategory функция для получения строкового ключа за место значения константы
const char *getBookCategory(struct BOOK *&book);

// Перегружаем функцию getBookCategory для получения значения костанты за место строкового ключа
BookCategoryEnum getBookCategory(const char *category);

/* fillBookFromStdIn заполняет поля книги через stdin */
void fillBookFromStdIn(struct BOOK *&book);

/* printBook печатает информацию о книге в stdout */
void printBook(struct BOOK *&book);

/* validateColumnTitle производит проверку соответствует ли строка
	названию одной одной из колонок */
bool validateColumnTitle(const char *str);

// semicolonToSpace все знаки ';' на пробелы
const char *semicolonToSpace(const char *text);