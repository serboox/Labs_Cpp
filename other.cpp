
#include "book.h"
#include "other.h"

void run()
{
	Card card;
	while (true) {
		std::string command;
		std::printf("$ ");

		std::getline(std::cin, command);
		std::printf("---%s----%d--\n", command.c_str(), command.length());

		if (!command.compare(COMMAND_HELP)) {
			std::printf(
				"%s  Распечатать содержимое картотеки. \n"
				"%s  Ввести новую книгу. \n"
				"%s  Удалить существующую(ие). \n"
				"%s  Записать текущее содержимое картотеки в файл. \n"
				"%s  Считать из файла содержимое в картотеку. \n"
				"%s  Отобразить список комманд. \n"
				"%s  Выйти. \n",
				COMMAND_PRINT,
				COMMAND_SET,
				COMMAND_DELETE,
				COMMAND_WRITE,
				COMMAND_READ,
				COMMAND_HELP,
				COMMAND_EXIT
			);
		}
		else if (!command.compare(COMMAND_PRINT)) {
			std::printf("Cодержимое картотеки: \n\n");
			card.print();
			std::printf("\n");
		}
		else if (!command.compare(COMMAND_SET)) {
			std::printf("Ввести новую книгу \n\n");
			card.set();
			std::printf("\n");
		}
		else if (!command.compare(COMMAND_DELETE)) {
			std::printf("Удалить существующую(ие). \n");
		}
		else if (!command.compare(COMMAND_WRITE)) {
			std::printf("Записать текущее содержимое картотеки в файл. \n");
		}
		else if (!command.compare(COMMAND_READ)) {
			std::printf("Считать из файла содержимое в картотеку. \n");
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

void Card::set()
{
	BOOK newBook;
	newBook.fillFromStdIn();
	this->bookVector.push_back(newBook);
}

void Card::print()
{
	size_t authorFirstNameSize = std::strlen(" Имя "),
		authorLastNameSize = std::strlen(" Фамилия "),
		bookTitleSize = std::strlen(" Заголовок "),
		bookYearSize = std::strlen(" Год "),
		bookPriceSize = std::strlen(" Цена "),
		bookCategorySize = std::strlen(" Категория ");
	for (BOOK book : this->bookVector) {
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
	}
	std::cout << alignCenter("Имя", authorFirstNameSize) << " | "
		<< alignCenter("Фамилия", authorLastNameSize) << " | "
		<< alignCenter("Заголовок", bookTitleSize) << " | "
		<< alignCenter("Год", bookYearSize) << " | "
		<< alignCenter("Цена", bookPriceSize) << " | "
		<< alignCenter("Категория", bookCategorySize) << " |\n";
	size_t totalSize = authorFirstNameSize + authorLastNameSize + bookTitleSize + bookYearSize + bookPriceSize + bookCategorySize;
	totalSize += totalSize * 0.21;
	for (size_t i=0; i <= totalSize; i++)
		std::cout << "—";
	std::cout << std::endl;
	for (BOOK book : this->bookVector) {
		std::cout << alignCenter(book.authorFirstName, authorFirstNameSize) << " | ";
		std::cout << alignCenter(book.authorLastName, authorLastNameSize) << " | "
			<< alignCenter(book.bookTitle, bookTitleSize) << " | "
			<< alignCenter(std::to_string(book.bookYear), bookYearSize) << " | "
			<< alignCenter(std::to_string(book.bookPrice), bookPriceSize) << " | "
			<< alignCenter(book.getBookCategory().c_str(), bookCategorySize) << " |\n";
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
