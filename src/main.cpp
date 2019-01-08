#include <iostream> // для работы с потоками
#include <string>   // библиотека для работы со строками
#include "cmath"	// для математических операций
#include "other.h"  // заголовочный ФАЙЛ с кодом программы
// макросы для определения ОС
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <Windows.h> // библиотека для выставления кодировки в консоли
#else
#include <unistd.h> // библиотека для sleep
#endif

#define stop __asm nop // для брейкпойнтов

int main()
{
	//Упрощения:
	//1. пусть автор и заглавие книги состоят из одного слова
	//2. все строки можно задавать латинскими буквами. Если хочется
	//   не только выводить, но и вводить русские символы, следует
	//   а) пользоваться расширенными функциями ввода/вывода - wprintf(), wscanf()
	//   б) хранить строки как расширенные - wchar_t
	//   в) установить кодировку - setlocale(LC_CTYPE, ".866");

	//Используйте структуру BOOK, созданную в предыдущей работе.
	//Для этого достаточно переписать и подключить к проекту файлы
	//book.h и book.cpp

	//Задание 1. Создаем «картотеку».
	//«Картотека» - это массив структур => нужно такой массив создать.
	//Замечание: размер массива придется увеличивать по мере добавления книг =>
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

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	SetConsoleCP(1251);		  //1251 | CP_UTF8
	SetConsoleOutputCP(1251); //1251 | CP_UTF8
							  // Функции для выставления кодировки в консоли 
#else
	std::cout << "You are run this app in Unix;\n"
			  << std::endl;
#endif
	run();
	return 0;
}