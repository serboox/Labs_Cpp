
#include "book.h" // Подключаем заголовочный файл с определением

const char *getBookCategory(struct BOOK *&book)
{
	char *category = new char[100];
	strcpy(category, BOOK_CATEGORY_ERROR_STRING);
	switch (book->bookCategory)
	{
	case BOOK_CATEGORY_HIST:
		strcpy(category, BOOK_CATEGORY_HIST_STRING);
		break;
	case BOOK_CATEGORY_MIDEVAL:
		strcpy(category, BOOK_CATEGORY_MIDEVAL_STRING);
		break;
	case BOOK_CATEGORY_DETECT:
		strcpy(category, BOOK_CATEGORY_DETECT_STRING);
		break;
	case BOOK_CATEGORY_ACTION:
		strcpy(category, BOOK_CATEGORY_ACTION_STRING);
		break;
	case BOOK_CATEGORY_TRAVEL:
		strcpy(category, BOOK_CATEGORY_TRAVEL_STRING);
		break;
	case BOOK_CATEGORY_ERROR:
		break;
	}
	return category;
}

BookCategoryEnum getBookCategory(const char *category)
{
	if (strcmp(category, BOOK_CATEGORY_HIST_STRING) == 0)
	{
		return BOOK_CATEGORY_HIST;
	}
	else if (strcmp(category, BOOK_CATEGORY_MIDEVAL_STRING) == 0)
	{
		return BOOK_CATEGORY_MIDEVAL;
	}
	else if (strcmp(category, BOOK_CATEGORY_DETECT_STRING) == 0)
	{
		return BOOK_CATEGORY_DETECT;
	}
	else if (strcmp(category, BOOK_CATEGORY_ACTION_STRING) == 0)
	{
		return BOOK_CATEGORY_ACTION;
	}
	else if (strcmp(category, BOOK_CATEGORY_TRAVEL_STRING) == 0)
	{
		return BOOK_CATEGORY_TRAVEL;
	}
	return BOOK_CATEGORY_ERROR;
}

