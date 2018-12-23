
#include "book.h"
#include "other.h"

void run()
{
	Card card;
	while (true) {
		std::string command;
		std::printf("$ ");

		std::getline(std::cin, command);
		//std::printf("---%s----%d--\n", command.c_str(), command.length());

		if (!command.compare(COMMAND_HELP)) {
			std::printf(
				"%s  Распечатать содержимое картотеки. \n"
				"%s  Ввести новую книгу. \n"
				"%s  Удалить существующую(ие). \n"
				"%s  Записать текущее содержимое картотеки в файл. \n"
				"%s  Считать из файла содержимое в картотеку. \n"
				"%s  Сортировки массива по одному или нескольким полям. \n"
				"%s  Отобразить список комманд. \n"
				"%s  Выйти. \n",
				COMMAND_PRINT,
				COMMAND_ADD,
				COMMAND_DELETE,
				COMMAND_SAVE,
				COMMAND_LOAD,
				COMMAND_SORT,
				COMMAND_HELP,
				COMMAND_EXIT
			);
		}
		else if (!command.compare(COMMAND_PRINT)) {
			std::printf("Cодержимое картотеки: \n\n");
			card.print();
			std::printf("\n");
		}
		else if (!command.compare(COMMAND_ADD)) {
			std::printf("Ввести новую книгу: \n\n");
			card.add();
		}
		else if (!command.compare(COMMAND_DELETE)) {
			std::printf("Удалить существующую(ие): \n");
			card.deleteCards();
		}
		else if (!command.compare(COMMAND_SAVE)) {
			std::printf("Записать текущее содержимое картотеки в файл: \n");
			card.saveToFile();
		}
		else if (!command.compare(COMMAND_LOAD)) {
			std::printf("Считать из файла содержимое в картотеку: \n");
			card.readFromFile();
		}
		else if (!command.compare(COMMAND_SORT)) {
			std::printf("Сортировка массива по одному или нескольким полям: \n");
			card.initSort();
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

void Card::print()
{
	size_t indexColumnSize = std::strlen(strSpaceWrap(COLUMN_INDEX_TITLE).c_str()),
		authorFirstNameSize = std::strlen(strSpaceWrap(COLUMN_AUTHOR_FIRST_NAME_TITLE).c_str()),
		authorLastNameSize = std::strlen(strSpaceWrap(COLUMN_AUTHOR_LAST_NAME_TITLE).c_str()),
		bookTitleSize = std::strlen(strSpaceWrap(COLUMN_BOOK_TITLE_TITLE).c_str()),
		bookYearSize = std::strlen(strSpaceWrap(COLUMN_BOOK_YEAR_TITLE).c_str()),
		bookPriceSize = std::strlen(strSpaceWrap(COLUMN_BOOK_PRICE_TITLE).c_str()),
		bookCategorySize = std::strlen(strSpaceWrap(COLUMN_BOOK_CATEGORY_TITLE).c_str());
	size_t i = 0;
	for (BOOK book : this->bookVector) {
		if (indexColumnSize < std::to_string(i).size()) {
			indexColumnSize = std::to_string(i).size();
		}
		if (authorFirstNameSize < book.authorFirstName.size()) {
			authorFirstNameSize = book.authorFirstName.size();
		}
		if (authorLastNameSize < book.authorLastName.size()) {
			authorLastNameSize = book.authorLastName.size();
		}
		if (bookTitleSize < book.bookTitle.size()) {
			bookTitleSize = book.bookTitle.size();
		}
		if (bookYearSize < std::to_string(bookYearSize).size()) {
			bookYearSize = std::to_string(bookYearSize).size();
		}
		if (bookPriceSize < std::to_string(book.bookPrice).size()) {
			bookPriceSize = std::to_string(book.bookPrice).size();
		}
		if (bookCategorySize < book.getBookCategory().size()) {
			bookCategorySize = book.getBookCategory().size();
		}
		i++;
	}
	std::cout << alignCenter(COLUMN_INDEX_TITLE, indexColumnSize) << " | "
		<< alignCenter(COLUMN_AUTHOR_FIRST_NAME_TITLE, authorFirstNameSize) << " | "
		<< alignCenter(COLUMN_AUTHOR_LAST_NAME_TITLE, authorLastNameSize) << " | "
		<< alignCenter(COLUMN_BOOK_TITLE_TITLE, bookTitleSize) << " | "
		<< alignCenter(COLUMN_BOOK_YEAR_TITLE, bookYearSize) << " | "
		<< alignCenter(COLUMN_BOOK_PRICE_TITLE, bookPriceSize) << " | "
		<< alignCenter(COLUMN_BOOK_CATEGORY_TITLE, bookCategorySize) << " |\n";
	size_t totalSize = indexColumnSize + authorFirstNameSize + authorLastNameSize
		+ bookTitleSize + bookYearSize + bookPriceSize + bookCategorySize;
	totalSize += totalSize * 0.21;
	for (size_t i = 0; i <= totalSize; i++)
		std::cout << "—";
	std::cout << std::endl;
	i = 0;
	for (BOOK book : this->bookVector) {
		std::cout << alignCenter(std::to_string(i), indexColumnSize) << " | "
			<< alignCenter(book.authorFirstName, authorFirstNameSize) << " | "
			<< alignCenter(book.authorLastName, authorLastNameSize) << " | "
			<< alignCenter(book.bookTitle, bookTitleSize) << " | "
			<< alignCenter(std::to_string(book.bookYear), bookYearSize) << " | "
			<< alignCenter(std::to_string(book.bookPrice), bookPriceSize) << " | "
			<< alignCenter(book.getBookCategory().c_str(), bookCategorySize) << " |\n";
		i++;
	}
}

void Card::printSortMap()
{
	for (auto data = this->sortMap.begin(); data != this->sortMap.end(); ++data) {
		std::printf("Map: %s => %s\n", data->first.c_str(), data->second ? "true" : "false");
	}
}

void Card::printSortVector()
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

void Card::add()
{
	BOOK newBook;
	newBook.fillFromStdIn();
	this->bookVector.push_back(newBook);
}

void Card::deleteCards()
{
	std::string command;
	while (true) {
		if (this->bookVector.size() <= 0) {
			std::printf("Ваша картотека пуста. Size: %d\n", this->bookVector.size());
			return;
		}

		int i;
		size_t firstIndex = 0,
			lastIndex = this->bookVector.size() - 1;
		std::printf("Пожалуйста введите Index удаляемой книги (от %d до %d): ", firstIndex, lastIndex);
		std::scanf("%d", &i);
		std::cin.ignore();

		if (i < firstIndex || i > lastIndex) {
			std::printf("Такой книги не существует! \n");
			while (true) {
				command = "";
				std::printf("Желаете продолжить? [Y/n]: ");
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

		this->bookVector[i].print();
		bool remove = false;
		while (true) {
			command = "";
			std::printf("Вы действительно желаете удалить эту книгу из картотеки? [Y/n]: ");
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
			this->bookVector.erase(this->bookVector.begin() + i);
		}
		std::printf("Книга удалена! \n");
		while (true) {
			command = "";
			std::printf("Желаете продолжить? [y/N]: ");
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

void Card::saveToFile()
{
	std::string saveData;
	for (BOOK book : this->bookVector) {
		saveData += book.authorFirstName.c_str();
		saveData += ";";
		saveData += book.authorLastName.c_str();
		saveData += ";";
		saveData += book.bookTitle.c_str();
		saveData += ";";
		saveData += std::to_string(book.bookYear);
		saveData += ";";
		saveData += std::to_string(book.bookPrice);
		saveData += ";";
		saveData += book.getBookCategory().c_str();
		saveData += "\n";
	}
	//std::printf("%s", saveData.c_str());
	std::ofstream saveFile;
	while (true) {
		std::string pathToFile = "";
		std::printf("Введите полный путь к файлу [default:%s]: ", DEFAULT_PATH_TO_FILE.c_str());
		std::getline(std::cin, pathToFile);
		if (!pathToFile.compare("")) {
			pathToFile = DEFAULT_PATH_TO_FILE;
		}
		saveFile.open(pathToFile, std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (saveFile.is_open()) {
			saveFile << saveData.c_str();
			saveFile.close();
			std::printf("Файл сохранен по поти: '%s'\n", pathToFile.c_str());
			return;
		}
		else {
			std::printf("Поток для записи в файл '%s' закрыт! \n", pathToFile.c_str());
			continue;
		}
		continue;
	}
}

void Card::readFromFile()
{
	std::string readData;
	std::ifstream readFile;
	while (true) {
		std::string pathToFile = "";
		std::printf("Введите полный путь к файлу [default:%s]: ", DEFAULT_PATH_TO_FILE.c_str());
		std::getline(std::cin, pathToFile);
		if (!pathToFile.compare("")) {
			pathToFile = DEFAULT_PATH_TO_FILE;
		}
		readFile.open(pathToFile, std::fstream::out);
		if (readFile.is_open()) {
			size_t i = 0;
			this->bookVector.clear();
			while (std::getline(readFile, readData)) {
				if (!readData.compare("")) {
					continue;
				}
				//std::printf("%s\n", readData.c_str());
				std::vector<std::string> bookProps = split(readData, ';');
				if (bookProps.size() != 6) {
					std::printf("Строка %d не соответствует требуемуму формату т.к."
						"число ее свойств (%d) должно быть равно 6!\n %s\n",
						i, bookProps.size(), readData.c_str());
					continue;
				}

				BOOK newBook;
				newBook.authorFirstName.append(bookProps[0]);
				newBook.authorLastName.append(bookProps[1]);
				newBook.bookTitle.append(bookProps[2]);
				newBook.bookYear = static_cast<short int>(atoi(bookProps[3].c_str()));
				newBook.bookPrice = std::stof(bookProps[4].c_str());
				newBook.bookCategory = newBook.getBookCategory(bookProps[5]);
				this->bookVector.push_back(newBook);
			}
			readFile.close();
			std::printf("Файл '%s' прочитан.\n", pathToFile.c_str());

			this->print();

			return;
		}
		else {
			std::printf("Поток для чтения из файла '%s' закрыт! \n", pathToFile.c_str());
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

void Card::initSort()
{
	if (this->bookVector.size() == 1) {
		this->print();
		std::printf("Для сортировки необходимо чтобы книг было больше 1!\n");
		return;
	}
	while (true) {
		std::string otherBy = "";
		std::printf(
			"Перечислите через запятую названия колонок (кроме '%s') по которым будет производиться сортировка \n"
			"Например %s %s,%s %s,%s %s (%s можно не писать): ",
			COLUMN_INDEX_TITLE.c_str(),
			COLUMN_AUTHOR_FIRST_NAME_TITLE.c_str(), SORT_DESC.c_str(),
			COLUMN_AUTHOR_LAST_NAME_TITLE.c_str(), SORT_ASC.c_str(),
			COLUMN_BOOK_YEAR_TITLE.c_str(), SORT_DESC.c_str(),
			SORT_ASC.c_str());
		std::getline(std::cin, otherBy);
		if (!otherBy.compare("")) {
			std::printf("Перечисление не может быть пустым!\n");
			bool isContinue = false;
			while (true) {
				std::string command = "";
				std::printf("Желаете продолжить? [y/N]: ");
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

		//this->printSortMap();
		//this->printSortVector();
		this->sortBook();
		this->sortMap.clear();
		this->sortVector.clear();
		this->print();
		while (true) {
			std::string command = "";
			std::printf("Желаете продолжить? [Y/n]: ");
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

bool Card::parseSortString(const std::string str)
{
	std::vector<std::string> splitString = split(str, ',');
	for (size_t i = 0; i < splitString.size(); i++) {
		std::vector<std::string> colAndTypeOper = split(splitString[i], ' ');
		//std::printf("Size: (%d)\n", colAndTypeOper.size());
		if (colAndTypeOper.size() > 2) {
			std::printf("Не удалось распознать строку '%s'!\n", splitString[i].c_str());
			return false;
		}
		else if (colAndTypeOper.size() == 2) {
			if (!validateColumnTitle(colAndTypeOper[0])) {
				std::printf("Не удалось распознать название колонки '%s'!\n", colAndTypeOper[0].c_str());
				return false;
			}
			this->sortMap[colAndTypeOper[0]] = false;
			this->sortVector.push_back(colAndTypeOper[0]);
			if (!colAndTypeOper[1].compare(SORT_DESC)) {
				this->sortMap[colAndTypeOper[0]] = true;
			}
			else if (colAndTypeOper[1].compare(SORT_ASC)) {
				std::printf("Не удалось распознать тип сортироваки '%s'!\n", colAndTypeOper[1].c_str());
				return false;
			}
		}
		else {
			if (!validateColumnTitle(colAndTypeOper[0])) {
				std::printf("Не удалось распознать название колонки '%s'!\n", colAndTypeOper[0].c_str());
				return false;
			}
			this->sortMap[colAndTypeOper[0]] = false;
			this->sortVector.push_back(colAndTypeOper[0]);
		}
	}
	return true;
}

void Card::sortBook()
{
	const std::string beginKey = sortVector[0];
	for (size_t i = 0; i < this->bookVector.size() - 1; i++) {
		BOOK maxElement = this->bookVector[i];
		bool isDesc = this->sortMap[beginKey];
		size_t posMaxElem = i;
		for (size_t j = i + 1; j < this->bookVector.size(); j++) {
			std::pair<int, bool> cmpRes = this->cmpBookRecursive(posMaxElem, j, 0);
			//std::printf("Результат сравнения: '%d' \n", cmpRes);
			//this->print();

			if (cmpRes.first == 0) {
				//std::printf("Книги равны\n");
				continue;
			}
			else if (cmpRes.first > 0 && cmpRes.second) {
				// DESC
				maxElement = this->bookVector[j];
				posMaxElem = j;
			}
			else if (cmpRes.first < 0 && !cmpRes.second) {
				// ASC
				maxElement = this->bookVector[j];
				posMaxElem = j;
			}
		}
		//std::printf("(i:%d;posMaxElem:%d)\n", i, posMaxElem);
		BOOK bookBuf = this->bookVector[i];
		this->bookVector[i] = maxElement;
		this->bookVector[posMaxElem] = bookBuf;
	}
}

std::pair<int, bool> Card::cmpBookRecursive(const size_t firstVectorIndex, const size_t secondVectorIndex, const size_t sortIndex)
{
	std::pair<int, bool> res;
	BOOK firstBook = this->bookVector[firstVectorIndex];
	BOOK secondBook = this->bookVector[secondVectorIndex];
	const std::string key = sortVector[sortIndex];
	res.second =this->sortMap[key];
	if (!key.compare(COLUMN_AUTHOR_FIRST_NAME_TITLE.c_str())) {
		if (!secondBook.authorFirstName.compare(firstBook.authorFirstName.c_str())) {
			//std::printf("Значения имен равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < this->sortVector.size() - 1) {
				newSortIndex++;
				return this->cmpBookRecursive(firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.authorFirstName.compare(firstBook.authorFirstName.c_str()) > 0) {
			res.first = 1;
			return res;
		}
		else if (secondBook.authorFirstName.compare(firstBook.authorFirstName.c_str()) < 0) {
			res.first = -1;
			return res;
		}
	}
	else if (!key.compare(COLUMN_AUTHOR_LAST_NAME_TITLE.c_str())) {
		if (!secondBook.authorLastName.compare(firstBook.authorLastName.c_str())) {
			//std::printf("Значения фамилий равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < this->sortVector.size() - 1) {
				newSortIndex++;
				return this->cmpBookRecursive(firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.authorLastName.compare(firstBook.authorLastName.c_str()) > 0) {
			res.first = 1;
			return res;
		}
		else if (secondBook.authorLastName.compare(firstBook.authorLastName.c_str()) < 0) {
			res.first = -1;
			return res;
		}
	}
	else if (!key.compare(COLUMN_BOOK_TITLE_TITLE.c_str())) {
		if (!secondBook.bookTitle.compare(firstBook.bookTitle.c_str())) {
			//std::printf("Значения название книги равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < this->sortVector.size() - 1) {
				newSortIndex++;
				return this->cmpBookRecursive(firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.bookTitle.compare(firstBook.bookTitle.c_str()) > 0) {
			res.first = 1;
			return res;
		}
		else if (secondBook.bookTitle.compare(firstBook.bookTitle.c_str()) < 0) {
			res.first = -1;
			return res;
		}
	}
	else if (!key.compare(COLUMN_BOOK_YEAR_TITLE.c_str())) {
		if (secondBook.bookYear == firstBook.bookYear) {
			//std::printf("Значения даты выпуска книги равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < this->sortVector.size() - 1) {
				newSortIndex++;
				return this->cmpBookRecursive(firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
			
		}
		else if (secondBook.bookYear > firstBook.bookYear) {
			res.first = 1;
			return res;
		}
		else if (secondBook.bookYear < firstBook.bookYear) {
			res.first = -1;
			return res;
		}
	}
	else if (!key.compare(COLUMN_BOOK_PRICE_TITLE.c_str())) {
		if (secondBook.bookPrice == firstBook.bookPrice) {
			//std::printf("Значения стоимостей книги равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < this->sortVector.size() - 1) {
				newSortIndex++;
				return this->cmpBookRecursive(firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.bookPrice > firstBook.bookPrice) {
			res.first = 1;
			return res;
		}
		else if (secondBook.bookPrice < firstBook.bookPrice) {
			res.first = -1;
			return res;
		}
	}
	else if (!key.compare(COLUMN_BOOK_CATEGORY_TITLE.c_str())) {
		if (!secondBook.getBookCategory().compare(firstBook.getBookCategory().c_str())) {
			//std::printf("Значения категорий равны\n");
			size_t newSortIndex = sortIndex;
			if (newSortIndex < this->sortVector.size() - 1) {
				newSortIndex++;
				return this->cmpBookRecursive(firstVectorIndex, secondVectorIndex, newSortIndex);
			}
			res.first = 0;
			return res;
		}
		else if (secondBook.getBookCategory().compare(firstBook.getBookCategory().c_str()) > 0) {
			res.first = 1;
			return res;
		}
		else if (secondBook.getBookCategory().compare(firstBook.getBookCategory().c_str()) < 0) {
			res.first = -1;
			return res;
		}
	}
	res.first = 0;
	return res;
}
