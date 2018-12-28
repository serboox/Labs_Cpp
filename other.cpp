
#include "other.h"

void run()
{
	RectangleSet recSet;
	while (true) {
		std::string command;
		std::printf("$ ");

		std::getline(std::cin, command);
		//std::printf("---%s----%d--\n", command.c_str(), command.length());

		if (!command.compare(COMMAND_HELP)) {
			std::printf(
				"%s  ����������� ���������� ������. \n"
				"%s  �������� ����� �������������. \n"
				"%s  ������� ������������(��). \n"
				"%s  �������� � ����. \n"
				"%s  ������� �� �����. \n"
				"%s  ����� �������������(�) ������� �������� ������������� ���������. \n"
				"%s  ���������� ������ �� ������ ��� ���������� �����. \n"
				"%s  ���������� ������ �������. \n"
				"%s  �����. \n",
				COMMAND_PRINT,
				COMMAND_ADD,
				COMMAND_DELETE,
				COMMAND_SAVE,
				COMMAND_LOAD,
				COMMAND_SEARCH,
				COMMAND_SORT,
				COMMAND_HELP,
				COMMAND_EXIT
			);
		}
		else if (!command.compare(COMMAND_PRINT)) {
			std::printf("C��������� ������ ���������������: \n\n");
			recSet.print();
			std::printf("\n");
		}
		else if (!command.compare(COMMAND_ADD)) {
			std::printf("�������� ����� �������������: \n\n");
			recSet.add();
		}
		else if (!command.compare(COMMAND_DELETE)) {
			std::printf("������� ������������(��): \n");
			recSet.deleteCards();
		}
		else if (!command.compare(COMMAND_SAVE)) {
			std::printf("�������� � ����: \n");
			recSet.saveToFile();
		}
		else if (!command.compare(COMMAND_LOAD)) {
			std::printf("������� �� �����: \n");
			recSet.readFromFile();
		}
		else if (!command.compare(COMMAND_SEARCH)) {
			std::printf("����� �������������(�) ������� �������� ������������� ���������: \n");
			recSet.search();
		}
		else if (!command.compare(COMMAND_SORT)) {
			std::printf("���������� ������ �� ������ ��� ���������� �����: \n");
			recSet.initSort();
		}
		else if (!command.compare(COMMAND_EXIT)) {
			break;
		}
		else {
			std::printf(
				"Command not be support. Please enter '%s' or '%s'.\n",
				COMMAND_HELP,
				COMMAND_EXIT
			);
		}

		command.clear();
		if (!command.compare(COMMAND_ENDL)) {
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

void RectangleSet::print()
{
	if (this->size <= 0) {
		std::printf("��� ����� ����. Size: %d\n", this->size);
		return;
	}
	size_t indexColumnSize = std::strlen(strSpaceWrap(COLUMN_INDEX_TITLE).c_str()),
		widthColumnSize = std::strlen(strSpaceWrap(COLUMN_WIDTH_TITLE).c_str()),
		heightColumnSize = std::strlen(strSpaceWrap(COLUMN_HEIGHT_TITLE).c_str()),
		areaColumnSize = std::strlen(strSpaceWrap(COLUMN_AREA_TITLE).c_str());
	size_t i = 0;
	for (Rectangle rectangle : this->recVector) {
		if (indexColumnSize < std::to_string(i).size()) {
			indexColumnSize = std::to_string(i).size();
		}
		if (widthColumnSize < std::to_string(rectangle.width).size()) {
			widthColumnSize = std::to_string(rectangle.width).size();
		}
		if (heightColumnSize < std::to_string(rectangle.height).size()) {
			heightColumnSize = std::to_string(rectangle.height).size();
		}
		if (areaColumnSize < std::to_string(rectangle.area).size()) {
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
		std::cout << "�";
	std::cout << std::endl;
	i = 0;
	Rectangle *rectangle = this->firstRectangle;
	do {
		std::cout << alignCenter(std::to_string(i), indexColumnSize) << " | "
			<< alignCenter(std::to_string(rectangle->width), widthColumnSize) << " | "
			<< alignCenter(std::to_string(rectangle->height), heightColumnSize) << " | "
			<< alignCenter(std::to_string(rectangle->area), areaColumnSize) << " |\n";
		i++;
		rectangle = rectangle->nextRectangle;
	} while (rectangle != nullptr);
}

void RectangleSet::printRecVector()
{
	size_t indexColumnSize = std::strlen(strSpaceWrap(COLUMN_INDEX_TITLE).c_str()),
		widthColumnSize = std::strlen(strSpaceWrap(COLUMN_WIDTH_TITLE).c_str()),
		heightColumnSize = std::strlen(strSpaceWrap(COLUMN_HEIGHT_TITLE).c_str()),
		areaColumnSize = std::strlen(strSpaceWrap(COLUMN_AREA_TITLE).c_str());
	size_t i = 0;
	for (Rectangle rectangle : this->recVector) {
		if (indexColumnSize < std::to_string(i).size()) {
			indexColumnSize = std::to_string(i).size();
		}
		if (widthColumnSize < std::to_string(rectangle.width).size()) {
			widthColumnSize = std::to_string(rectangle.width).size();
		}
		if (heightColumnSize < std::to_string(rectangle.height).size()) {
			heightColumnSize = std::to_string(rectangle.height).size();
		}
		if (areaColumnSize < std::to_string(rectangle.area).size()) {
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
		std::cout << "�";
	std::cout << std::endl;
	i = 0;
	for (Rectangle rectangle : this->recVector) {
		std::cout << alignCenter(std::to_string(i), indexColumnSize) << " | "
			<< alignCenter(std::to_string(rectangle.width), widthColumnSize) << " | "
			<< alignCenter(std::to_string(rectangle.height), heightColumnSize) << " | "
			<< alignCenter(std::to_string(rectangle.area), areaColumnSize) << " |\n";
		i++;
	}
}

void RectangleSet::printSortMap()
{
	for (auto data = this->sortMap.begin(); data != this->sortMap.end(); ++data) {
		std::printf("Map: %s => %s\n", data->first.c_str(), data->second ? "true" : "false");
	}
}

void RectangleSet::printSortVector()
{
	for (auto data = this->sortVector.begin(); data != this->sortVector.end(); ++data) {
		std::printf("Vector: %s\n", data->c_str());
	}
}

std::string alignCenter(const std::string s, const int w) {
	std::stringstream ss, spaces;
	int padding = w - s.size();
	for (int i = 0; i < padding / 2; ++i)
		spaces << " ";
	ss << spaces.str() << s << spaces.str();
	if (padding > 0 && padding % 2 != 0)
		ss << " ";
	return ss.str();
}

std::string alignRight(const std::string s, const int w) {
	std::stringstream ss, spaces;
	int padding = w - s.size();
	for (int i = 0; i < padding; ++i)
		spaces << " ";
	ss << spaces.str() << s;
	return ss.str();
}

std::string alignLeft(const std::string s, const int w) {
	std::stringstream ss, spaces;
	int padding = w - s.size();
	for (int i = 0; i < padding; ++i)
		spaces << " ";
	ss << s << spaces.str();
	return ss.str();
}

void RectangleSet::add()
{
	Rectangle *newRectangle;
	newRectangle = (struct Rectangle*)malloc(sizeof(struct Rectangle));
	newRectangle->fillFromStdIn();
	if (this->firstRectangle == nullptr) {

		this->firstRectangle = newRectangle;
		this->lastRectangle = newRectangle;
	}
	else {
		newRectangle->prevRectangle = this->lastRectangle;
		this->lastRectangle->nextRectangle = newRectangle;
		this->lastRectangle = newRectangle;
	}
	++this->size;
}

void RectangleSet::deleteCards()
{
	std::string command;
	while (true) {
		if (this->size <= 0) {
			std::printf("��� ����� ����. Size: %d\n", this->size);
			return;
		}

		int i;
		size_t firstIndex = 0,
			lastIndex = this->size - 1;
		std::printf("���������� ������� Index ���������� �������������� (�� %d �� %d): ", firstIndex, lastIndex);
		std::scanf("%d", &i);
		std::cin.ignore();

		if (i < firstIndex || i > lastIndex) {
			std::printf("������ �������������� �� ����������! \n");
			while (true) {
				command = "";
				std::printf("������� ����������? [Y/n]: ");
				std::getline(std::cin, command);
				if (!command.compare("") || !command.compare("Y") || !command.compare("y")) {
					break;
				}
				else if (!command.compare("n") || !command.compare("N")) {
					return;
				}
				continue;
			}
			continue;
		}

		Rectangle *deleteRectangle = this->searchFromIndex(i);
		deleteRectangle->print();
		bool remove = false;
		while (true) {
			command = "";
			std::printf("�� ������������� ������ ������� ���� ������������� �� ������? [Y/n]: ");
			std::getline(std::cin, command);
			if (!command.compare("") || !command.compare("Y") || !command.compare("y")) {
				remove = true;
				break;
			}
			else if (!command.compare("n") || !command.compare("N")) {
				remove = false;
				break;
			}
			continue;
		}
		if (remove) {
			//this->recVector.erase(this->recVector.begin() + i);
			Rectangle *prevRectangle, *nextRectangle;
			prevRectangle = deleteRectangle->prevRectangle;
			nextRectangle = deleteRectangle->nextRectangle;
			if (prevRectangle != NULL) {
				// ������������ ���������
				prevRectangle->nextRectangle = deleteRectangle->nextRectangle;
			}
			if (nextRectangle != NULL) {
				// ������������ ���������
				nextRectangle->prevRectangle = deleteRectangle->prevRectangle;
			}
			// ����������� ������ ���������� ��������
			free(deleteRectangle);
		}
		std::printf("������������� ������! \n");
		while (true) {
			command = "";
			std::printf("������� ����������? [y/N]: ");
			std::getline(std::cin, command);
			if (!command.compare("Y") || !command.compare("y")) {
				break;
			}
			else if (!command.compare("") || !command.compare("n") || !command.compare("N")) {
				return;
			}
			continue;
		}
	}
}

void RectangleSet::saveToFile()
{
	std::string saveData;
	Rectangle *rectangle = this->firstRectangle;
	do {
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
	while (true) {
		std::string pathToFile = "";
		std::printf("������� ���� � ����� [default:%s]: ", DEFAULT_PATH_TO_FILE.c_str());
		std::getline(std::cin, pathToFile);
		if (!pathToFile.compare("")) {
			pathToFile = DEFAULT_PATH_TO_FILE;
		}
		saveFile.open(pathToFile, std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (saveFile.is_open()) {
			saveFile << saveData.c_str();
			saveFile.close();
			std::printf("���� �������� �� ����: '%s'\n", pathToFile.c_str());
			return;
		}
		else {
			std::printf("����� ��� ������ � ���� '%s' ������! \n", pathToFile.c_str());
			continue;
		}
		continue;
	}
}

void RectangleSet::readFromFile()
{
	std::string readData;
	std::ifstream readFile;
	while (true) {
		std::string pathToFile = "";
		std::printf("������� ���� � ����� [default:%s]: ", DEFAULT_PATH_TO_FILE.c_str());
		std::getline(std::cin, pathToFile);
		if (!pathToFile.compare("")) {
			pathToFile = DEFAULT_PATH_TO_FILE;
		}
		readFile.open(pathToFile, std::fstream::out);
		if (readFile.is_open()) {
			size_t i = 0;
			this->clear();
			while (std::getline(readFile, readData)) {
				if (!readData.compare("")) {
					continue;
				}
				//std::printf("%s\n", readData.c_str());
				std::vector<std::string> rectangleProps = split(readData, ';');
				if (rectangleProps.size() != 3) {
					std::printf("������ %d �� ������������� ���������� ������� �.�."
						"����� �� ������� (%d) ������ ���� ����� 3!\n %s\n",
						i, rectangleProps.size(), readData.c_str());
					continue;
				}

				Rectangle *newRectangle;
				newRectangle = (struct Rectangle*)malloc(sizeof(struct Rectangle));
				newRectangle->width = std::stof(rectangleProps[0].c_str());
				newRectangle->height = std::stof(rectangleProps[1].c_str());
				newRectangle->area = std::stof(rectangleProps[2].c_str());
				if (this->firstRectangle == nullptr) {

					this->firstRectangle = newRectangle;
					this->lastRectangle = newRectangle;
				}
				else {
					newRectangle->prevRectangle = this->lastRectangle;
					this->lastRectangle->nextRectangle = newRectangle;
					this->lastRectangle = newRectangle;
				}
				++this->size;
			}
			readFile.close();
			std::printf("���� '%s' ��������.\n", pathToFile.c_str());

			this->print();
			return;
		}
		else {
			std::printf("����� ��� ������ �� ����� '%s' ������! \n", pathToFile.c_str());
			return;
		}
		continue;
	}
}

std::vector<std::string> split(const std::string& s, const char sep) {
	typedef std::string::const_iterator iter;
	std::vector<std::string> ret;
	iter i = s.begin();
	while (i != s.end()) {
		i = std::find_if(i, s.end(), [sep](char c) -> bool {
			return sep != c;
		});
		iter j = std::find_if(i, s.end(), [sep](char c) -> bool {
			return sep == c;
		});
		if (i != s.end()) {
			ret.push_back(std::string(i, j));
			i = j;
		}
	}
	return ret;
}

void RectangleSet::search()
{
	float findArea;
	while (true) {
		if (this->size <= 0) {
			std::printf("��� ����� ����. Size: %d\n", this->size);
			return;
		}

		std::printf("������� ������� �������������� ������� ����� �����: ");
		std::scanf("%f", &findArea);
		std::cin.ignore();

		//std::printf("Find rectangle with area: %f\n", findArea);
		RectangleSet res;
		for (size_t i = 0; i < this->recVector.size(); i++) {
			if (findArea == this->recVector[i].area) {
				res.recVector.push_back(this->recVector[i]);
			}
		}
		Rectangle *rectangle = this->firstRectangle;
		do {
			if (rectangle->area == findArea) {
				res.recVector.push_back(*rectangle);
			}
			rectangle = rectangle->nextRectangle;
		} while (rectangle != nullptr);
		if (res.recVector.size() == 0) {
			std::printf("�� ������ �������������� � �������� %f �� �������.\n", findArea);
		}
		else {
			res.printRecVector();
		}

		while (true) {
			std::string command = "";
			std::printf("������� ����������? [Y/n]: ");
			std::getline(std::cin, command);
			if (!command.compare("") | !command.compare("Y") || !command.compare("y")) {
				break;
			}
			else if (!command.compare("n") || !command.compare("N")) {
				return;
			}
			continue;
		}
	}
}

Rectangle *RectangleSet::searchFromIndex(size_t index)
{
	size_t i = 0;
	Rectangle *rectangle = this->firstRectangle;
	do {
		if (index == i) {
			return rectangle;
		}
		i++;
		rectangle = rectangle->nextRectangle;
	} while (rectangle != nullptr);
	return nullptr;
}

void RectangleSet::clear()
{
    if (this->size == 0) {
        return;
    }
	Rectangle *rectangle = this->firstRectangle;
	do {
		Rectangle *curRectangle = rectangle;
		rectangle = rectangle->nextRectangle;
		free(curRectangle);
	} while (rectangle != nullptr);
	this->firstRectangle = nullptr;
	this->lastRectangle = nullptr;
	this->size = 0;
}

void RectangleSet::initSort()
{
	if (this->size <= 1) {
		this->print();
		std::printf("��� ���������� ���������� ����� ��������������� ���� ������ 1!\n");
		return;
	}
	while (true) {
		std::string otherBy = "";
		std::printf(
			"����������� ����� ������� �������� ������� (����� '%s') �� ������� ����� ������������� ���������� \n"
			"�������� %s %s,%s %s (%s ����� �� ������): ",
			COLUMN_INDEX_TITLE.c_str(),
			COLUMN_WIDTH_TITLE.c_str(), SORT_DESC.c_str(),
			COLUMN_AREA_TITLE.c_str(), SORT_DESC.c_str(),
			SORT_ASC.c_str());
		std::getline(std::cin, otherBy);
		if (!otherBy.compare("")) {
			std::printf("������������ �� ����� ���� ������!\n");
			bool isContinue = false;
			while (true) {
				std::string command = "";
				std::printf("������� ����������? [y/N]: ");
				std::getline(std::cin, command);
				if (!command.compare("Y") || !command.compare("y")) {
					isContinue = true;
					break;
				}
				else if (!command.compare("") || !command.compare("n") || !command.compare("N")) {
					return;
				}
			}
			if (isContinue) {
				continue;
			}
		}
		if (!this->parseSortString(otherBy)) {
			continue;
		}

		this->fillRecVectorFromDoublyLinkedList();
		//this->printSortMap();
		//this->printSortVector();

		this->sortBook();
		this->sortMap.clear();
		this->sortVector.clear();

		this->printRecVector();
		//this->fillDoublyLinkedListFromRecVector();
		this->recVector.clear();
		while (true) {
			std::string command = "";
			std::printf("������� ����������? [Y/n]: ");
			std::getline(std::cin, command);
			if (!command.compare("") || !command.compare("Y") || !command.compare("y")) {
				break;
			}
			else if (!command.compare("n") || !command.compare("N")) {
				return;
			}
			continue;
		}
	}
}

void RectangleSet::fillRecVectorFromDoublyLinkedList()
{
	//std::printf("fillRecVectorFromDoublyLinkedList\n");
	this->recVector.clear();
	Rectangle *rectangle = this->firstRectangle;
	do {
		this->recVector.push_back(*rectangle);
		rectangle = rectangle->nextRectangle;
	} while (rectangle != nullptr);
}

void RectangleSet::fillDoublyLinkedListFromRecVector()
{
	std::printf("fillDoublyLinkedListFromRecVector\n");
	this->clear();
	//Rectangle *rectangle = this->firstRectangle;
	//do {
	//	if (rectangle == nullptr) {
	//		break;
	//	}
	//	std::printf("%f %f %f\n", rectangle->width, rectangle->height, rectangle->area);
	//	rectangle = rectangle->nextRectangle;
	//} while (rectangle != nullptr);
	//return;

	this->printRecVector();

	size_t i = 0;
	for(Rectangle rec : this->recVector) {

		std::printf("Start: %d\n", this->size);
		rec.print();

		Rectangle *newRectangle = &rec;
		//newRectangle = (struct Rectangle*)malloc(sizeof(struct Rectangle));
		newRectangle->prevRectangle = nullptr;
		newRectangle->nextRectangle = nullptr;
		if (this->firstRectangle == nullptr) {
			std::printf("Set first rectangle: \n");

			this->firstRectangle = newRectangle;
			this->lastRectangle = newRectangle;
		} else {
			std::printf("Set next rectangle: \n");
			newRectangle->prevRectangle = this->lastRectangle;
			this->lastRectangle->nextRectangle = newRectangle;
			this->lastRectangle = newRectangle;
		}
		++this->size;

		std::printf("Finish: %d\n", this->size);
		std::printf("Vector size: %d\n", this->size);
		this->recVector.size();
		this->print();
		if (this->size > 3) {
			return;
		}
	}
}

bool RectangleSet::parseSortString(const std::string str)
{
	std::vector<std::string> splitString = split(str, ',');
	for (size_t i = 0; i < splitString.size(); i++) {
		std::vector<std::string> colAndTypeOper = split(splitString[i], ' ');
		//std::printf("Size: (%d)\n", colAndTypeOper.size());
		if (colAndTypeOper.size() > 2) {
			std::printf("�� ������� ���������� ������ '%s'!\n", splitString[i].c_str());
			return false;
		}
		else if (colAndTypeOper.size() == 2) {
			if (!validateColumnTitle(colAndTypeOper[0])) {
				std::printf("�� ������� ���������� �������� ������� '%s'!\n", colAndTypeOper[0].c_str());
				return false;
			}
			this->sortMap[colAndTypeOper[0]] = false;
			this->sortVector.push_back(colAndTypeOper[0]);
			if (!colAndTypeOper[1].compare(SORT_DESC)) {
				this->sortMap[colAndTypeOper[0]] = true;
			}
			else if (colAndTypeOper[1].compare(SORT_ASC)) {
				std::printf("�� ������� ���������� ��� ����������� '%s'!\n", colAndTypeOper[1].c_str());
				return false;
			}
		}
		else {
			if (!validateColumnTitle(colAndTypeOper[0])) {
				std::printf("�� ������� ���������� �������� ������� '%s'!\n", colAndTypeOper[0].c_str());
				return false;
			}
			this->sortMap[colAndTypeOper[0]] = false;
			this->sortVector.push_back(colAndTypeOper[0]);
		}
	}
	return true;
}

void RectangleSet::sortBook()
{
	const std::string beginKey = sortVector[0];
	for (size_t i = 0; i < this->recVector.size() - 1; i++) {
		Rectangle maxElement = this->recVector[i];
		bool isDesc = this->sortMap[beginKey];
		size_t posMaxElem = i;
		for (size_t j = i + 1; j < this->recVector.size(); j++) {
			std::pair<int, bool> cmpRes = this->cmpRectangleRecursive(posMaxElem, j, 0);
			//std::printf("��������� ���������: '%d' \n", cmpRes);
			//this->print();

			if (cmpRes.first == 0) {
				//std::printf("�������������� �����\n");
				continue;
			}
			else if (cmpRes.first > 0 && cmpRes.second) {
				// DESC
				maxElement = this->recVector[j];
				posMaxElem = j;
			}
			else if (cmpRes.first < 0 && !cmpRes.second) {
				// ASC
				maxElement = this->recVector[j];
				posMaxElem = j;
			}
		}
		//std::printf("(i:%d;posMaxElem:%d)\n", i, posMaxElem);
		Rectangle bookBuf = this->recVector[i];
		this->recVector[i] = maxElement;
		this->recVector[posMaxElem] = bookBuf;
	}
}

std::pair<int, bool> RectangleSet::cmpRectangleRecursive(const size_t firstVectorIndex, const size_t secondVectorIndex, const size_t sortIndex)
{
	std::pair<int, bool> res;
	Rectangle firstBook = this->recVector[firstVectorIndex];
	Rectangle secondBook = this->recVector[secondVectorIndex];
	const std::string key = sortVector[sortIndex];
	res.second = this->sortMap[key];
	if (!key.compare(COLUMN_WIDTH_TITLE.c_str())) {
		if (secondBook.width == firstBook.width) {
			//std::printf("�������� ����� ��������������� �����\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < this->sortVector.size() - 1) {
				newSortIndex++;
				return this->cmpRectangleRecursive(firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.width > firstBook.width) {
			res.first = 1;
			return res;
		}
		else if (secondBook.width < firstBook.width) {
			res.first = -1;
			return res;
		}
	}
	else if (!key.compare(COLUMN_HEIGHT_TITLE.c_str())) {
		if (secondBook.height == firstBook.height) {
			//std::printf("�������� ����� ��������������� �����\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < this->sortVector.size() - 1) {
				newSortIndex++;
				return this->cmpRectangleRecursive(firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.height > firstBook.height) {
			res.first = 1;
			return res;
		}
		else if (secondBook.height < firstBook.height) {
			res.first = -1;
			return res;
		}
	}
	else if (!key.compare(COLUMN_AREA_TITLE.c_str())) {
		if (secondBook.area == firstBook.area) {
			//std::printf("�������� �������� ��������������� �����\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < this->sortVector.size() - 1) {
				newSortIndex++;
				return this->cmpRectangleRecursive(firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.area > firstBook.area) {
			res.first = 1;
			return res;
		}
		else if (secondBook.area < firstBook.area) {
			res.first = -1;
			return res;
		}
	}
	res.first = 0;
	return res;
}
