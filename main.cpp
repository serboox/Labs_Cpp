/*************************************************************
//Практическое занятие №5. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/
#include <iostream>
#include <string>
#include "cmath"
#include "book.h"
#include "other.h"

#define      stop __asm nop

int main() {
	//Используйте структуру BOOK, созданную в предыдущей работе.
	//Для этого достаточно переписать и подключить к проекту файлы
	//book.h и book.cpp

	BOOK book;
	std::printf("Static size: %d\n", (int) sizeof(book));

	std::printf("\nBook authorFirstName size: %d\n", (int) sizeof(book.authorFirstName));
	std::printf("Book authorLastName size: %d\n", (int) sizeof(book.authorLastName));
	std::printf("Book bookTitle size: %d\n", (int) sizeof(book.bookTitle));
	std::printf("Book bookYear size: %d\n", (int) sizeof(book.bookYear));
	std::printf("Book bookPrice size: %d\n", (int) sizeof(book.bookPrice));
	std::printf("Book bookCategory size: %d\n\n", (int) sizeof(book.bookCategory));
	stop;

	//Упрощения:
	//1. пусть автор и заглавие книги состоят из одного слова
	//2. все строки можно задавать латинскими буквами. Если хочется
	//   не только выводить, но и вводить русские символы, следует
	//   а) пользоваться расширенными функциями ввода/вывода - wprintf(), wscanf()
	//   б) хранить строки как расширенные - wchar_t
	//   в) установить кодировку - setlocale(LC_CTYPE, ".866");


	//Задание 1. Создаем «картотеку».
	//«Картотека» - это массив структур => нужно такой массив создать.
	//Замечание: размер массива придется увеличиватьпо мере добавления книг =>
	//каким должен быть такой массив???


	//Пользователь должен иметь возможность по своему желанию выполнять
	//разные действия с картотекой => нужно такую возможность ему
	//предоставить: это может выглядеть как вывод "меню" (перечень
	//возможных действий и соответствующих реакций пользователя), например:
	//Распечатать содержимое картотеки (1)
	//Ввести новую книгу (2)
	//Удалить существующую(ие) (3)
	//Записать текущее содержимое картотеки в файл (4)
	//Считать из файла содержимое в картотеку (5)
	//...
	//Выход из программы (...)


	//Реализуйте посредством функций разные возможности работы с картотекой




	//Подсказка: для файлового ввода/вывода используйте функции fprintf и fscanf
	//(заголовочный файл <cstdio>








	//****************************************************************
	//Задание 2. Предоставьте пользователю возможность выводить перечень книг
	//в определенном порядке => напишите функцию (функции) сортировки массива
	//по любому из полей структуры.
	//Замечание: признак - "по какому полю сортируем" можно ввести с помощью
	//перечисления.



}

template<typename T>
void printOneDimArray(const T arr, size_t rows) {

	std::cout << "/ -----" << " Print one-dimensional Array with";
	std::cout << " Rows: " << rows << std::endl;
	for (size_t i = 0; i < rows; i++) {
		if (i == 0) {
			std::cout << "[";
		}
		std::cout << arr[i];
		if (i == (rows - 1)) {
			std::cout << "]" << std::endl;
		}
		else {
			std::cout << " ";
		}
	}
	std::cout << "/ -----" << std::endl;
}

template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t columns) {
	std::cout << "/ -----" << " Print two-dimensional Array with";
	std::cout << " Rows: " << rows << " Columns: " << columns << std::endl;
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			if (j == 0) {
				std::cout << "/ ";
			}
			std::cout << arr[i][j];
			if (j == (columns - 1)) {
				std::cout << " /" << std::endl;
			}
		}
	}
	std::cout << "/ -----" << std::endl;
}