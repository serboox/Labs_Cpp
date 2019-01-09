
//Прототипы (интерфесы) используемых в данном задании функций:

// printEquation, печатает в виде таблицы результаты уравнения
// в заданном диапазоне
void printEquation(int A, int B, int C, float from, float to, float step);

// Sum, функция выполняющая оперцию сложения
double Sum(double x, double y);
// Sub, функция выполняющая оперцию вычитания
double Sub(double x, double y);
// Mul, функция выполняющая оперцию умножения
double Mul(double x, double y);
// Div, функция выполняющая оперцию деления
double Div(double x, double y);
// Pow, функция выполняющая оперцию возведения в степень
double Pow(double x, double y);
void calculator();

// Sort, сортирует пузырьком
void Sort(char *pcFirst, int nNumber, int size,
		  void (*Swap)(void *, void *), int (*Compare)(void *, void *));

// SwapInt, переставляет значения аргументов
void SwapInt(void *p1, void *p2);
// CmpInt, которая принимает два void указателя и
//возвращает int результат сравнения:
//<0 - первый элемент меньше, чем второй
//=0 - равны
//>0 - первый элемент больше, чем второй
int CmpInt(void *p1, void *p2);

// SwapDouble, переставляет значения аргументов
void SwapDouble(void *p1, void *p2);
// CmpDouble, которая принимает два void указателя и
//возвращает double результат сравнения:
//<0 - первый элемент меньше, чем второй
//=0 - равны
//>0 - первый элемент больше, чем второй
int CmpDouble(void *p1, void *p2);

// SwapChar, переставляет значения аргументов
void SwapChar(void *p1, void *p2);
// CmpChar, которая принимает два void указателя и
//возвращает char результат сравнения:
//<0 - первый элемент меньше, чем второй
//=0 - равны
//>0 - первый элемент больше, чем второй
int CmpChar(void *p1, void *p2);

// GetString0, возвращает строку
const char *GetString0();
// GetString1, возвращает строку
const char *GetString1();
// GetString2, возвращает строку
const char *GetString2();
// GetString3, возвращает строку
const char *GetString3();
// GetString4, возвращает строку
const char *GetString4();
// GetString5, возвращает строку
const char *GetString5();

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

// BOOK, структура книги
struct BOOK
{
	char *authorFirstName; // 8 bytes
	char *authorLastName;  // 8 bytes
	char *bookTitle;	   // 8 bytes
	short int bookYear;	// 2 bytes
	/* 2 padding byte */
	float bookPrice;			   // 4 bytes
	BookCategoryEnum bookCategory; // 4 bytes
};

// getBookCategory функция для получения строкового ключа за место значения константы
const char *getBookCategory(struct BOOK *&book);
// Перегружаем функцию getBookCategory для получения значения костанты за место строкового ключа
BookCategoryEnum getBookCategory(const char *category);
// printBook функция для печати книги на экран
void printBook(struct BOOK *&book);

// fillBookFromStdIn, функция для заполнения полей книги через stdin
void fillBookFromStdIn(struct BOOK *&book);

// printOneDimArray, печатает в stdout одноуровневый массив
template <typename T>
void printOneDimArray(const T arr, size_t values);

// printTwoDimArray, печатает в stdout двухуровневый массив
template <typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns);
