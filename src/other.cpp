
#include "other.h"

void run()
{
	RectangleDLL *recDLL = new RectangleDLL;

	while (true)
	{
		std::string command;
		std::printf("$ ");

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
			readFromFile(recDLL);
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

std::string strSpaceWrap(std::string str)
{
	std::string res = " ";
	res += str;
	res += " ";
	return res;
}

void printRectangleDLL(RectangleDLL *&recDLL)
{
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
	size_t indexColumnSize = std::strlen(strSpaceWrap(COLUMN_INDEX_TITLE).c_str()),
		   widthColumnSize = std::strlen(strSpaceWrap(COLUMN_WIDTH_TITLE).c_str()),
		   heightColumnSize = std::strlen(strSpaceWrap(COLUMN_HEIGHT_TITLE).c_str()),
		   areaColumnSize = std::strlen(strSpaceWrap(COLUMN_AREA_TITLE).c_str());
	size_t i = 0;
	do
	{
		if (indexColumnSize < std::to_string(i).size())
		{
			indexColumnSize = std::to_string(i).size();
		}
		if (widthColumnSize < std::to_string(rectangle->width).size())
		{
			widthColumnSize = std::to_string(rectangle->width).size();
		}
		if (heightColumnSize < std::to_string(rectangle->height).size())
		{
			heightColumnSize = std::to_string(rectangle->height).size();
		}
		if (areaColumnSize < std::to_string(rectangle->area).size())
		{
			areaColumnSize = std::to_string(rectangle->area).size();
		}
		i++;

		rectangle = rectangle->nextRectangle;
		//std::printf("Titles: %zu : %zu : %d\n", i, this->size, rectangle != nullptr);
	} while (rectangle != nullptr);
	std::cout << alignCenter(COLUMN_INDEX_TITLE, indexColumnSize) << " | "
			  << alignCenter(COLUMN_WIDTH_TITLE, widthColumnSize) << " | "
			  << alignCenter(COLUMN_HEIGHT_TITLE, heightColumnSize) << " | "
			  << alignCenter(COLUMN_AREA_TITLE, areaColumnSize) << " |\n";
	size_t totalSize = indexColumnSize + widthColumnSize + heightColumnSize + areaColumnSize;
	totalSize += totalSize * 0.21;
	for (size_t i = 0; i <= totalSize; i++)
		std::cout << "—";
	std::cout << std::endl;
	rectangle = recDLL->firstRectangle;
	i = 0;
	do
	{
		std::cout << alignCenter(std::to_string(i), indexColumnSize) << " | "
				  << alignCenter(std::to_string(rectangle->width), widthColumnSize) << " | "
				  << alignCenter(std::to_string(rectangle->height), heightColumnSize) << " | "
				  << alignCenter(std::to_string(rectangle->area), areaColumnSize) << " |\n";
		i++;
		rectangle = rectangle->nextRectangle;
	} while (rectangle != nullptr);
}

void printRecVector(RectangleDLL *&recleDLL)
{
	size_t indexColumnSize = std::strlen(strSpaceWrap(COLUMN_INDEX_TITLE).c_str()),
		   widthColumnSize = std::strlen(strSpaceWrap(COLUMN_WIDTH_TITLE).c_str()),
		   heightColumnSize = std::strlen(strSpaceWrap(COLUMN_HEIGHT_TITLE).c_str()),
		   areaColumnSize = std::strlen(strSpaceWrap(COLUMN_AREA_TITLE).c_str());
	size_t i = 0;
	for (Rectangle rectangle : recleDLL->recVector)
	{
		if (indexColumnSize < std::to_string(i).size())
		{
			indexColumnSize = std::to_string(i).size();
		}
		if (widthColumnSize < std::to_string(rectangle.width).size())
		{
			widthColumnSize = std::to_string(rectangle.width).size();
		}
		if (heightColumnSize < std::to_string(rectangle.height).size())
		{
			heightColumnSize = std::to_string(rectangle.height).size();
		}
		if (areaColumnSize < std::to_string(rectangle.area).size())
		{
			areaColumnSize = std::to_string(rectangle.area).size();
		}
		i++;
	}
	std::cout << alignCenter(COLUMN_INDEX_TITLE, indexColumnSize) << " | "
			  << alignCenter(COLUMN_WIDTH_TITLE, widthColumnSize) << " | "
			  << alignCenter(COLUMN_HEIGHT_TITLE, heightColumnSize) << " | "
			  << alignCenter(COLUMN_AREA_TITLE, areaColumnSize) << " |\n";
	size_t totalSize = indexColumnSize + widthColumnSize + heightColumnSize + areaColumnSize;
	totalSize += totalSize * 0.21;
	for (size_t i = 0; i <= totalSize; i++)
		std::cout << "—";
	std::cout << std::endl;
	i = 0;
	for (Rectangle rectangle : recleDLL->recVector)
	{
		std::cout << alignCenter(std::to_string(i), indexColumnSize) << " | "
				  << alignCenter(std::to_string(rectangle.width), widthColumnSize) << " | "
				  << alignCenter(std::to_string(rectangle.height), heightColumnSize) << " | "
				  << alignCenter(std::to_string(rectangle.area), areaColumnSize) << " |\n";
		i++;
	}
}

void printSortMap(RectangleDLL *&recDLL)
{
	for (auto data = recDLL->sortMap.begin(); data != recDLL->sortMap.end(); ++data)
	{
		std::printf("Map: %s => %s\n", data->first.c_str(), data->second ? "true" : "false");
	}
}

void printSortVector(RectangleDLL *&recDLL)
{
	for (auto data = recDLL->sortVector.begin(); data != recDLL->sortVector.end(); ++data)
	{
		std::printf("Vector: %s\n", data->c_str());
	}
}

std::string alignCenter(const std::string s, const int w)
{
	std::stringstream ss, spaces;
	int padding = w - s.size();
	for (int i = 0; i < padding / 2; ++i)
		spaces << " ";
	ss << spaces.str() << s << spaces.str();
	if (padding > 0 && padding % 2 != 0)
		ss << " ";
	return ss.str();
}

std::string alignRight(const std::string s, const int w)
{
	std::stringstream ss, spaces;
	int padding = w - s.size();
	for (int i = 0; i < padding; ++i)
		spaces << " ";
	ss << spaces.str() << s;
	return ss.str();
}

std::string alignLeft(const std::string s, const int w)
{
	std::stringstream ss, spaces;
	int padding = w - s.size();
	for (int i = 0; i < padding; ++i)
		spaces << " ";
	ss << s << spaces.str();
	return ss.str();
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
	std::string command;
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
				command = "";
				std::printf("Желаете продолжить? [Y/n]: ");
				std::getline(std::cin, command);
				if (!command.compare("") || !command.compare("Y") || !command.compare("y"))
				{
					break;
				}
				else if (!command.compare("n") || !command.compare("N"))
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
			command = "";
			std::printf("Вы действительно хотите удалить этот прямоугольник из набора? [Y/n]: ");
			std::getline(std::cin, command);
			if (!command.compare("") || !command.compare("Y") || !command.compare("y"))
			{
				remove = true;
				break;
			}
			else if (!command.compare("n") || !command.compare("N"))
			{
				remove = false;
				break;
			}
			continue;
		}
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
			if (nextRectangle != NULL)
			{
				// переставляем указатель
				nextRectangle->prevRectangle = deleteRectangle->prevRectangle;
			}
			// освобождаем память удаляемого элемента
			free(deleteRectangle);
		}
		std::printf("Прямоугольник удален! \n");
		while (true)
		{
			command = "";
			std::printf("Желаете продолжить? [y/N]: ");
			std::getline(std::cin, command);
			if (!command.compare("Y") || !command.compare("y"))
			{
				break;
			}
			else if (!command.compare("") || !command.compare("n") || !command.compare("N"))
			{
				return;
			}
			continue;
		}
	}
}

void saveToFile(RectangleDLL *&recDLL)
{
	std::string saveData;
	Rectangle *rectangle = recDLL->firstRectangle;
	do
	{
		saveData += std::to_string(rectangle->width);
		saveData += ";";
		saveData += std::to_string(rectangle->height);
		saveData += ";";
		saveData += std::to_string(rectangle->area);
		saveData += "\n";
		rectangle = rectangle->nextRectangle;
	} while (rectangle != nullptr);
	//std::printf("%s", saveData.c_str());
	std::ofstream saveFile;
	while (true)
	{
		std::string pathToFile = "";
		std::printf("Введите путь к файлу [default:%s]: ", DEFAULT_PATH_TO_FILE.c_str());
		std::getline(std::cin, pathToFile);
		if (!pathToFile.compare(""))
		{
			pathToFile = DEFAULT_PATH_TO_FILE;
		}
		saveFile.open(pathToFile, std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (saveFile.is_open())
		{
			saveFile << saveData.c_str();
			saveFile.close();
			std::printf("Файл сохранен по поти: '%s'\n", pathToFile.c_str());
			return;
		}
		else
		{
			std::printf("Поток для записи в файл '%s' закрыт! \n", pathToFile.c_str());
			continue;
		}
		continue;
	}
}

void readFromFile(RectangleDLL *&recDLL)
{
	std::string readData;
	std::ifstream readFile;
	while (true)
	{
		std::string pathToFile = "";
		std::printf("Введите путь к файлу [default:%s]: ", DEFAULT_PATH_TO_FILE.c_str());
		std::getline(std::cin, pathToFile);
		if (!pathToFile.compare(""))
		{
			pathToFile = DEFAULT_PATH_TO_FILE;
		}
		readFile.open(pathToFile, std::fstream::out);
		if (readFile.is_open())
		{
			size_t i = 0;
			recDLL->recVector.clear();
			while (std::getline(readFile, readData))
			{
				if (!readData.compare(""))
				{
					continue;
				}
				//std::printf("%s\n", readData.c_str());
				std::vector<std::string> rectangleProps = split(readData, ';');
				if (rectangleProps.size() != 3)
				{
					std::printf("Строка %zu не соответствует требуемуму формату т.к."
								"число ее свойств (%zu) должно быть равно 3!\n %s\n",
								i, rectangleProps.size(), readData.c_str());
					continue;
				}

				Rectangle newRectangle;
				newRectangle.width = std::stof(rectangleProps[0].c_str());
				newRectangle.height = std::stof(rectangleProps[1].c_str());
				newRectangle.area = std::stof(rectangleProps[2].c_str());
				newRectangle.prevRectangle = nullptr;
				newRectangle.nextRectangle = nullptr;
				recDLL->recVector.push_back(newRectangle);
			}
			readFile.close();
			std::printf("Файл '%s' прочитан.\n", pathToFile.c_str());

			fillDoublyLinkedListFromRecVector(recDLL);
			recDLL->recVector.clear();
			printRectangleDLL(recDLL);
			return;
		}
		else
		{
			std::printf("Поток для чтения из файла '%s' закрыт! \n", pathToFile.c_str());
			return;
		}
		continue;
	}
}

std::vector<std::string> split(const std::string &s, const char sep)
{
	typedef std::string::const_iterator iter;
	std::vector<std::string> ret;
	iter i = s.begin();
	while (i != s.end())
	{
		i = std::find_if(i, s.end(), [sep](char c) -> bool {
			return sep != c;
		});
		iter j = std::find_if(i, s.end(), [sep](char c) -> bool {
			return sep == c;
		});
		if (i != s.end())
		{
			ret.push_back(std::string(i, j));
			i = j;
		}
	}
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

		//std::printf("Find rectangle with area: %f\n", findArea);
		RectangleDLL *res = new RectangleDLL;
		for (size_t i = 0; i < recDLL->recVector.size(); i++)
		{
			if (findArea == recDLL->recVector[i].area)
			{
				res->recVector.push_back(recDLL->recVector[i]);
			}
		}
		Rectangle *rectangle = recDLL->firstRectangle;
		do
		{
			if (rectangle->area == findArea)
			{
				res->recVector.push_back(*rectangle);
			}
			rectangle = rectangle->nextRectangle;
		} while (rectangle != nullptr);
		if (res->recVector.size() == 0)
		{
			std::printf("Ни одного прямоугольника с площадью %f не найдено.\n", findArea);
		}
		else
		{
			printRecVector(res);
		}

		while (true)
		{
			std::string command = "";
			std::printf("Желаете продолжить? [Y/n]: ");
			std::getline(std::cin, command);
			if (!command.compare("") | !command.compare("Y") || !command.compare("y"))
			{
				break;
			}
			else if (!command.compare("n") || !command.compare("N"))
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
		//this->print();
		printRectangleDLL(recDLL);
		std::printf("Для сортировки необходимо чтобы прямоугольников было больше 1!\n");
		return;
	}
	while (true)
	{
		std::string otherBy = "";
		std::printf(
			"Перечислите через запятую названия колонок (кроме '%s') по которым будет производиться сортировка \n"
			"Например %s %s,%s %s (%s можно не писать): ",
			COLUMN_INDEX_TITLE,
			COLUMN_WIDTH_TITLE, SORT_DESC.c_str(),
			COLUMN_AREA_TITLE, SORT_DESC.c_str(),
			SORT_ASC.c_str());
		std::getline(std::cin, otherBy);
		if (!otherBy.compare(""))
		{
			std::printf("Перечисление не может быть пустым!\n");
			bool isContinue = false;
			while (true)
			{
				std::string command = "";
				std::printf("Желаете продолжить? [y/N]: ");
				std::getline(std::cin, command);
				if (!command.compare("Y") || !command.compare("y"))
				{
					isContinue = true;
					break;
				}
				else if (!command.compare("") || !command.compare("n") || !command.compare("N"))
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

		fillRecVectorFromDoublyLinkedList(recDLL);
		//this->printSortMap();
		//this->printSortVector();

		sortRectangleDLL(recDLL);
		recDLL->sortMap.clear();
		recDLL->sortVector.clear();

		printRecVector(recDLL);
		fillDoublyLinkedListFromRecVector(recDLL);
		recDLL->recVector.clear();
		while (true)
		{
			std::string command = "";
			std::printf("Желаете продолжить? [Y/n]: ");
			std::getline(std::cin, command);
			if (!command.compare("") || !command.compare("Y") || !command.compare("y"))
			{
				break;
			}
			else if (!command.compare("n") || !command.compare("N"))
			{
				return;
			}
			continue;
		}
	}
}

void fillRecVectorFromDoublyLinkedList(RectangleDLL *&recDLL)
{
	recDLL->recVector.clear();
	Rectangle *rectangle = recDLL->firstRectangle, *nextRectangle;
	do
	{
		nextRectangle = rectangle->nextRectangle;
		if (rectangle == nullptr)
		{
			return;
		}
		rectangle->prevRectangle = nullptr;
		rectangle->nextRectangle = nullptr;
		recDLL->recVector.push_back(*rectangle);
		rectangle = nextRectangle;
	} while (rectangle != nullptr);
}

void fillDoublyLinkedListFromRecVector(RectangleDLL *&recDLL)
{
	//std::printf("Start fillDoublyLinkedListFromRecVector size: %zu\n", this->size);
	clearDLL(recDLL);
	Rectangle *newRectangle = nullptr;
	Rectangle *lastRectangle = nullptr;
	for (size_t i = 0; i < recDLL->recVector.size(); i++)
	{
		newRectangle = &recDLL->recVector[i];
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
	//std::printf("Finish fillDoublyLinkedListFromRecVector size: %zu\n", this->size);
}

bool parseRectangleSortString(RectangleDLL *&recDLL, const std::string str)
{
	std::vector<std::string> splitString = split(str, ',');
	for (size_t i = 0; i < splitString.size(); i++)
	{
		std::vector<std::string> colAndTypeOper = split(splitString[i], ' ');
		//std::printf("Size: (%d)\n", colAndTypeOper.size());
		if (colAndTypeOper.size() > 2)
		{
			std::printf("Не удалось распознать строку '%s'!\n", splitString[i].c_str());
			return false;
		}
		else if (colAndTypeOper.size() == 2)
		{
			if (!validateColumnTitle(colAndTypeOper[0].c_str()))
			{
				std::printf("Не удалось распознать название колонки '%s'!\n", colAndTypeOper[0].c_str());
				return false;
			}
			recDLL->sortMap[colAndTypeOper[0]] = false;
			recDLL->sortVector.push_back(colAndTypeOper[0]);
			if (!colAndTypeOper[1].compare(SORT_DESC))
			{
				recDLL->sortMap[colAndTypeOper[0]] = true;
			}
			else if (colAndTypeOper[1].compare(SORT_ASC))
			{
				std::printf("Не удалось распознать тип сортироваки '%s'!\n", colAndTypeOper[1].c_str());
				return false;
			}
		}
		else
		{
			if (!validateColumnTitle(colAndTypeOper[0].c_str()))
			{
				std::printf("Не удалось распознать название колонки '%s'!\n", colAndTypeOper[0].c_str());
				return false;
			}
			recDLL->sortMap[colAndTypeOper[0]] = false;
			recDLL->sortVector.push_back(colAndTypeOper[0]);
		}
	}
	return true;
}

void sortRectangleDLL(RectangleDLL *&recDLL)
{
	const std::string beginKey = recDLL->sortVector[0];
	for (size_t i = 0; i < recDLL->recVector.size() - 1; i++)
	{
		Rectangle maxElement = recDLL->recVector[i];
		bool isDesc = recDLL->sortMap[beginKey];
		size_t posMaxElem = i;
		for (size_t j = i + 1; j < recDLL->recVector.size(); j++)
		{
			std::pair<int, bool> cmpRes = cmpRectangleRecursive(recDLL, posMaxElem, j, 0);
			//std::printf("Результат сравнения: '%d' \n", cmpRes);
			//printRectangle(recDLL);

			if (cmpRes.first == 0)
			{
				//std::printf("Прямоугольники равны\n");
				continue;
			}
			else if (cmpRes.first > 0 && cmpRes.second)
			{
				// DESC
				maxElement = recDLL->recVector[j];
				posMaxElem = j;
			}
			else if (cmpRes.first < 0 && !cmpRes.second)
			{
				// ASC
				maxElement = recDLL->recVector[j];
				posMaxElem = j;
			}
		}
		//std::printf("(i:%d;posMaxElem:%d)\n", i, posMaxElem);
		Rectangle bookBuf = recDLL->recVector[i];
		recDLL->recVector[i] = maxElement;
		recDLL->recVector[posMaxElem] = bookBuf;
	}
}

std::pair<int, bool> cmpRectangleRecursive(
	RectangleDLL *&recDLL,
	const size_t firstVectorIndex,
	const size_t secondVectorIndex,
	const size_t sortIndex)
{
	std::pair<int, bool> res;
	Rectangle firstBook = recDLL->recVector[firstVectorIndex];
	Rectangle secondBook = recDLL->recVector[secondVectorIndex];
	const std::string key = recDLL->sortVector[sortIndex];
	res.second = recDLL->sortMap[key];
	if (!key.compare(COLUMN_WIDTH_TITLE))
	{
		if (secondBook.width == firstBook.width)
		{
			//std::printf("Значения ширин прямоугольников равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < recDLL->sortVector.size() - 1)
			{
				newSortIndex++;
				return cmpRectangleRecursive(recDLL, firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.width > firstBook.width)
		{
			res.first = 1;
			return res;
		}
		else if (secondBook.width < firstBook.width)
		{
			res.first = -1;
			return res;
		}
	}
	else if (!key.compare(COLUMN_HEIGHT_TITLE))
	{
		if (secondBook.height == firstBook.height)
		{
			//std::printf("Значения высот прямоугольников равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < recDLL->sortVector.size() - 1)
			{
				newSortIndex++;
				return cmpRectangleRecursive(recDLL, firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.height > firstBook.height)
		{
			res.first = 1;
			return res;
		}
		else if (secondBook.height < firstBook.height)
		{
			res.first = -1;
			return res;
		}
	}
	else if (!key.compare(COLUMN_AREA_TITLE))
	{
		if (secondBook.area == firstBook.area)
		{
			//std::printf("Значения площадей прямоугольников равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < recDLL->sortVector.size() - 1)
			{
				newSortIndex++;
				return cmpRectangleRecursive(recDLL, firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.area > firstBook.area)
		{
			res.first = 1;
			return res;
		}
		else if (secondBook.area < firstBook.area)
		{
			res.first = -1;
			return res;
		}
	}
	res.first = 0;
	return res;
}
