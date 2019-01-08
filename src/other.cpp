
#include "other.h"

void run()
{
	struct Card *card = new struct Card;

	while (true)
	{
		char *command = new char[21];
		std::printf("$ ");

		std::cin.clear();
		std::cin.getline(command, 20);
		std::cin.clear();

		if (strcmp(command, COMMAND_HELP) == 0)
		{
			std::printf(
				"%s  Распечатать содержимое картотеки. \n"
				"%s  Добавить новую книгу. \n"
				"%s  Удалить существующий(ие). \n"
				"%s  Записать в файл. \n"
				"%s  Считать из файла. \n"
				"%s  Сортировки набора по одному или нескольким полям. \n"
				"%s  Отобразить список комманд. \n"
				"%s  Выйти. \n",
				COMMAND_PRINT,
				COMMAND_ADD,
				COMMAND_DELETE,
				COMMAND_SAVE,
				COMMAND_LOAD,
				COMMAND_SORT,
				COMMAND_HELP,
				COMMAND_EXIT);
		}
		else if (strcmp(command, COMMAND_PRINT) == 0)
		{
			std::printf("Cодержимое картотеки: \n\n");
			printCard(card);
			std::printf("\n");
		}
		else if (strcmp(command, COMMAND_ADD) == 0)
		{
			std::printf("Добавить новую книгу: \n\n");
			addBookToCard(card);
		}
		else if (strcmp(command, COMMAND_DELETE) == 0)
		{
			std::printf("Удалить существующий(ие): \n");
			deleteBook(card);
		}
		else if (strcmp(command, COMMAND_SAVE) == 0)
		{
			std::printf("Записать в файл: \n");
			saveToFile(card);
		}
		else if (strcmp(command, COMMAND_LOAD) == 0)
		{
			std::printf("Считать из файла: \n");
			loadFromFile(card);
		}
		else if (strcmp(command, COMMAND_SORT) == 0)
		{
			std::printf("Сортировки набора по одному или нескольким полям: \n");
			initCardSort(card);
		}
		else if (strcmp(command, COMMAND_EXIT) == 0)
		{
			break;
		}
		else
		{
			std::printf(
				"Command not be support. Please enter '%s' or '%s'.\n",
				COMMAND_HELP,
				COMMAND_EXIT);
		}

		strcpy(command, "");
		if (strcmp(command, COMMAND_ENDL) == 0)
		{
			std::cin.ignore();
		}
	}
}

const char *strSpaceWrap(const char *str)
{
	char *res = new char[strlen(str) + 2];
	res[0] = ' ';
	size_t i = 1;
	for (; i <= strlen(str); i++)
	{
		res[i] = str[i - 1];
	}
	res[i] = ' ';
	return res;
}

