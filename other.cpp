#include "iostream"
#include <string>
#include <cmath>
#include <stdlib.h>
#include "other.h"

///////////////////////////////////////////////////

void printEquation(int A, int B, int C,
	float from, float to, float step, float(*callback)(int A, int B, int C, float x)) {

	float x = 0, y = 0;
	// Находим из скольки символов максимум может состоять число х
	int sizeX = (int)log10(std::numeric_limits<float>::max()) + 2;
	// Находим из скольки символов максимум может состоять число y
	int sizeY = (int)log10(std::numeric_limits<float>::max()) + 2;

	std::printf("Max size x: %d\n", sizeX);
	std::printf("Max size y: %d\n", sizeY);

	std::cout << "-";
	for (int i = 1; i <= sizeX; i++) {
		std::cout << "-";
	}
	std::cout << "-";
	for (int i = 1; i <= sizeY; i++) {
		std::cout << "-";
	}
	std::cout << "-\n";

	std::cout << "|";
	for (int i = 2; i <= sizeX / 2; i++) {
		std::cout << " ";
	}
	std::cout << "x";
	for (int i = 1; i <= sizeX / 2; i++) {
		std::cout << " ";
	}
	std::cout << "|";

	for (int i = 1; i <= sizeX / 2; i++) {
		std::cout << " ";
	}
	std::cout << "y";
	for (int i = 2; i <= sizeX / 2; i++) {
		std::cout << " ";
	}
	std::cout << "|\n";

	std::cout << "|-";
	for (int i = 2; i <= sizeX; i++) {
		std::cout << "-";
	}
	std::cout << "-";
	for (int i = 1; i <= sizeY; i++) {
		std::cout << "-";
	}
	std::cout << "|\n";

	for (x = from; x <= to; x += step) {

		int lenX = 3;
		int paddingLeft = (sizeX / 2) - (lenX / 2);
		int paddingRight = paddingLeft;
		if (x < 0) {
			lenX = (int)log10(abs(x)) + 4;
			paddingLeft = (sizeX / 2) - (lenX / 2);
		}
		else if (x > 0) {
			lenX = (int)log10(abs(x)) + 3;
		}
		if ((lenX + paddingLeft + paddingRight) > sizeX + 1) {
			--paddingRight;
		}

		std::cout << "|";
		for (int i = 2; i <= paddingLeft; i++) {
			std::cout << " ";
		}
		std::printf("%.1f", x);
		for (int i = 1; i <= paddingRight; i++) {
			std::cout << " ";
		}
		std::cout << "|";

		// Instead y = A * x * x + B * x + C;
		y = callback(A, B, C, x);
		int lenY = 3;
		if (y < 0) {
			lenY = (int)log10(abs(y)) + 4;
		}
		else if (y > 0) {
			lenY = (int)log10(abs(y)) + 3;
		}

		paddingLeft = (sizeY / 2) - (lenY / 2);
		paddingRight = paddingLeft;
		if ((lenY + paddingLeft + paddingRight) > sizeY) {
			--paddingRight;
		}

		//std::cout << "L: " << lenY << " ";
		//std::cout << "PL: " << paddingLeft << " ";
		//std::cout << "PR: " << paddingRight << " ";

		for (int i = 1; i <= paddingLeft; i++) {
			std::cout << " ";
		}
		std::printf("%.1f", y);
		for (int i = 1; i <= paddingRight; i++) {
			std::cout << " ";
		}
		std::cout << "|\n";
	}
	std::cout << "-";
	for (int i = 1; i <= sizeX; i++) {
		std::cout << "-";
	}
	std::cout << "-";
	for (int i = 1; i <= sizeY; i++) {
		std::cout << "-";
	}
	std::cout << "-\n";
}

double Sum(double x, double y) {
	return x + y;
}
double Sub(double x, double y) {
	return x - y;
}
double Mul(double x, double y) {
	return x * y;
}
double Div(double x, double y) {
	return x / y;
}
double Pow(double x, double y) {
	return pow(x, y);
}

