
//Прототипы используемых в данном задании функций:

void printEquation(int A, int B, int C,
	float from, float to, float step, float(*callback)(int A, int B, int C, float x));

double Sum(double x, double y);
double Sub(double x, double y);
double Mul(double x, double y);
double Div(double x, double y);
double Pow(double x, double y);
void calculator();


void Sort(char *pcFirst, int nNumber, int size,
	void(*Swap)(void *, void *), int(*Compare)(void *, void *));

void SwapInt(void *p1, void *p2);

int CmpInt(void *p1, void *p2);

const char
BOOK_CATEGORY_ERROR_STRING[] = "",
BOOK_CATEGORY_HIST_STRING[] = "hist",
BOOK_CATEGORY_MIDEVAL_STRING[] = "mideval",
BOOK_CATEGORY_DETECT_STRING[] = "detect",
BOOK_CATEGORY_ACTION_STRING[] = "action",
BOOK_CATEGORY_TRAVEL_STRING[] = "travel";

enum BookCategoryEnum {
	BOOK_CATEGORY_ERROR = -1, // Тип для ошибки
	BOOK_CATEGORY_HIST, // Исторический роман
	BOOK_CATEGORY_MIDEVAL, // Литература античная и средних веков
	BOOK_CATEGORY_DETECT, //  Детективы, триллеры
	BOOK_CATEGORY_ACTION, // Боевик, книга о войне
	BOOK_CATEGORY_TRAVEL, // Приключения, путешествия
};

// В структуре поля и методы по умолчанию имеют модификатор доступа public
struct BOOK {
	std::string authorFirstName; // 28 bytes
	std::string authorLastName; // 28 bytes
	std::string bookTitle; // 28 bytes
	short int bookYear; // 2 bytes
	/* 2 padding byte */
	float bookPrice; // 4 bytes
	BookCategoryEnum bookCategory; // 4 bytes

	// Обявляем метод
	std::string getBookCategory() {
		std::string category = BOOK_CATEGORY_ERROR_STRING;
		switch (bookCategory) {
		case BOOK_CATEGORY_HIST:
			category = BOOK_CATEGORY_HIST_STRING;
			break;
		case BOOK_CATEGORY_MIDEVAL:
			category = BOOK_CATEGORY_MIDEVAL_STRING;
			break;
		case BOOK_CATEGORY_DETECT:
			category = BOOK_CATEGORY_DETECT_STRING;
			break;
		case BOOK_CATEGORY_ACTION:
			category = BOOK_CATEGORY_ACTION_STRING;
			break;
		case BOOK_CATEGORY_TRAVEL:
			category = BOOK_CATEGORY_TRAVEL_STRING;
			break;
		}
		return category;
	}

	// Перегружаем метод getBookCategory
	BookCategoryEnum getBookCategory(std::string category) {
		if (!category.compare(BOOK_CATEGORY_HIST_STRING)) {
			return BOOK_CATEGORY_HIST;
		}
		else if (!category.compare(BOOK_CATEGORY_MIDEVAL_STRING)) {
			return BOOK_CATEGORY_MIDEVAL;
		}
		else if (!category.compare(BOOK_CATEGORY_DETECT_STRING)) {
			return BOOK_CATEGORY_DETECT;
		}
		else if (!category.compare(BOOK_CATEGORY_ACTION_STRING)) {
			return BOOK_CATEGORY_ACTION;
		}
		else if (!category.compare(BOOK_CATEGORY_TRAVEL_STRING)) {
			return BOOK_CATEGORY_TRAVEL;
		}
		return BOOK_CATEGORY_ERROR;
	}
	// Метод печати книги на экран
	void print() {
		std::printf("Books{\n"
			"\tauthorFirstName (string):%s\n"
			"\tauthorLastName (string): %s\n"
			"\tbookTitle (string): %s\n"
			"\tbookYear (short int): %d\n"
			"\tbookPrice (float): %f\n"
			"\tbookCategory (enum): %s\n}\n",
			this->authorFirstName.c_str(),
			this->authorLastName.c_str(),
			this->bookTitle.c_str(),
			this->bookYear,
			this->bookPrice,
			this->getBookCategory().c_str());
	};
};

// Объявим класс наследуясь от структуры BOOK
class MyBOOK : public BOOK {
public:
	// Определяем тип super
	typedef BOOK super;

	// Объявляем конструктор класса
	MyBOOK(std::string authorFirstName,
		std::string authorLastName,
		std::string bookTitle,
		short int bookYear,
		float bookPrice,
		BookCategoryEnum bookCategory) {

		this->authorFirstName = authorFirstName;
		this->authorLastName = authorLastName;
		this->bookTitle = bookTitle;
		this->bookYear = bookYear;
		this->bookPrice = bookPrice;
		this->bookCategory = bookCategory;
	}

	void print() {
		super::print();
	};
protected:
	// Нет защищенных полей и методов
private:
	// Нет приватных полей и методов
};

void fillBookFields(BOOK &book);