void printCard(struct Card *&card)
{
	//std::printf("Start printCard->size:%zu\n", card->bookDinArr->size);
	if (card->bookDinArr->size <= 0)
	{
		std::printf("Ваш набор пуст. Size: %zu\n", card->bookDinArr->size);
		return;
	}
	size_t indexColumnSize = strlen(strSpaceWrap(COLUMN_INDEX_TITLE)),
		   firstNameColumnSize = strlen(strSpaceWrap(COLUMN_AUTHOR_FIRST_NAME_TITLE)),
		   lastNameColumnSize = strlen(strSpaceWrap(COLUMN_AUTHOR_LAST_NAME_TITLE)),
		   titleColumnSize = strlen(strSpaceWrap(COLUMN_BOOK_TITLE_TITLE)),
		   yearColumnSize = strlen(strSpaceWrap(COLUMN_BOOK_YEAR_TITLE)),
		   priceColumnSize = strlen(strSpaceWrap(COLUMN_BOOK_PRICE_TITLE)),
		   categoryColumnSize = strlen(strSpaceWrap(COLUMN_BOOK_CATEGORY_TITLE));

	for (size_t i = 0; i < card->bookDinArr->size; i++)
	{
		//std::printf("i:%zu\n", i);
		struct BOOK *book = card->bookDinArr->arr[i];
		char *index = new char[indexColumnSize];
		sprintf(index, "%zu", i);
		char *bookYear = new char[yearColumnSize];
		sprintf(bookYear, "%d", book->bookYear);
		char *bookPrice = new char[priceColumnSize];
		sprintf(bookPrice, "%f", book->bookPrice);

		if (indexColumnSize < strlen(index))
		{
			indexColumnSize = strlen(index);
		}
		if (firstNameColumnSize < strlen(book->authorFirstName))
		{
			firstNameColumnSize = strlen(book->authorFirstName);
		}
		if (lastNameColumnSize < strlen(book->authorLastName))
		{
			lastNameColumnSize = strlen(book->authorLastName);
		}

		if (titleColumnSize < strlen(book->bookTitle))
		{
			titleColumnSize = strlen(book->bookTitle);
		}
		if (yearColumnSize < strlen(bookYear))
		{
			yearColumnSize = strlen(bookYear);
		}
		if (priceColumnSize < strlen(bookPrice))
		{
			priceColumnSize = strlen(bookPrice);
		}
		if (categoryColumnSize < strlen(getBookCategory(book)))
		{
			categoryColumnSize = strlen(getBookCategory(book));
		}
	}
	std::cout << alignCenter(COLUMN_INDEX_TITLE, indexColumnSize) << " | "
			  << alignCenter(COLUMN_AUTHOR_FIRST_NAME_TITLE, firstNameColumnSize) << " | "
			  << alignCenter(COLUMN_AUTHOR_LAST_NAME_TITLE, lastNameColumnSize) << " | "
			  << alignCenter(COLUMN_BOOK_TITLE_TITLE, titleColumnSize) << " | "
			  << alignCenter(COLUMN_BOOK_YEAR_TITLE, yearColumnSize) << " | "
			  << alignCenter(COLUMN_BOOK_PRICE_TITLE, priceColumnSize) << " | "
			  << alignCenter(COLUMN_BOOK_CATEGORY_TITLE, categoryColumnSize) << " |\n";

	size_t totalSize = indexColumnSize + firstNameColumnSize + lastNameColumnSize + titleColumnSize;
	totalSize += yearColumnSize + priceColumnSize + categoryColumnSize;
	totalSize += totalSize * 0.21;
	for (size_t i = 0; i <= totalSize; i++)
		std::cout << "—";
	std::cout << std::endl;
	for (size_t i = 0; i < card->bookDinArr->size; i++)
	{
		//std::printf("i:%zu\n", i);
		struct BOOK *book = card->bookDinArr->arr[i];
		char *index = new char[indexColumnSize];
		sprintf(index, "%zu", i);
		char *bookYear = new char[yearColumnSize];
		sprintf(bookYear, "%d", book->bookYear);
		char *bookPrice = new char[priceColumnSize];
		sprintf(bookPrice, "%f", book->bookPrice);

		std::cout << alignCenter(index, indexColumnSize) << " | "
				  << alignCenter(book->authorFirstName, firstNameColumnSize) << " | "
				  << alignCenter(book->authorLastName, lastNameColumnSize) << " | "
				  << alignCenter(book->bookTitle, titleColumnSize) << " | "
				  << alignCenter(bookYear, yearColumnSize) << " | "
				  << alignCenter(bookPrice, priceColumnSize) << " | "
				  << alignCenter(getBookCategory(book), categoryColumnSize) << " |\n";
	}
	//std::printf("Finish printCard\n");
}

void printSortMap(struct Card *&card)
{
	for (size_t i = 0; i < card->sortMap->size; i++)
	{
		SortMapItem *data = card->sortMap->arr[i];
		std::printf("sortMap: %s => %s\n", data->columnName, data->isDesc ? "true" : "false");
	}
}

