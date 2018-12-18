
#include <iostream>

// Перечисляем строковые константы категорий у книги 
const char
BOOK_CATEGORY_ERROR_STRING[] = "",
BOOK_CATEGORY_HIST_STRING[] = "hist",
BOOK_CATEGORY_MIDEVAL_STRING[] = "mideval",
BOOK_CATEGORY_DETECT_STRING[] = "detect",
BOOK_CATEGORY_ACTION_STRING[] = "action",
BOOK_CATEGORY_TRAVEL_STRING[] = "travel";

// Объявляем enum с перечислением категорий книги
enum BookCategoryEnum {
	BOOK_CATEGORY_ERROR = -1, // Тип для ошибки
	BOOK_CATEGORY_HIST, // Исторический роман
	BOOK_CATEGORY_MIDEVAL, // Литература античная и средних веков
	BOOK_CATEGORY_DETECT, //  Детективы, триллеры
	BOOK_CATEGORY_ACTION, // Боевик, книга о войне
	BOOK_CATEGORY_TRAVEL, // Приключения, путешествия
};

// BOOK, структура книги
// Поля и методы по умолчанию имеют модификатор доступа public
struct BOOK {
	std::string authorFirstName; // 28 bytes
	std::string authorLastName; // 28 bytes
	std::string bookTitle; // 28 bytes
	short int bookYear; // 2 bytes
	/* 2 padding byte */
	float bookPrice; // 4 bytes
	BookCategoryEnum bookCategory; // 4 bytes

	// fillBookFields, функция заполняет поля книги через stdin
	void fillFromStdIn();
	// getBookCategory, метод для получения строкового ключа за место значения константы
	std::string getBookCategory();
	// Перегружаем метод getBookCategory для получения значения костанты за место строкового ключа
	BookCategoryEnum getBookCategory(std::string category);
	// print, метод печати книги на экран
	void print();
};

// semicolonToSpace все знаки ';' на пробелы
void semicolonToSpace(std::string &text);

// printOneDimArray, печатает в stdout одноуровневый массив
template<typename T>
void printOneDimArray(const T arr, size_t values);

// printTwoDimArray, печатает в stdout двухуровневый массив
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns);