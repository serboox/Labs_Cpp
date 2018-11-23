#include "iostream"
#include "other.h"
#include <unistd.h>

///////////////////////////////////////////////////

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst+j*size;
			char* pPrevious = pcFirst+(j-1)*size;
			if((*Compare)( pPrevious, pCurrent ) > 0)//требуется
												//переставить
				(*Swap)( pPrevious, pCurrent );
		}
}

void SwapInt(void* p1, void* p2)
{


}

int CmpInt(void* p1, void* p2)
{
	int nResult = 0;




	return nResult;
}

void fillBookFields(BOOK &book) {
	const int YEAR_OF_WRITING = 988;

	std::fprintf(stdout, "Please enter fields\n");
	while(true) {
		std::fprintf(stdout, "authorFirstName (string): ");
		std::getline(std::cin, book.authorFirstName);
		if (book.authorFirstName.size() == 0) {
			std::fprintf(stderr, "The field 'authorFirstName' can not be empty!\n");
			usleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while(true) {
		std::fprintf(stdout, "authorLastName (string): ");
		std::getline(std::cin, book.authorLastName);
		if (book.authorLastName.size() == 0) {
			std::fprintf(stderr, "The field 'authorLastName' can not be empty!\n");
			usleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while(true) {
		std::fprintf(stdout, "bookTitle (string): ");
		std::getline(std::cin, book.bookTitle);
		if (book.bookTitle.size() == 0) {
			std::fprintf(stderr, "The field 'bookTitle' can not be empty!\n");
			usleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while(true) {
		std::fprintf(stdout, "bookYear (short int): ");
		std::scanf("%hu", &book.bookYear);
		std::cin.ignore();
		if (book.bookYear < YEAR_OF_WRITING) {
			std::fprintf(stderr, "The date of writing the book can not be less "
						"than %d!\n",YEAR_OF_WRITING);
			usleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while(true) {
		std::fprintf(stdout, "bookPrice (float): ");
		std::scanf("%f", &book.bookPrice);
		std::cin.ignore();
		if (book.bookPrice < 0) {
			std::fprintf(stderr, "The cost of the book can not be less than %d!\n",0);
			usleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while(true) {
		std::fprintf(stdout, "bookCategory (strings): ");
		std::string category;
		std::getline(std::cin, category);
		if (category.size() == 0) {
			std::fprintf(stderr, "The field 'bookCategory' can not be empty!\n");
			usleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}

		std::printf("Input category: %s\n", category.c_str());
		std::printf("Get category number: %d\n", book.getBookCategory(category));

		BookCategoryEnum bookCategoryEnum = book.getBookCategory(category);
		if (bookCategoryEnum == BOOK_CATEGORY_ERROR) {
			std::fprintf(stderr, "The field 'bookCategory' may contain only next values "
						"('hist','mideval', 'detect', 'action', 'travel')"
						"!\n");
			usleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		book.bookCategory = bookCategoryEnum;
		break;
	}
	std::cout << std::endl;
}