const char *alignCenter(const char *s, const int w)
{
	int padding = w - strlen(s);
	//std::printf("w:%d;s:%zu;pad:%d; ", w, strlen(s), padding);
	size_t endSpace = 0;
	if (padding > 0 && padding % 2 != 0)
	{
		endSpace = 1;
	}
	padding /= 2;

	size_t resSize = padding + strlen(s) + padding + endSpace;
	std::stringstream buff;
	for (size_t i = 0; i < padding; i++)
	{
		buff << " ";
	}
	for (size_t i = 0; i < strlen(s); i++)
	{
		buff << s[i];
	}
	for (size_t i = 0; i < padding + endSpace; i++)
	{
		buff << " ";
	}
	char *res = new char[buff.str().length() + 1];
	strcpy(res, buff.str().c_str());
	return res;
}

void addBookToCard(struct Card *&card)
{
	struct BOOK *newBook;
	newBook = (struct BOOK *)malloc(sizeof(struct BOOK));
	fillBookFromStdIn(newBook);
	card->bookDinArr->size++;
	card->bookDinArr->arr = (BOOK **)realloc(card->bookDinArr->arr, sizeof(struct BOOK) * card->bookDinArr->size);
	card->bookDinArr->arr[card->bookDinArr->size - 1] = newBook;
}

void deleteBook(struct Card *&card)
{
	char command[10];
	while (true)
	{
		if (card->bookDinArr->size <= 0)
		{
			std::printf("Ваш набор пуст. Size: %zu\n", card->bookDinArr->size);
			return;
		}

		int i;
		size_t firstIndex = 0,
			   lastIndex = card->bookDinArr->size - 1;
		std::printf("Пожалуйста введите Index удаляемой книги (от %zu до %zu): ", firstIndex, lastIndex);
		std::scanf("%d", &i);
		std::cin.ignore();

		if (i < firstIndex || i > lastIndex)
		{
			std::printf("Такой книги не существует! \n");
			while (true)
			{
				strcpy(command, "");
				std::printf("Желаете продолжить? [Y/n]: ");
				std::cin.getline(command, 10);
				std::cin.clear();
				if (strcmp(command, "") == 0 || strcmp(command, "Y") == 0 || strcmp(command, "y") == 0)
				{
					break;
				}
				else if (strcmp(command, "n") == 0 || strcmp(command, "N") == 0)
				{
					return;
				}
				continue;
			}
			continue;
		}

		struct BOOK *deleteBook = card->bookDinArr->arr[i];
		printBook(deleteBook);
		bool remove = false;
		while (true)
		{
			strcpy(command, "");
			std::printf("Вы действительно хотите удалить эту книгу из набора? [Y/n]: ");
			std::cin.getline(command, 10);
			std::cin.clear();
			if (strcmp(command, "") == 0 || strcmp(command, "Y") == 0 || strcmp(command, "y") == 0)
			{
				remove = true;
				break;
			}
			else if (strcmp(command, "n") == 0 || strcmp(command, "N") == 0)
			{
				remove = false;
				break;
			}
			continue;
		}
		//std::printf("Remove: %s\n", remove ? "true" : "false");
		if (remove)
		{
			if (card->bookDinArr->size == 1)
			{
				std::printf("Книга удалена! \n");
				card->bookDinArr = new BookDinArr;
				// Освобождаем память от удаляемого элемента
				delete deleteBook;
				return;
			}

			struct BookDinArr *newBookDinArray = new BookDinArr[card->bookDinArr->size - 1];
			size_t k = 0;
			for (size_t j = 0; j < card->bookDinArr->size; j++)
			{
				if (i == j)
				{
					continue;
				}
				newBookDinArray->arr[k] = card->bookDinArr->arr[j];
				newBookDinArray->size++;
				k++;
			}
			card->bookDinArr = newBookDinArray;
			// Освобождаем память от удаляемого элемента
			delete deleteBook;
			std::printf("Книга удалена! \n");
		}
		while (true)
		{
			strcpy(command, "");
			std::printf("Желаете продолжить? [y/N]: ");
			std::cin.getline(command, 10);
			std::cin.clear();
			if (strcmp(command, "Y") == 0 || strcmp(command, "y") == 0)
			{
				break;
			}
			else if (strcmp(command, "") == 0 || strcmp(command, "n") == 0 || strcmp(command, "N") == 0)
			{
				return;
			}
			continue;
		}
	}
}