void calculator() {

	// Определяем константя для операций
	const char OPERATION_SUM = '+';
	const char OPERATION_SUB = '-';
	const char OPERATION_MUL = '*';
	const char OPERATION_DIV = '/';
	const char OPERATION_POW = '^';

	// Вводим ограничение на число символов у аргумента
	const size_t MAX_NUM_SIZE = 1024;
	double x = 0.0, y = 0.0;
	double(*operation)(double x, double y);

	while (true) {
		std::printf("Please enter an expression using a space (example 1+2=):\n");

		std::string buffX, buffY;
		char buff, operationChar = ' ';
		size_t indexX = 0, indexY = 0;
		bool xIsFill = false, yIsFill = false, operationIsFill = false;
		// Находим все значения выражения
		while (std::cin >> buff) {
			if (buff == '\n') {
				continue;
			}
			if (buff == '=') {
				std::cin.ignore();
				std::cin.clear();
				break;
			}
			if (!xIsFill && indexX < MAX_NUM_SIZE
				&& ((indexX == 0 && buff == '-') ||
				(buff >= '0' && buff <= '9') || (buff == '.'))) {
				buffX += buff;
				indexX++;
				continue;
			}
			if (!operationIsFill) {
				operationChar = buff;
				xIsFill = true;
				operationIsFill = true;
				continue;
			}
			if (indexY < MAX_NUM_SIZE) {
				buffY += buff;
				indexY++;
				if (buff >= '0' && buff <= '9') {
					yIsFill = true;
				}
				continue;
			}
			std::cin.ignore();
			std::cin.clear();
			break;
		}

		//std::printf("X(string): %s\n", buffX.c_str());
		//std::printf("Y(string): %s\n", buffY.c_str());
		//std::printf("OperationChar (symbol): %c\n", operationChar);

		if (!xIsFill) {
			std::fprintf(stderr, "Please enter first equation argument!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		if (!operationIsFill) {
			std::fprintf(stderr, "Please specify the permissible action on the arguments!\n"
				"('+','-','*','/','**')\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		if (!yIsFill) {
			std::fprintf(stderr, "Please enter last equation argument!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		// Определяем функцию которая будет выполнять действия над аргументами
		switch (operationChar) {
		case OPERATION_SUM:
			operation = Sum;
			break;
		case OPERATION_SUB:
			operation = Sub;
			break;
		case OPERATION_MUL:
			operation = Mul;
			break;
		case OPERATION_DIV:
			operation = Div;
			break;
		case OPERATION_POW:
			operation = Pow;
			break;
		default:
			std::fprintf(stderr, "Please specify the permissible action on the arguments!\n"
				"('+','-','*','/','**')\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}

		// Конвертируем строковые значения в double
		x = std::strtod(buffX.c_str(), NULL);
		y = std::strtod(buffY.c_str(), NULL);

		//std::printf("X(double): %lf\n", x);
		//std::printf("Y(double): %lf\n", y);

		std::printf("Result: %lf\n", (*operation)(x, y));
	}
}

void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0) //требуется переставить
				(*Swap)(pPrevious, pCurrent);
		}
}

void SwapInt(void* p1, void* p2)
{
	int *p1Int = static_cast<int*>(p1);
	int *p2Int = static_cast<int*>(p2);
	int buff = *p2Int;
	*p2Int = *p1Int;
	*p1Int = buff;
}

int CmpInt(void* p1, void* p2)
{
	int *p1Int = static_cast<int*>(p1);
	int *p2Int = static_cast<int*>(p2);
	if (*p1Int < *p2Int) {
		return -1;
	}
	else if (*p1Int == *p2Int) {
		return 0;
	}
	return 1;
}

void SwapDouble(void * p1, void * p2)
{
	double *p1Double = static_cast<double*>(p1);
	double *p2Double = static_cast<double*>(p2);
	double buff = *p2Double;
	*p2Double = *p1Double;
	*p1Double = buff;
}

int CmpDouble(void * p1, void * p2)
{
	double *p1Double = static_cast<double*>(p1);
	double *p2Double = static_cast<double*>(p2);
	if (*p1Double < *p2Double) {
		return -1;
	}
	else if (*p1Double == *p2Double) {
		return 0;
	}
	return 1;
}

void SwapChar(void *p1, void *p2)
{
	char **p1Char = static_cast<char**>(p1);
	char **p2Char = static_cast<char**>(p2);
	char *buff = *p1Char;
	*p1Char = *p2Char;
	*p2Char = buff;
}

int CmpChar(void * p1, void * p2)
{
	char *p1Char = *static_cast<char**>(p1);
	char *p2Char = *static_cast<char**>(p2);
	
	// Для проверки можно использовать
	//return std::strcmp(p1Char, p2Char);

	size_t size1 = sizeof(p1Char) / sizeof(p1Char[0]);
	size_t size2 = sizeof(p2Char) / sizeof(p2Char[0]);
	size_t max = size1;
	if (size2 > max) {
		max = size2;
	}
	
	int res = 0;
	for (size_t i = 0; i < max;i++) {
		if ((i+1) > size1) {
			res = -1;
			break;
		}
		if ((i+1) > size2) {
			res = 1;
			break;
		}
		if (p1Char[i] < p2Char[i]) {
			res = -1;
			break;
		}
		if (p1Char[i] > p2Char[i]) {
			res = 1;
			break;
		}
	}
	return res;
}

std::string BOOK::getBookCategory() {
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

BookCategoryEnum BOOK::getBookCategory(std::string category) {
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

void BOOK::print() {
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

void fillBookFields(BOOK &book) {
	const int YEAR_OF_WRITING = 988;

	std::fprintf(stdout, "Please enter fields\n");
	while (true) {
		std::fprintf(stdout, "authorFirstName (string): ");

		std::getline(std::cin, book.authorFirstName);
		if (book.authorFirstName.size() == 0) {
			std::fprintf(stderr, "The field 'authorFirstName' can not be empty!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "authorLastName (string): ");
		std::getline(std::cin, book.authorLastName);
		if (book.authorLastName.size() == 0) {
			std::fprintf(stderr, "The field 'authorLastName' can not be empty!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "bookTitle (string): ");
		std::getline(std::cin, book.bookTitle);
		if (book.bookTitle.size() == 0) {
			std::fprintf(stderr, "The field 'bookTitle' can not be empty!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "bookYear (short int): ");
		std::scanf("%hu", &book.bookYear);
		std::cin.ignore();
		if (book.bookYear < YEAR_OF_WRITING) {
			std::fprintf(stderr, "The date of writing the book can not be less "
				"than %d!\n", YEAR_OF_WRITING);
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "bookPrice (float): ");
		std::scanf("%f", &book.bookPrice);
		std::cin.ignore();
		if (book.bookPrice < 0) {
			std::fprintf(stderr, "The cost of the book can not be less than %d!\n", 0);
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "bookCategory (strings): ");
		std::string category;
		std::getline(std::cin, category);
		if (category.size() == 0) {
			std::fprintf(stderr, "The field 'bookCategory' can not be empty!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}

		std::printf("Input category: %s\n", category.c_str());
		std::printf("Get category number: %d\n", book.getBookCategory(category));

		BookCategoryEnum bookCategoryEnum = book.getBookCategory(category);
		if (bookCategoryEnum == BOOK_CATEGORY_ERROR) {
			std::fprintf(stderr, "The field 'bookCategory' may contain only next values "
				"('hist','mideval', 'detect', 'action', 'travel')"
				"!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		book.bookCategory = bookCategoryEnum;
		break;
	}
	std::cout << std::endl;
}

MyBook::MyBook(std::string authorFirstName,
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

void MyBook::print() {
	super::print();
}
