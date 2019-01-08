
#include "other.h"

void run()
{
	RectangleDLL *recDLL = new RectangleDLL;

	while (true)
	{
		std::string command;
		std::printf("$ ");

		std::cin.clear();
		std::getline(std::cin, command);
		//std::printf("---%s----%d--\n", command.c_str(), command.length());

		if (!command.compare(COMMAND_HELP))
		{
			std::printf(
				"%s  Распечатать содержимое набора. \n"
				"%s  Добавить новый прямоугольник. \n"
				"%s  Удалить существующий(ие). \n"
				"%s  Записать в файл. \n"
				"%s  Считать из файла. \n"
				"%s  Найти прямоугольник(и) площадь которого соответствует значениею. \n"
				"%s  Сортировки набора по одному или нескольким полям. \n"
				"%s  Отобразить список комманд. \n"
				"%s  Выйти. \n",
				COMMAND_PRINT,
				COMMAND_ADD,
				COMMAND_DELETE,
				COMMAND_SAVE,
				COMMAND_LOAD,
				COMMAND_SEARCH,
				COMMAND_SORT,
				COMMAND_HELP,
				COMMAND_EXIT);
		}
		else if (!command.compare(COMMAND_PRINT))
		{
			std::printf("Cодержимое набора прямоугольников: \n\n");
			printRectangleDLL(recDLL);
			std::printf("\n");
		}
		else if (!command.compare(COMMAND_ADD))
		{
			std::printf("Добавить новый прямоугольник: \n\n");
			addRectangle(recDLL);
		}
		else if (!command.compare(COMMAND_DELETE))
		{
			std::printf("Удалить существующий(ие): \n");
			deleteRectangle(recDLL);
		}
		else if (!command.compare(COMMAND_SAVE))
		{
			std::printf("Записать в файл: \n");
			saveToFile(recDLL);
		}
		else if (!command.compare(COMMAND_LOAD))
		{
			std::printf("Считать из файла: \n");
			loadFromFile(recDLL);
		}
		else if (!command.compare(COMMAND_SEARCH))
		{
			std::printf("Найти прямоугольник(и) площадь которого соответствует значениею: \n");
			searchRectangle(recDLL);
		}
		else if (!command.compare(COMMAND_SORT))
		{
			std::printf("Сортировки набора по одному или нескольким полям: \n");
			initRectangleSort(recDLL);
		}
		else if (!command.compare(COMMAND_EXIT))
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

		command.clear();
		if (!command.compare(COMMAND_ENDL))
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

void printRectangleDLL(RectangleDLL *&recDLL)
{
	//std::printf("Start printRectangleDLL\n");
	if (recDLL->size <= 0)
	{
		std::printf("Ваш набор пуст. Size: %zu\n", recDLL->size);
		return;
	}
	Rectangle *rectangle = recDLL->firstRectangle;
	if (rectangle == nullptr)
	{
		std::printf("Ваш набор пуст. Size: %zu\n", recDLL->size);
		return;
	}
	size_t indexColumnSize = strlen(strSpaceWrap(COLUMN_INDEX_TITLE)),
		   widthColumnSize = strlen(strSpaceWrap(COLUMN_WIDTH_TITLE)),
		   heightColumnSize = strlen(strSpaceWrap(COLUMN_HEIGHT_TITLE)),
		   areaColumnSize = strlen(strSpaceWrap(COLUMN_AREA_TITLE));
	size_t i = 0;
	do
	{
		char *index = new char[indexColumnSize];
		sprintf(index, "%zu", i);
		char *width = new char[widthColumnSize];
		sprintf(width, "%f", rectangle->width);
		char *height = new char[heightColumnSize];
		sprintf(height, "%f", rectangle->height);
		char *area = new char[areaColumnSize];
		sprintf(area, "%f", rectangle->area);

		if (indexColumnSize < strlen(index))
		{
			indexColumnSize = strlen(index);
		}
		if (widthColumnSize < strlen(width))
		{
			widthColumnSize = strlen(width);
		}
		if (heightColumnSize < strlen(height))
		{
			heightColumnSize = strlen(height);
		}
		if (areaColumnSize < strlen(area))
		{
			areaColumnSize = strlen(area);
		}
		i++;

		rectangle = rectangle->nextRectangle;
		//std::printf("Titles: %zu : %zu : %d\n", i, recDLL->size, rectangle == nullptr);
	} while (rectangle != nullptr);
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	std::cout << alignCenter(COLUMN_INDEX_TITLE, indexColumnSize) << " | "
			  << alignCenter(COLUMN_WIDTH_TITLE, widthColumnSize) << " | "
			  << alignCenter(COLUMN_HEIGHT_TITLE, heightColumnSize) << " | "
			  << alignCenter(COLUMN_AREA_TITLE, areaColumnSize) << " |\n";
#else
	std::cout << alignCenter(COLUMN_INDEX_TITLE, indexColumnSize) << " | "
		<< alignCenter(COLUMN_WIDTH_TITLE, widthColumnSize + floor((float)strlen(COLUMN_WIDTH_TITLE) / 2)) << " | "
		<< alignCenter(COLUMN_HEIGHT_TITLE, heightColumnSize + floor((float)strlen(COLUMN_HEIGHT_TITLE) / 2)) << " | "
		<< alignCenter(COLUMN_AREA_TITLE, areaColumnSize + floor((float)strlen(COLUMN_AREA_TITLE) / 2)) << " |\n";
#endif
	size_t totalSize = indexColumnSize + widthColumnSize + heightColumnSize + areaColumnSize;
	totalSize += totalSize * 0.21;
	for (size_t i = 0; i <= totalSize; i++)
		std::cout << "—";
	std::cout << std::endl;
	rectangle = recDLL->firstRectangle;
	i = 0;
	do
	{
		char *index = new char[indexColumnSize];
		sprintf(index, "%zu", i);
		char *width = new char[widthColumnSize];
		sprintf(width, "%f", rectangle->width);
		char *height = new char[heightColumnSize];
		sprintf(height, "%f", rectangle->height);
		char *area = new char[areaColumnSize];
		sprintf(area, "%f", rectangle->area);

		std::cout
			<< alignCenter(index, indexColumnSize) << " | "
			<< alignCenter(width, widthColumnSize) << " | "
			<< alignCenter(height, heightColumnSize) << " | "
			<< alignCenter(area, areaColumnSize) << " |\n";
		i++;
		rectangle = rectangle->nextRectangle;
	} while (rectangle != nullptr);
	//std::printf("Finish printRectangleDLL\n");
}

void printRectangleDinArr(RectangleDLL *&recDLL)
{
	//std::printf("Start printRectangleDinArr\n");
	if (recDLL->recDinArr->size <= 0)
	{
		std::printf("Ваш набор пуст. Size: %zu\n", recDLL->recDinArr->size);
		return;
	}
	size_t indexColumnSize = strlen(strSpaceWrap(COLUMN_INDEX_TITLE)),
		   widthColumnSize = strlen(strSpaceWrap(COLUMN_WIDTH_TITLE)),
		   heightColumnSize = strlen(strSpaceWrap(COLUMN_HEIGHT_TITLE)),
		   areaColumnSize = strlen(strSpaceWrap(COLUMN_AREA_TITLE));
	for (size_t i = 0; i < recDLL->recDinArr->size; i++)
	{
		Rectangle *rectangle = recDLL->recDinArr->arr[i];
		char *index = new char[indexColumnSize];
		sprintf(index, "%zu", i);
		char *width = new char[widthColumnSize];
		sprintf(width, "%f", rectangle->width);
		char *height = new char[heightColumnSize];
		sprintf(height, "%f", rectangle->height);
		char *area = new char[areaColumnSize];
		sprintf(area, "%f", rectangle->area);

		if (indexColumnSize < strlen(index))
		{
			indexColumnSize = strlen(index);
		}
		if (widthColumnSize < strlen(width))
		{
			widthColumnSize = strlen(width);
		}
		if (heightColumnSize < strlen(height))
		{
			heightColumnSize = strlen(height);
		}
		if (areaColumnSize < strlen(area))
		{
			areaColumnSize = strlen(area);
		}
		i++;
	}
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	std::cout << alignCenter(COLUMN_INDEX_TITLE, indexColumnSize) << " | "
			  << alignCenter(COLUMN_WIDTH_TITLE, widthColumnSize) << " | "
			  << alignCenter(COLUMN_HEIGHT_TITLE, heightColumnSize) << " | "
			  << alignCenter(COLUMN_AREA_TITLE, areaColumnSize) << " |\n";
#else
	std::cout << alignCenter(COLUMN_INDEX_TITLE, indexColumnSize) << " | "
		<< alignCenter(COLUMN_WIDTH_TITLE, widthColumnSize + floor((float)strlen(COLUMN_WIDTH_TITLE) / 2)) << " | "
		<< alignCenter(COLUMN_HEIGHT_TITLE, heightColumnSize + floor((float)strlen(COLUMN_HEIGHT_TITLE) / 2)) << " | "
		<< alignCenter(COLUMN_AREA_TITLE, areaColumnSize + floor((float)strlen(COLUMN_AREA_TITLE) / 2)) << " |\n";
#endif
	size_t totalSize = indexColumnSize + widthColumnSize + heightColumnSize + areaColumnSize;
	totalSize += totalSize * 0.21;
	for (size_t i = 0; i <= totalSize; i++)
		std::cout << "—";
	std::cout << std::endl;
	for (size_t i = 0; i < recDLL->recDinArr->size; i++)
	{
		Rectangle *rectangle = recDLL->recDinArr->arr[i];
		char *index = new char[indexColumnSize];
		sprintf(index, "%zu", i);
		char *width = new char[widthColumnSize];
		sprintf(width, "%f", rectangle->width);
		char *height = new char[heightColumnSize];
		sprintf(height, "%f", rectangle->height);
		char *area = new char[areaColumnSize];
		sprintf(area, "%f", rectangle->area);

		std::cout
			<< alignCenter(index, indexColumnSize) << " | "
			<< alignCenter(width, widthColumnSize) << " | "
			<< alignCenter(height, heightColumnSize) << " | "
			<< alignCenter(area, areaColumnSize) << " |\n";
	}
	//std::printf("Finish printRectangleDinArr\n");
}

void printSortMap(RectangleDLL *&recDLL)
{
	for (size_t i = 0; i < recDLL->sortMap->size; i++)
	{
		SortMapItem *data = recDLL->sortMap->arr[i];
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
	char * res = new char[buff.str().length()+1];
	strcpy(res, buff.str().c_str());
	return res;
}

void addRectangle(RectangleDLL *&recDLL)
{
	Rectangle *newRectangle;
	newRectangle = (struct Rectangle *)malloc(sizeof(struct Rectangle));
	fillRectangleFromStdIn(newRectangle);
	if (recDLL->firstRectangle == nullptr)
	{

		recDLL->firstRectangle = newRectangle;
		recDLL->lastRectangle = newRectangle;
	}
	else
	{
		newRectangle->prevRectangle = recDLL->lastRectangle;
		recDLL->lastRectangle->nextRectangle = newRectangle;
		recDLL->lastRectangle = newRectangle;
	}
	++recDLL->size;
}

void deleteRectangle(RectangleDLL *&recDLL)
{
	char command[10];
	while (true)
	{
		if (recDLL->size <= 0)
		{
			std::printf("Ваш набор пуст. Size: %zu\n", recDLL->size);
			return;
		}

		int i;
		size_t firstIndex = 0,
			   lastIndex = recDLL->size - 1;
		std::printf("Пожалуйста введите Index удаляемого прямоугольника (от %zu до %zu): ", firstIndex, lastIndex);
		std::scanf("%d", &i);
		std::cin.ignore();

		if (i < firstIndex || i > lastIndex)
		{
			std::printf("Такого прямоугольника не существует! \n");
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

		Rectangle *deleteRectangle = searchRectangleFromIndex(recDLL, i);
		printRectangle(deleteRectangle);
		bool remove = false;
		while (true)
		{
			strcpy(command, "");
			std::printf("Вы действительно хотите удалить этот прямоугольник из набора? [Y/n]: ");
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
			//this->recVector.erase(this->recVector.begin() + i);
			Rectangle *prevRectangle, *nextRectangle;
			prevRectangle = deleteRectangle->prevRectangle;
			nextRectangle = deleteRectangle->nextRectangle;
			if (prevRectangle != NULL)
			{
				// переставляем указатель
				prevRectangle->nextRectangle = deleteRectangle->nextRectangle;
			}
			else
			{
				recDLL->firstRectangle = nextRectangle;
			}
			if (nextRectangle != NULL)
			{
				// переставляем указатель
				nextRectangle->prevRectangle = deleteRectangle->prevRectangle;
			}
			else
			{
				recDLL->lastRectangle = prevRectangle;
			}
			// освобождаем память удаляемого элемента
			free(deleteRectangle);

			std::printf("Прямоугольник удален! \n");
			recDLL->size--;
			if (recDLL->size == 0)
			{
				return;
			}
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

void saveToFile(RectangleDLL *&recDLL)
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
			Rectangle *rectangle = recDLL->firstRectangle;
			do
			{
				char *width = new char[64];
				sprintf(width, "%f", rectangle->width);
				char *height = new char[64];
				sprintf(height, "%f", rectangle->height);
				char *area = new char[64];
				sprintf(area, "%f", rectangle->area);

				saveFile << width;
				saveFile << ";";
				saveFile << height;
				saveFile << ";";
				saveFile << area;
				saveFile << "\n";
				rectangle = rectangle->nextRectangle;
			} while (rectangle != nullptr);
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

void loadFromFile(RectangleDLL *&recDLL)
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
			recDLL->recDinArr->size = 0;
			Rectangle **recArr = new Rectangle *[1];
			while (input.getline(readData, 1000))
			{
				if (strcmp(readData, "") == 0)
				{
					continue;
				}
				//std::printf("%s\n", readData);
				StringDinArr *rectangleProps = split(readData, ';');
				if (rectangleProps->size != 3)
				{
					std::printf("Строка %zu не соответствует требуемуму формату т.к."
								"число ее свойств (%zu) должно быть равно 3!\n %s\n",
								i, rectangleProps->size, readData);
					continue;
				}

				if (i != 0)
				{
					recArr = (Rectangle **)realloc(recArr, sizeof(struct Rectangle) * (i + 1));
				}
				Rectangle *newRectangle = new Rectangle;
				newRectangle->width = std::stof(rectangleProps->arr[0]);
				newRectangle->height = std::stof(rectangleProps->arr[1]);
				newRectangle->area = std::stof(rectangleProps->arr[2]);
				newRectangle->prevRectangle = nullptr;
				newRectangle->nextRectangle = nullptr;

				recArr[i] = newRectangle;
				i++;
				recDLL->recDinArr->size++;
			}
			recDLL->recDinArr->arr = recArr;
			input.close();
			std::printf("Файл '%s' прочитан.\n", pathToFile);

			fillDoublyLinkedListFromRecDinArray(recDLL);
			printRectangleDLL(recDLL);
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
			ret->arr[ret->size] = new char[buff.str().length()+1];
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

void searchRectangle(RectangleDLL *&recDLL)
{
	float findArea;
	while (true)
	{
		if (recDLL->size <= 0)
		{
			std::printf("Ваш набор пуст. Size: %zu\n", recDLL->size);
			return;
		}

		std::printf("Введите площадь прямоугольника который нужно найти: ");
		std::scanf("%f", &findArea);
		std::cin.ignore();

		std::printf("recDinArr size: %zu\n", recDLL->recDinArr->size);
		// Сбрасываем начальный размер массива
		if (recDLL->recDinArr->size != 0)
		{
			recDLL->recDinArr->size = 0;
		}
		Rectangle **recDinArr = new Rectangle *[recDLL->size];
		recDLL->recDinArr->arr = recDinArr;

		/* Находим совпавшие по площади прямоугольники и заносим
			их указатели во временный буфер */
		//std::printf("Find rectangle with area: %f\n", findArea);
		Rectangle *rectangle = recDLL->firstRectangle;
		do
		{
			if (rectangle->area == findArea)
			{
				recDLL->recDinArr->arr[recDLL->recDinArr->size] = rectangle;
				recDLL->recDinArr->size++;
			}
			rectangle = rectangle->nextRectangle;
		} while (rectangle != nullptr);
		if (recDLL->recDinArr->size == 0)
		{
			std::printf("Ни одного прямоугольника с площадью %f не найдено.\n", findArea);
		}
		else
		{
			// Печатаем результаты поиска на экран
			printRectangleDinArr(recDLL);
		}

		while (true)
		{
			char command[10];
			std::printf("Желаете продолжить? [Y/n]: ");
			std::cin.getline(command, 10);
			std::cin.clear();
			if (strcmp(command, "") == 0 | strcmp(command, "Y") == 0 || strcmp(command, "y") == 0)
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

Rectangle *searchRectangleFromIndex(RectangleDLL *&recDLL, size_t index)
{
	size_t i = 0;
	Rectangle *rectangle = recDLL->firstRectangle;
	do
	{
		if (index == i)
		{
			return rectangle;
		}
		i++;
		rectangle = rectangle->nextRectangle;
	} while (rectangle != nullptr);
	return nullptr;
}

void clearDLL(RectangleDLL *&recDLL)
{
	//std::printf("Start clear size %zu\n", this->size);
	if (recDLL->size == 0)
	{
		return;
	}
	if (recDLL->firstRectangle == nullptr)
	{
		return;
	}

	Rectangle *rectangle = recDLL->firstRectangle, *nextRectangle;
	do
	{
		nextRectangle = rectangle->nextRectangle;
		if (nextRectangle == nullptr)
		{
			break;
		}
		free(rectangle);
		rectangle = nextRectangle;
	} while (rectangle != nullptr);

	recDLL->firstRectangle = nullptr;
	recDLL->lastRectangle = nullptr;
	recDLL->size = 0;
	//std::printf("Finish clear size %zu\n", this->size);
}

void initRectangleSort(RectangleDLL *&recDLL)
{
	if (recDLL->size <= 1)
	{
		printRectangleDLL(recDLL);
		std::printf("Для сортировки необходимо чтобы прямоугольников было больше 1!\n");
		return;
	}
	while (true)
	{
		char *otherBy = new char[1000];
		std::printf(
			"Перечислите через запятую названия колонок (кроме '%s') по которым будет производиться сортировка \n"
			"Например %s %s,%s %s (%s можно не писать): ",
			COLUMN_INDEX_TITLE,
			COLUMN_WIDTH_TITLE, SORT_DESC,
			COLUMN_AREA_TITLE, SORT_DESC,
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
		if (!parseRectangleSortString(recDLL, otherBy))
		{
			continue;
		}

		//TODO::Вот тут лежит сердце сортировки

		fillRecDinArrayFromDoublyLinkedList(recDLL);
		//printSortMap(recDLL);
		//printRectangleDinArr(recDLL);

		sortRectangleDLL(recDLL);
		recDLL->sortMap = new SortMap;

		printRectangleDinArr(recDLL);
		fillDoublyLinkedListFromRecDinArray(recDLL);
		recDLL->recDinArr->size = 0;
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

void fillRecDinArrayFromDoublyLinkedList(RectangleDLL *&recDLL)
{
	recDLL->recDinArr->size = 0;
	recDLL->recDinArr->arr = new Rectangle *[recDLL->size];
	Rectangle *rectangle = recDLL->firstRectangle, *nextRectangle;
	size_t i = 0;
	do
	{
		nextRectangle = rectangle->nextRectangle;
		if (rectangle == nullptr)
		{
			return;
		}
		rectangle->prevRectangle = nullptr;
		rectangle->nextRectangle = nullptr;
		recDLL->recDinArr->arr[i] = rectangle;
		recDLL->recDinArr->size++;
		i++;
		rectangle = nextRectangle;
	} while (rectangle != nullptr);
}

void fillDoublyLinkedListFromRecDinArray(RectangleDLL *&recDLL)
{
	//std::printf("Start fillDoublyLinkedListFromRecDinArray size: %zu\n", recDLL->size);
	clearDLL(recDLL);
	Rectangle *newRectangle = nullptr;
	Rectangle *lastRectangle = nullptr;
	for (size_t i = 0; i < recDLL->recDinArr->size; i++)
	{
		newRectangle = recDLL->recDinArr->arr[i];
		newRectangle->prevRectangle = nullptr;
		newRectangle->nextRectangle = nullptr;
		if (recDLL->firstRectangle == nullptr)
		{
			recDLL->firstRectangle = newRectangle;
			recDLL->lastRectangle = newRectangle;
		}
		else
		{
			lastRectangle = recDLL->lastRectangle;
			newRectangle->prevRectangle = lastRectangle;
			lastRectangle->nextRectangle = newRectangle;
			recDLL->lastRectangle = nullptr;
			recDLL->lastRectangle = newRectangle;
		}
		++recDLL->size;
	}
	//std::printf("Finish fillDoublyLinkedListFromRecDinArray size: %zu\n", recDLL->size);
}

bool parseRectangleSortString(RectangleDLL *&recDLL, const char *str)
{
	//std::printf("Start parseRectangleSortString\n");
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
				addToSortMap(recDLL, colAndTypeOper->arr[0], true);
			}
			else if (strcmp(colAndTypeOper->arr[1], SORT_ASC) == 0)
			{
				addToSortMap(recDLL, colAndTypeOper->arr[0], false);
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
			addToSortMap(recDLL, colAndTypeOper->arr[0], false);
		}
	}
	//std::printf("Finish parseRectangleSortString\n");
	return true;
}

void addToSortMap(RectangleDLL *&recDLL, char *columnName, bool isDesc)
{
	for (size_t i = 0; i < recDLL->sortMap->size; i++)
	{
		if (strcmp(recDLL->sortMap->arr[i]->columnName, columnName) == 0)
		{
			recDLL->sortMap->arr[i]->isDesc = isDesc;
			return;
		}
	}
	SortMapItem *item = new SortMapItem;
	item->columnName = columnName;
	item->isDesc = isDesc;
	recDLL->sortMap->arr[recDLL->sortMap->size] = item;
	recDLL->sortMap->size++;
}

void sortRectangleDLL(RectangleDLL *&recDLL)
{
	//std::printf("Start sortRectangleDLL\n");
	const char *beginKey = recDLL->sortMap->arr[0]->columnName;
	bool isDesc = recDLL->sortMap->arr[0]->isDesc;
	for (size_t i = 0; i < recDLL->recDinArr->size - 1; i++)
	{
		Rectangle *maxElement = recDLL->recDinArr->arr[i];
		size_t posMaxElem = i;
		for (size_t j = i + 1; j < recDLL->recDinArr->size; j++)
		{
			SortPair *cmpRes = cmpRectangleRecursive(recDLL, posMaxElem, j, 0);
			//std::printf("Результат сравнения: '%d' \n", cmpRes);

			if (cmpRes->resCmp == 0)
			{
				//std::printf("Прямоугольники равны\n");
				continue;
			}
			else if (cmpRes->resCmp > 0 && cmpRes->isDesc)
			{
				// DESC
				maxElement = recDLL->recDinArr->arr[j];
				posMaxElem = j;
			}
			else if (cmpRes->resCmp < 0 && !cmpRes->isDesc)
			{
				// ASC
				maxElement = recDLL->recDinArr->arr[j];
				posMaxElem = j;
			}
		}
		//std::printf("(i:%d;posMaxElem:%d)\n", i, posMaxElem);
		Rectangle *bookBuf = recDLL->recDinArr->arr[i];
		recDLL->recDinArr->arr[i] = maxElement;
		recDLL->recDinArr->arr[posMaxElem] = bookBuf;
	}
	//std::printf("Finish sortRectangleDLL\n");
}

SortPair *cmpRectangleRecursive(
	RectangleDLL *&recDLL,
	const size_t firstSortIndex,
	const size_t secondSortIndex,
	const size_t sortIndex)
{
	//std::printf("Start cmpRectangleRecursive->%zu:%zu:%zu\n", firstSortIndex, secondSortIndex, sortIndex);
	SortPair *res = new SortPair;
	Rectangle *firstBook = recDLL->recDinArr->arr[firstSortIndex];
	Rectangle *secondBook = recDLL->recDinArr->arr[secondSortIndex];
	const char *key = recDLL->sortMap->arr[sortIndex]->columnName;
	res->isDesc = recDLL->sortMap->arr[sortIndex]->isDesc;
	if (strcmp(key, COLUMN_WIDTH_TITLE) == 0)
	{
		if (secondBook->width == firstBook->width)
		{
			//std::printf("Значения ширин прямоугольников равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < recDLL->sortMap->size - 1)
			{
				newSortIndex++;
				return cmpRectangleRecursive(recDLL, firstSortIndex, secondSortIndex, newSortIndex);
			}
			res->resCmp = 0;
			return res;
		}
		else if (secondBook->width > firstBook->width)
		{
			res->resCmp = 1;
			return res;
		}
		else if (secondBook->width < firstBook->width)
		{
			res->resCmp = -1;
			return res;
		}
	}
	else if (strcmp(key, COLUMN_HEIGHT_TITLE) == 0)
	{
		if (secondBook->height == firstBook->height)
		{
			//std::printf("Значения высот прямоугольников равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < recDLL->sortMap->size - 1)
			{
				newSortIndex++;
				return cmpRectangleRecursive(recDLL, firstSortIndex, secondSortIndex, newSortIndex);
			}
			res->resCmp = 0;
			return res;
		}
		else if (secondBook->height > firstBook->height)
		{
			res->resCmp = 1;
			return res;
		}
		else if (secondBook->height < firstBook->height)
		{
			res->resCmp = -1;
			return res;
		}
	}
	else if (strcmp(key, COLUMN_AREA_TITLE) == 0)
	{
		if (secondBook->area == firstBook->area)
		{
			//std::printf("Значения площадей прямоугольников равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < recDLL->sortMap->size - 1)
			{
				newSortIndex++;
				return cmpRectangleRecursive(recDLL, firstSortIndex, secondSortIndex, newSortIndex);
			}
			res->resCmp = 0;
			return res;
		}
		else if (secondBook->area > firstBook->area)
		{
			res->resCmp = 1;
			return res;
		}
		else if (secondBook->area < firstBook->area)
		{
			res->resCmp = -1;
			return res;
		}
	}
	res->resCmp = 0;
	//std::printf("Finish cmpRectangleRecursive\n");
	return res;
}
