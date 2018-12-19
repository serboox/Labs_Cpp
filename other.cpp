
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
		else if (!command.compare(COMMAND_LOAD)) {
			std::printf("Сортировки массива по одному или нескольким полям: \n");
			card.sort();
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

void Card::print()
{
	size_t indexColumnSize = std::strlen(" Index "),
		authorFirstNameSize = std::strlen(" Имя "),
		authorLastNameSize = std::strlen(" Фамилия "),
		bookTitleSize = std::strlen(" Заголовок "),
		bookYearSize = std::strlen(" Год "),
		bookPriceSize = std::strlen(" Цена "),
		bookCategorySize = std::strlen(" Категория ");
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
	std::cout << alignCenter("Index", indexColumnSize) << " | "
		<< alignCenter("Имя", authorFirstNameSize) << " | "
		<< alignCenter("Фамилия", authorLastNameSize) << " | "
		<< alignCenter("Заголовок", bookTitleSize) << " | "
		<< alignCenter("Год", bookYearSize) << " | "
		<< alignCenter("Цена", bookPriceSize) << " | "
		<< alignCenter("Категория", bookCategorySize) << " |\n";
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
				std::vector<std::string> bookProps = split(readData,';');
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

void Card::sort()
{
}
