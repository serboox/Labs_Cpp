
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
				"%s  ����������� ���������� ���������. \n"
				"%s  ������ ����� �����. \n"
				"%s  ������� ������������(��). \n"
				"%s  �������� ������� ���������� ��������� � ����. \n"
				"%s  ������� �� ����� ���������� � ���������. \n"
				"%s  ���������� ������ �������. \n"
				"%s  �����. \n",
				COMMAND_PRINT,
				COMMAND_ADD,
				COMMAND_DELETE,
				COMMAND_SAVE,
				COMMAND_LOAD,
				COMMAND_HELP,
				COMMAND_EXIT
			);
		}
		else if (!command.compare(COMMAND_PRINT)) {
			std::printf("C��������� ���������: \n\n");
			card.print();
			std::printf("\n");
		}
		else if (!command.compare(COMMAND_ADD)) {
			std::printf("������ ����� �����: \n\n");
			card.add();
		}
		else if (!command.compare(COMMAND_DELETE)) {
			std::printf("������� ������������(��): \n");
			card.deleteCards();
		}
		else if (!command.compare(COMMAND_SAVE)) {
			std::printf("�������� ������� ���������� ��������� � ����: \n");
			card.saveToFile();
		}
		else if (!command.compare(COMMAND_LOAD)) {
			std::printf("������� �� ����� ���������� � ���������: \n");
			card.readFromFile();
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
		authorFirstNameSize = std::strlen(" ��� "),
		authorLastNameSize = std::strlen(" ������� "),
		bookTitleSize = std::strlen(" ��������� "),
		bookYearSize = std::strlen(" ��� "),
		bookPriceSize = std::strlen(" ���� "),
		bookCategorySize = std::strlen(" ��������� ");
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
		<< alignCenter("���", authorFirstNameSize) << " | "
		<< alignCenter("�������", authorLastNameSize) << " | "
		<< alignCenter("���������", bookTitleSize) << " | "
		<< alignCenter("���", bookYearSize) << " | "
		<< alignCenter("����", bookPriceSize) << " | "
		<< alignCenter("���������", bookCategorySize) << " |\n";
	size_t totalSize = indexColumnSize + authorFirstNameSize + authorLastNameSize
		+ bookTitleSize + bookYearSize + bookPriceSize + bookCategorySize;
	totalSize += totalSize * 0.21;
	for (size_t i = 0; i <= totalSize; i++)
		std::cout << "�";
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
			std::printf("���� ��������� �����. Size: %d\n", this->bookVector.size());
			return;
		}
		
		int i;
		size_t firstIndex = 0,
			lastIndex = this->bookVector.size() - 1;
		std::printf("���������� ������� Index ��������� ����� (�� %d �� %d): ", firstIndex, lastIndex);
		std::scanf("%d", &i);
		std::cin.ignore();

		if (i < firstIndex || i > lastIndex) {
			std::printf("����� ����� �� ����������! \n");
			while (true) {
				command = "";
				std::printf("������� ����������? [Y/n]: ");
				std::getline(std::cin, command);
				if (!command.compare("") || !command.compare("Y") || !command.compare("y")) {
					break;
				}else if (!command.compare("n") || !command.compare("N")) {
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
			std::printf("�� ������������� ������� ������� ��� ����� �� ���������? [Y/n]: ");
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
		std::printf("����� �������! \n");
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

void Card::saveToFile()
{
	std::string saveData;
	for (BOOK book : this->bookVector) {
		saveData += book.authorFirstName.c_str();
		saveData += ";";
		saveData +=  book.authorLastName.c_str();
		saveData += ";";
		saveData +=  book.bookTitle.c_str();
		saveData += ";";
		saveData +=  std::to_string(book.bookYear);
		saveData += ";";
		saveData +=  std::to_string(book.bookPrice);
		saveData += ";";
		saveData +=  book.getBookCategory().c_str();
		saveData += "\n";
	}
	//std::printf("%s", saveData.c_str());
	std::ofstream outfile;
	std::string defaultPathToFile = "C:\\Users\\Public\\card.txt";
	while (true) {
		std::string pathToFile = "";
		std::printf("������� ������ ���� � ����� [default:%s]: ", defaultPathToFile.c_str());
		std::getline(std::cin, pathToFile);
		if (!pathToFile.compare("")) {
			pathToFile = defaultPathToFile;
		}
		outfile.open(pathToFile, std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (outfile.is_open()) {
			outfile << saveData.c_str();
			std::printf("���� �������� �� ����: '%s'\n", pathToFile.c_str());
			break;
		}
		else {
			std::printf("����� ��� ������ � ���� '%s' ������! \n", pathToFile.c_str());
			continue;
		}
		continue;
	}
	outfile.close();
}

void Card::readFromFile()
{
}
