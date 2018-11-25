
//Прототипы (интерфесы) используемых в данном задании функций:

// printEquation, печатает в виде таблицы результаты уравнения 
// в заданном диапазоне
void printEquation(int A, int B, int C,
	float from, float to, float step, float(*callback)(int A, int B, int C, float x));

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
	void(*Swap)(void *, void *), int(*Compare)(void *, void *));

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

	// getBookCategory, метод для получения строкового ключа за место значения константы
	std::string getBookCategory();
	// Перегружаем метод getBookCategory для получения значения костанты за место строкового ключа
	BookCategoryEnum getBookCategory(std::string category);
	// print, метод печати книги на экран
	void print();
};

// fillBookFields, функция для заполнения полей книги через stdin
void fillBookFields(BOOK &book);

// Объявим класс наследуясь от структуры BOOK
class MyBook : public BOOK {
public:
	// Определяем тип super для обращения к родителю
	typedef BOOK super;

	// Объявляем конструктор класса
	MyBook(std::string authorFirstName,
		std::string authorLastName,
		std::string bookTitle,
		short int bookYear,
		float bookPrice,
		BookCategoryEnum bookCategory);

	void print();
protected:
	// Нет защищенных полей и методов
private:
	// Нет приватных полей и методов
};

// printOneDimArray, печатает в stdout одноуровневый массив
template<typename T>
void printOneDimArray(const T arr, size_t values);

// printTwoDimArray, печатает в stdout двухуровневый массив
template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns);
