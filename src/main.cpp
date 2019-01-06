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
	/*11. Посредством структур реализуйте двухсвязный список для хранения прямоугольников.
	Обеспечьте следующую функциональность :
	А) добавить прямоугольник в список
	Б) изъять из списка все прямоугольники, площадь которых совпадает с указанным
	В) сохранять данные в файле
	Г) считывать данные из файла
	Д) сортировать список согласно заданному критерию*/

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	SetConsoleCP(1251);		  //1251 | CP_UTF8
	SetConsoleOutputCP(1251); //1251 | CP_UTF8
							  // Функции для выставления кодировки в консоли на 7 винде
#else
	std::cout << "You are run this app in Unix;\n"
			  << std::endl;
#endif
	run();
	return 0;
}