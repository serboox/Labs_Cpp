#include "iostream"
#include <string>
#include <cmath>
#include <stdlib.h>
#include "book.h"

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

void BOOK::fillFromStdIn() {
	const int YEAR_OF_WRITING = 988;

	std::fprintf(stdout, "Please enter fields\n");
	while (true) {
		std::fprintf(stdout, "authorFirstName (string): ");

		std::getline(std::cin, this->authorFirstName);
		if (this->authorFirstName.size() == 0) {
			std::fprintf(stderr, "The field 'authorFirstName' can not be empty!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "authorLastName (string): ");
		std::getline(std::cin, this->authorLastName);
		if (this->authorLastName.size() == 0) {
			std::fprintf(stderr, "The field 'authorLastName' can not be empty!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "bookTitle (string): ");
		std::getline(std::cin, this->bookTitle);
		if (this->bookTitle.size() == 0) {
			std::fprintf(stderr, "The field 'bookTitle' can not be empty!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "bookYear (short int): ");
		std::scanf("%hu", &this->bookYear);
		std::cin.ignore();
		if (this->bookYear < YEAR_OF_WRITING) {
			std::fprintf(stderr, "The date of writing the book can not be less "
				"than %d!\n", YEAR_OF_WRITING);
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "bookPrice (float): ");
		std::scanf("%f", &this->bookPrice);
		std::cin.ignore();
		if (this->bookPrice < 0) {
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
		//std::printf("Get category number: %d\n", this->getBookCategory(category));

		BookCategoryEnum bookCategoryEnum = this->getBookCategory(category);
		if (bookCategoryEnum == BOOK_CATEGORY_ERROR) {
			std::fprintf(stderr, "The field 'bookCategory' may contain only next values "
				"('hist','mideval', 'detect', 'action', 'travel')"
				"!\n");
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		this->bookCategory = bookCategoryEnum;
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