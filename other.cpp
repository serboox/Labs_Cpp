
#include <cstdio>
#include <string>
#include <vector>

#include "book.h"
#include "other.h"


void run()
{
	std::vector<BOOK> bookVector;

	while (true) {
		std::string command;
		std::printf("$ ");

		std::getline(std::cin, command);
		std::printf(u8"---%s----%d--\n", command.c_str(), command.length());

		if (!command.compare(COMMAND_HELP)) {
			std::printf(
				"%s  Распечатать содержимое картотеки. \n"
				"%s  Ввести новую книгу. \n"
				"%s  Удалить существующую(ие). \n"
				"%s  Записать текущее содержимое картотеки в файл. \n"
				"%s  Считать из файла содержимое в картотеку. \n"
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
			std::printf(" Распечатать содержимое картотеки. \n");
		}
		else if (!command.compare(COMMAND_SET)) {
			std::printf(" Ввести новую книгу \n");
		}
		else if (!command.compare(COMMAND_DELETE)) {
			std::printf(" Удалить существующую(ие). \n");
		}
		else if (!command.compare(COMMAND_WRITE)) {
			std::printf(" Записать текущее содержимое картотеки в файл. \n");
		}
		else if (!command.compare(COMMAND_READ)) {
			std::printf(" Считать из файла содержимое в картотеку. \n");
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