// fillBookFromStdIn заполняет поля книги через stdin
void fillBookFromStdIn(BOOK *&book)
{
	const int YEAR_OF_WRITING = 988;

	book->authorFirstName = new char[256];
	book->authorLastName = new char[256];
	book->bookTitle = new char[1024];

	std::fprintf(stdout, "Please enter fields\n");

	while (true)
	{
		std::fprintf(stdout, "authorFirstName (string): ");
		std::cin.getline(book->authorFirstName, 255);
		std::cin.clear();
		strcpy(book->authorFirstName, semicolonToSpace(book->authorFirstName));
		if (strlen(book->authorFirstName) == 0)
		{
			std::fprintf(stderr, "The field 'authorFirstName' can not be empty!\n");
			/*
			 *  Делаем ожидание для корректного вывода текстовый полей в консоль иначе текст может поехать
			 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_sleep(100);
#else
			sleep(200);
#endif
			continue;
		}
		break;
	}

	while (true)
	{
		std::fprintf(stdout, "authorLastName (string): ");
		std::cin.getline(book->authorLastName, 255);
		std::cin.clear();
		strcpy(book->authorLastName, semicolonToSpace(book->authorLastName));
		if (strlen(book->authorLastName) == 0)
		{
			std::fprintf(stderr, "The field 'authorLastName' can not be empty!\n");
			/*
			 *  Делаем ожидание для корректного вывода текстовый полей в консоль иначе текст может поехать
			 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_sleep(100);
#else
			sleep(200);
#endif
			continue;
		}
		break;
	}

	while (true)
	{
		std::fprintf(stdout, "bookTitle (string): ");
		std::cin.getline(book->bookTitle, 1023);
		std::cin.clear();
		strcpy(book->bookTitle, semicolonToSpace(book->bookTitle));
		if (strlen(book->bookTitle) == 0)
		{
			std::fprintf(stderr, "The field 'bookTitle' can not be empty!\n");
			/*
			 *  Делаем ожидание для корректного вывода текстовый полей в консоль иначе текст может поехать
			 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_sleep(100);
#endif
			continue;
		}
		break;
	}

	while (true)
	{
		std::fprintf(stdout, "bookYear (short int): ");
		std::scanf("%hu", &book->bookYear);
		std::cin.ignore();
		if (book->bookYear < YEAR_OF_WRITING)
		{
			std::fprintf(stderr, "The date of writing the book can not be less "
								 "than %d!\n",
						 YEAR_OF_WRITING);
			/*
			 *  Делаем ожидание для корректного вывода текстовый полей в консоль иначе текст может поехать
			 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_sleep(100);
#endif
			continue;
		}
		break;
	}

	while (true)
	{
		std::fprintf(stdout, "bookPrice (float): ");
		std::scanf("%f", &book->bookPrice);
		std::cin.ignore();
		if (book->bookPrice < 0)
		{
			std::fprintf(stderr, "The cost of the book can not be less than %d!\n", 0);
			/*
			 *  Делаем ожидание для корректного вывода текстовый полей в консоль иначе текст может поехать
			 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_sleep(100);
#endif
			continue;
		}
		break;
	}

	char *category = new char[256];
	while (true)
	{
		std::fprintf(stdout, "bookCategory (strings): ");
		std::cin.getline(category, 255);
		std::cin.clear();
		if (strlen(category) == 0)
		{
			std::fprintf(stderr, "The field 'bookCategory' can not be empty!\n");
			/*
			 *  Делаем ожидание для корректного вывода текстовый полей в консоль иначе текст может поехать
			 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_sleep(100);
#endif
			continue;
		}

		std::printf("Input category: %s\n", category);
		//std::printf("Get category number: %d\n", getBookCategory(category));

		BookCategoryEnum bookCategoryEnum = getBookCategory(category);
		if (bookCategoryEnum == BOOK_CATEGORY_ERROR)
		{
			std::fprintf(stderr, "The field 'bookCategory' may contain only next values "
								 "('hist','mideval', 'detect', 'action', 'travel')"
								 "!\n");
			/*
			 *  Делаем ожидание для корректного вывода текстовый полей в консоль иначе текст может поехать
			 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_sleep(100);
#endif
			continue;
		}
		book->bookCategory = bookCategoryEnum;
		break;
	}
	std::cout << std::endl;
}

// printBook печатает информацию о книге в stdout (консоль)
void printBook(struct BOOK *&book)
{
	std::printf("Books{\n"
				"\tauthorFirstName (string):%s\n"
				"\tauthorLastName (string): %s\n"
				"\tbookTitle (string): %s\n"
				"\tbookYear (short int): %d\n"
				"\tbookPrice (float): %f\n"
				"\tbookCategory (enum): %s\n}\n",
				book->authorFirstName,
				book->authorLastName,
				book->bookTitle,
				book->bookYear,
				book->bookPrice,
				getBookCategory(book));
};

/* validateColumnTitle функция производящая проверку соответствует ли строка
	названию одной одной из колонок */
bool validateColumnTitle(const char *str)
{
	if (strcmp(str, COLUMN_AUTHOR_FIRST_NAME_TITLE) == 0)
	{
		return true;
	}
	else if (strcmp(str, COLUMN_AUTHOR_LAST_NAME_TITLE) == 0)
	{
		return true;
	}
	else if (strcmp(str, COLUMN_BOOK_TITLE_TITLE) == 0)
	{
		return true;
	}
	else if (strcmp(str, COLUMN_BOOK_YEAR_TITLE) == 0)
	{
		return true;
	}
	else if (strcmp(str, COLUMN_BOOK_PRICE_TITLE) == 0)
	{
		return true;
	}
	else if (strcmp(str, COLUMN_BOOK_CATEGORY_TITLE) == 0)
	{
		return true;
	}
	return false;
}

const char *semicolonToSpace(const char *text)
{
	//std::printf("Start semicolonToSpace\n");
	std::stringstream buff;
	for (size_t i = 0; i < strlen(text); i++)
	{
		if (text[i] == ';')
		{
			buff << ' ';
			continue;
		}
		buff << text[i];
	}
	char *res = new char[buff.str().length()];
	strcpy(res, buff.str().c_str());
	//std::printf("Finishmake semicolonToSpace\n");
	return res;
}