void saveToFile(struct Card *&card)
{
	std::ofstream saveFile;
	while (true)
	{
		char pathToFile[1000];
		std::printf("Введите путь к файлу [default:%s]: ", DEFAULT_PATH_TO_FILE);
		std::cin.getline(pathToFile, 1000);
		std::cin.clear();
		if (strcmp(pathToFile, "") == 0)
		{
			strcpy(pathToFile, DEFAULT_PATH_TO_FILE);
		}
		saveFile.open(pathToFile, std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (saveFile.is_open())
		{

			for (size_t i = 0; i < card->bookDinArr->size; i++)
			{
				struct BOOK *book = card->bookDinArr->arr[i];
				char *index = new char[128];
				sprintf(index, "%zu", i);
				char *bookYear = new char[128];
				sprintf(bookYear, "%d", book->bookYear);
				char *bookPrice = new char[128];
				sprintf(bookPrice, "%f", book->bookPrice);

				saveFile << book->authorFirstName;
				saveFile << ";";
				saveFile << book->authorLastName;
				saveFile << ";";
				saveFile << book->bookTitle;
				saveFile << ";";
				saveFile << bookYear;
				saveFile << ";";
				saveFile << bookPrice;
				saveFile << ";";
				saveFile << getBookCategory(book);
				saveFile << "\n";
			}
			saveFile.close();
			std::printf("Файл сохранен по пути: '%s'\n", pathToFile);
			return;
		}
		else
		{
			std::printf("Поток для записи в файл '%s' закрыт! \n", pathToFile);
			continue;
		}
		continue;
	}
}

void loadFromFile(Card *&card)
{
	char *readData = new char[1000];
	std::ifstream input;
	while (true)
	{
		char *pathToFile = new char[1000];
		std::printf("Введите путь к файлу [default:%s]: ", DEFAULT_PATH_TO_FILE);
		std::cin.getline(pathToFile, 1000);
		std::cin.clear();
		if (strcmp(pathToFile, "") == 0)
		{
			strcpy(pathToFile, DEFAULT_PATH_TO_FILE);
		}
		input.open(pathToFile, std::fstream::out);
		if (input.is_open())
		{
			size_t i = 0;
			card->bookDinArr->size = 0;
			struct BOOK **bookDinArr = new BOOK *[1];
			while (input.getline(readData, 1000))
			{
				if (strcmp(readData, "") == 0)
				{
					continue;
				}
				std::printf("%s\n", readData);
				StringDinArr *bookProps = split(readData, ';');
				if (bookProps->size != 6)
				{
					std::printf("Строка %zu не соответствует требуемуму формату т.к."
								"число ее свойств (%zu) должно быть равно 6!\n %s\n",
								i, bookProps->size, readData);
					continue;
				}

				if (i != 0)
				{
					bookDinArr = (BOOK **)realloc(bookDinArr, sizeof(struct BOOK) * (i + 1));
				}
				BOOK *newBook = new BOOK;

				//newBook->authorFirstName = new char[256];
				strcpy(newBook->authorFirstName, bookProps->arr[0]);
				//newBook->authorLastName = new char[256];
				strcpy(newBook->authorLastName, bookProps->arr[1]);
				//newBook->bookTitle = new char[1024];
				strcpy(newBook->bookTitle, bookProps->arr[2]);

				newBook->bookYear = static_cast<short int>(atoi(bookProps->arr[3]));
				newBook->bookPrice = std::stof(bookProps->arr[4]);
				newBook->bookCategory = getBookCategory(bookProps->arr[5]);

				bookDinArr[i] = newBook;
				i++;
				card->bookDinArr->size++;
			}
			card->bookDinArr->arr = bookDinArr;
			input.close();
			std::printf("Файл '%s' прочитан.\n", pathToFile);

			printCard(card);
			return;
		}
		else
		{
			std::printf("Поток для чтения из файла '%s' закрыт! \n", pathToFile);
			return;
		}
		continue;
	}
}

StringDinArr *split(const char *s, const char sep)
{
	//std::printf("strlen:%zu->s:%s\n", strlen(s), s);
	StringDinArr *ret = new StringDinArr;
	ret->arr = new char *[strlen(s)];
	std::stringstream buff;
	for (size_t i = 0; i < strlen(s); i++)
	{
		//std::printf("'%c'=='%c'->%s\n", s[i], sep, s[i] == sep ? "true" : "false");
		if (s[i] == sep)
		{
			//std::printf("ret->arr[%zu]=%s\n", ret->size - 1, buff);
			ret->arr[ret->size] = new char[buff.str().length() + 1];
			strcpy(ret->arr[ret->size], buff.str().c_str());
			buff.str("");
			ret->size++;
			continue;
		}
		buff << s[i];
		//std::printf("buff:%s\n", buff.str().c_str());
	}

	ret->arr[ret->size] = new char[buff.str().length() + 1];
	strcpy(ret->arr[ret->size], buff.str().c_str());
	ret->size++;
	buff.str("");
	return ret;
}

void initCardSort(Card *&card)
{
	if (card->bookDinArr->size <= 1)
	{
		printCard(card);
		std::printf("Для сортировки необходимо чтобы книг было больше 1!\n");
		return;
	}
	while (true)
	{
		char *otherBy = new char[1000];
		std::printf(
			"Перечислите через запятую названия колонок (кроме '%s') по которым будет производиться сортировка \n"
			"Например %s %s,%s %s,%s %s (%s можно не писать): ",
			COLUMN_INDEX_TITLE,
			COLUMN_AUTHOR_FIRST_NAME_TITLE, SORT_DESC,
			COLUMN_AUTHOR_LAST_NAME_TITLE, SORT_ASC,
			COLUMN_BOOK_YEAR_TITLE, SORT_DESC,
			SORT_ASC);
		std::cin.getline(otherBy, 1000);
		std::cin.clear();
		if (strcmp(otherBy, "") == 0)
		{
			std::printf("Перечисление не может быть пустым!\n");
			bool isContinue = false;
			while (true)
			{
				char *command = new char[10];
				std::printf("Желаете продолжить? [y/N]: ");
				std::cin.getline(command, 10);
				std::cin.clear();
				if (strcmp(command, "Y") == 0 || strcmp(command, "y") == 0)
				{
					isContinue = true;
					break;
				}
				else if (strcmp(command, "") == 0 || strcmp(command, "n") == 0 || strcmp(command, "N") == 0)
				{
					return;
				}
			}
			if (isContinue)
			{
				continue;
			}
		}
		if (!parseCardSortString(card, otherBy))
		{
			continue;
		}

		printSortMap(card);

		sortCard(card);
		card->sortMap = new SortMap;
		printCard(card);

		while (true)
		{
			char *command = new char[10];
			std::printf("Желаете продолжить? [Y/n]: ");
			std::cin.getline(command, 10);
			std::cin.clear();
			if (strcmp(command, "") == 0 || strcmp(command, "Y") == 0 || strcmp(command, "y") == 0)
			{
				break;
			}
			else if (strcmp(command, "n") == 0 || strcmp(command, "N") == 0)
			{
				return;
			}
			continue;
		}
	}
}

bool parseCardSortString(Card *&card, const char *str)
{
	//std::printf("Start parseCardSortString\n");
	struct StringDinArr *splitString = split(str, ',');
	for (size_t i = 0; i < splitString->size; i++)
	{
		struct StringDinArr *colAndTypeOper = split(splitString->arr[i], ' ');
		//std::printf("Size: (%d)\n", colAndTypeOper->size);
		if (colAndTypeOper->size > 2)
		{
			std::printf("Не удалось распознать строку '%s'!\n", splitString->arr[i]);
			return false;
		}
		else if (colAndTypeOper->size == 2)
		{
			if (!validateColumnTitle(colAndTypeOper->arr[0]))
			{
				std::printf("Не удалось распознать название колонки '%s'!\n", colAndTypeOper->arr[0]);
				return false;
			}

			if (strcmp(colAndTypeOper->arr[1], SORT_DESC) == 0)
			{
				addToSortMap(card, colAndTypeOper->arr[0], true);
			}
			else if (strcmp(colAndTypeOper->arr[1], SORT_ASC) == 0)
			{
				addToSortMap(card, colAndTypeOper->arr[0], false);
			}
			else
			{
				std::printf("Не удалось распознать тип сортироваки '%s'!\n", colAndTypeOper->arr[1]);
				return false;
			}
		}
		else
		{
			if (!validateColumnTitle(colAndTypeOper->arr[0]))
			{
				std::printf("Не удалось распознать название колонки '%s'!\n", colAndTypeOper->arr[0]);
				return false;
			}
			addToSortMap(card, colAndTypeOper->arr[0], false);
		}
	}
	//std::printf("Finish parseCardSortString\n");
	return true;
}

void addToSortMap(Card *&card, char *columnName, bool isDesc)
{
	for (size_t i = 0; i < card->sortMap->size; i++)
	{
		if (strcmp(card->sortMap->arr[i]->columnName, columnName) == 0)
		{
			card->sortMap->arr[i]->isDesc = isDesc;
			return;
		}
	}
	SortMapItem *item = new SortMapItem;
	item->columnName = columnName;
	item->isDesc = isDesc;
	card->sortMap->arr[card->sortMap->size] = item;
	card->sortMap->size++;
}

void sortCard(Card *&card)
{
	//std::printf("Start sortCard: sortMapSize: %zu\n", card->sortMap->size);
	if (card->bookDinArr->size == 0)
	{
		std::printf("sortMapSize: mast be over 2: Have: %zu\n", card->sortMap->size);
		return;
	}

	const char *beginKey = card->sortMap->arr[0]->columnName;
	bool isDesc = card->sortMap->arr[0]->isDesc;
	for (int i = 0; i < card->bookDinArr->size - 1; i++)
	{
		struct BOOK *maxElement = card->bookDinArr->arr[i];
		size_t posMaxElem = i;
		for (int j = i + 1; j < card->bookDinArr->size; j++)
		{
			SortPair *cmpRes = cmpBookRecursive(card, posMaxElem, j, 0);
			//std::printf("Результат сравнения: '%d' \n", cmpRes->resCmp);

			if (cmpRes->resCmp == 0)
			{
				//std::printf("Книги равны\n");
				continue;
			}
			else if (cmpRes->resCmp > 0 && cmpRes->isDesc)
			{
				// DESC
				maxElement = card->bookDinArr->arr[j];
				posMaxElem = j;
			}
			else if (cmpRes->resCmp < 0 && !cmpRes->isDesc)
			{
				// ASC
				maxElement = card->bookDinArr->arr[j];
				posMaxElem = j;
			}
		}
		//std::printf("(i:%d;posMaxElem:%d)\n", i, posMaxElem);
		struct BOOK *bookBuf = card->bookDinArr->arr[i];
		card->bookDinArr->arr[i] = maxElement;
		card->bookDinArr->arr[posMaxElem] = bookBuf;
	}
	std::printf("Finish sortCard\n");
}

SortPair *cmpBookRecursive(
	Card *&card,
	const size_t firstSortIndex,
	const size_t secondSortIndex,
	const size_t sortIndex)
{
	//std::printf("Start cmpBookRecursive->%zu:%zu:%zu\n", firstSortIndex, secondSortIndex, sortIndex);
	struct SortPair *res = new SortPair;
	struct BOOK *firstBook = card->bookDinArr->arr[firstSortIndex];
	struct BOOK *secondBook = card->bookDinArr->arr[secondSortIndex];
	const char *key = card->sortMap->arr[sortIndex]->columnName;
	res->isDesc = card->sortMap->arr[sortIndex]->isDesc;
	if (strcmp(key, COLUMN_AUTHOR_FIRST_NAME_TITLE) == 0)
	{
		if (strcmp(secondBook->authorFirstName, firstBook->authorFirstName) == 0)
		{
			//std::printf("Значения имен равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < card->sortMap->size - 1)
			{
				newSortIndex++;
				return cmpBookRecursive(card, firstSortIndex, secondSortIndex, newSortIndex);
			}
			res->resCmp = 0;
			return res;
		}
		else if (strcmp(secondBook->authorFirstName, firstBook->authorFirstName) > 0)
		{
			res->resCmp = 1;
			return res;
		}
		else if (strcmp(secondBook->authorFirstName, firstBook->authorFirstName) < 0)
		{
			res->resCmp = -1;
			return res;
		}
	}
	else if (strcmp(key, COLUMN_AUTHOR_LAST_NAME_TITLE) == 0)
	{
		if (strcmp(secondBook->authorLastName, firstBook->authorLastName) == 0)
		{
			//std::printf("Значения фамилий равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < card->sortMap->size - 1)
			{
				newSortIndex++;
				return cmpBookRecursive(card, firstSortIndex, secondSortIndex, newSortIndex);
			}
			res->resCmp = 0;
			return res;
		}
		else if (strcmp(secondBook->authorLastName, firstBook->authorLastName) > 0)
		{
			res->resCmp = 1;
			return res;
		}
		else if (strcmp(secondBook->authorLastName, firstBook->authorLastName) < 0)
		{
			res->resCmp = -1;
			return res;
		}
	}
	else if (strcmp(key, COLUMN_BOOK_TITLE_TITLE) == 0)
	{
		if (strcmp(secondBook->bookTitle, firstBook->bookTitle) == 0)
		{
			//std::printf("Значения название книги равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < card->sortMap->size - 1)
			{
				newSortIndex++;
				return cmpBookRecursive(card, firstSortIndex, secondSortIndex, newSortIndex);
			}
			res->resCmp = 0;
			return res;
		}
		else if (strcmp(secondBook->bookTitle, firstBook->bookTitle) > 0)
		{
			res->resCmp = 1;
			return res;
		}
		else if (strcmp(secondBook->bookTitle, firstBook->bookTitle) < 0)
		{
			res->resCmp = -1;
			return res;
		}
	}
	else if (strcmp(key, COLUMN_BOOK_YEAR_TITLE) == 0)
	{
		if (secondBook->bookYear == firstBook->bookYear)
		{
			//std::printf("Значения даты выпуска книги равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < card->sortMap->size - 1)
			{
				newSortIndex++;
				return cmpBookRecursive(card, firstSortIndex, secondSortIndex, newSortIndex);
			}
			res->resCmp = 0;
			return res;
		}
		else if (secondBook->bookYear > firstBook->bookYear)
		{
			res->resCmp = 1;
			return res;
		}
		else if (secondBook->bookYear < firstBook->bookYear)
		{
			res->resCmp = -1;
			return res;
		}
	}
	else if (strcmp(key, COLUMN_BOOK_PRICE_TITLE) == 0)
	{
		if (secondBook->bookPrice == firstBook->bookPrice)
		{
			//std::printf("Значения стоимостей книги равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < card->sortMap->size - 1)
			{
				newSortIndex++;
				return cmpBookRecursive(card, firstSortIndex, secondSortIndex, newSortIndex);
			}
			res->resCmp = 0;
			return res;
		}
		else if (secondBook->bookPrice > firstBook->bookPrice)
		{
			res->resCmp = 1;
			return res;
		}
		else if (secondBook->bookPrice < firstBook->bookPrice)
		{
			res->resCmp = -1;
			return res;
		}
	}
	else if (strcmp(key, COLUMN_BOOK_CATEGORY_TITLE) == 0)
	{
		if (strcmp(getBookCategory(secondBook), getBookCategory(firstBook)) == 0)
		{
			//std::printf("Значения категорий равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < card->sortMap->size - 1)
			{
				newSortIndex++;
				return cmpBookRecursive(card, firstSortIndex, secondSortIndex, newSortIndex);
			}
			res->resCmp = 0;
			return res;
		}
		else if (strcmp(getBookCategory(secondBook), getBookCategory(firstBook)) > 0)
		{
			res->resCmp = 1;
			return res;
		}
		else if (strcmp(getBookCategory(secondBook), getBookCategory(firstBook)) < 0)
		{
			res->resCmp = -1;
			return res;
		}
	}
	res->resCmp = 0;
	//std::printf("Finish cmpBookRecursive\n");
	return res;
}
