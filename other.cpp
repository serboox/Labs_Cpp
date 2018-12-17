
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
				"%s  ����������� ���������� ���������. \n"
				"%s  ������ ����� �����. \n"
				"%s  ������� ������������(��). \n"
				"%s  �������� ������� ���������� ��������� � ����. \n"
				"%s  ������� �� ����� ���������� � ���������. \n"
				"%s  �����. \n",
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
			std::printf(" ����������� ���������� ���������. \n");
		}
		else if (!command.compare(COMMAND_SET)) {
			std::printf(" ������ ����� ����� \n");
		}
		else if (!command.compare(COMMAND_DELETE)) {
			std::printf(" ������� ������������(��). \n");
		}
		else if (!command.compare(COMMAND_WRITE)) {
			std::printf(" �������� ������� ���������� ��������� � ����. \n");
		}
		else if (!command.compare(COMMAND_READ)) {
			std::printf(" ������� �� ����� ���������� � ���������. \n");
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
