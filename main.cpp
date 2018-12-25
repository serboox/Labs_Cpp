/*************************************************************
//Практическое занятие №5. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/
#include <iostream>
#include <cstdio>
#include <string>

#include <clocale>
#include "cmath"
#include "rectangle.h"
#include "other.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <Windows.h>
#endif

#define      stop __asm nop

int main(int argc, char** argv)
{
	/*11. Посредством структур реализуйте двухсвязный список для хранения прямоугольников.Обеспечьте следующую функциональность :
	А) добавить прямоугольник в список
	Б) изъять из списка все прямоугольники, площадь которых совпадает с указанным
	В) сохранять данные в файле
	Г) считывать данные из файла
	Д) сортировать список согласно заданному критерию*/

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	SetConsoleCP(1251);//1251 | CP_UTF8
	SetConsoleOutputCP(1251);//1251 | CP_UTF8
#else
	std::cout << "You are run this app in Linux;\n" << std::endl;
#endif
	run();
	return 0;
}