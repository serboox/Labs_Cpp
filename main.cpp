/*************************************************************
	Практическое занятие №3. Встроенные массивы.
							Динамическое выделение памяти.
							Простейшие алгоритмы сортировки и поиска.
							Сложные указатели.
							Ссылки.
*************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "other.h"

#define	  stop __asm nop

int main()
{

	///////////////////////////////////////////////////////////////
	//			Встроенные массивы                               //
	///////////////////////////////////////////////////////////////

	//Задание 1. Объявите трехмерный массив и сформируйте указанные
	//значения элементов следующим образом:
	//а) проинициализируйте массив при объявлении
	/*{
		int arrInt1[3][3][3] = {
							{{1,1,1}, {1,1,1}, {1,1,1}},
							{{2,2,2}, {2,2,2}, {2,2,2}},
							{{3,3,3}, {3,3,3}, {3,3,3}}
		};
		stop
	}*/

	//б) объявите неинициализированный массив и присвойте значения элементам
	//	с помощью кода
	//					 |--------|		
	//				   / |3  3  3 |		
	//    			 |---------|3 |
	//			   / | 2  2  2 |3 |
	//			  |---------|2 |__|
	//			  | 1  1  1 |2 | /
	//			  | 1  1  1 |__| 
	//			  | 1  1  1 | /
	//			  |_________|
	//Средствами отладчика проверьте правильность Вашего решения.
	/*{
		int arrInt2[3][3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					arrInt2[i][j][k] = i + 1;
				}
			}
		}
		stop
	}*/

	//в) найдите сумму элементов массива
	/*{
		int sum = 0;
		int arrInt3[3][3][3] = {
									{{1,1,1}, {1,1,1}, {1,1,1}},
									{{2,2,2}, {2,2,2}, {2,2,2}},
									{{3,3,3}, {3,3,3}, {3,3,3}}
		};
		int *parrInt3 = &arrInt3[0][0][0];
		size_t Intz = sizeof(arrInt3) / sizeof(arrInt3[0][0][0]);
		for (int i = 0; i < Intz; i++)
		{
			sum += *parrInt3;
			parrInt3++;
		}
		stop
	}*/

	//г) проинициализируйте массив при объявлении:
	//					   |--------|		
	//					 / |3  0  0 |		
	//	    		   |---------|0 |
	//    			 / | 2  0  0 |0 |
	//				|---------|0 |__|
	//				| 1  0  0 |0 | /
	//				| 0  0  0 |__| 
	//				| 0  0  0 | /
	//				|_________|
	/*{
		int arrInt4[3][3][3] = { {1}, {2}, {3} };
	}*/

	//д) Инициализация массивов строковыми литералами:
	//Объявите и проинициализируйте строковыми литералами два массива:
	//двухмерный массив и массив указателей. Поясните разницу в использовании
	//элементов таких массивов.
	/*{
		char arrInt5[][15] = { {"It`s"},{"Easy"} };
		const char*arrInt6[] = { {"It`s"},{"Hard"} };
		stop
	}*/


	///////////////////////////////////////////////////////////////
	//			Динамическое выделение памяти                    //
	///////////////////////////////////////////////////////////////
	//Задание2. Создайте динамический двухмерный массив с размерностями,
	//вычисляемыми в процессе выполнения программы - N*M.
	//Задайте значения элементов помощью генератора случайных чисел.
	//Найдите  сумму элементов.
	//Подсказка 1: для генерации случайных чисел используйте функцию
	//стандартной библиотеки - rand() (<cstdlib>)
	//Подсказка 2: На самом деле те значения, которые создаются генератором случайных
	//чисел являются «псевдослучайными», то есть при двух последовательных запусках
	//приложения Вы получаете две одинаковые последовательности значений.
	//Для того чтобы генерируемые "случайные" значения были разными при каждом 
	//запуске приложения используйте функции стандартной библиотеки srand() (<cstdlib>)
	//и time() (<ctime>).
	//Функция srand() осуществляет «привязку» начала генерации к указанному в качестве параметра значению.
	//Функция time() задает эту точку отсчета, считывая текущее время
	/*{
		srand(time(0));
		int N = 3;
		int M = 4;
		int *p = new int[N*M];
		for (int i = 0; i < N*M; i++) {
			p[i] = rand() % 10;
			std::cout << p[i] << " ";
		}
		int sum = arraySum(p, N, M);
		std::cout << std::endl;
		printOneDimArrayWitnEndl(p, N*M, M);
		std::cout << "Array Sum: " << sum << std::endl;
		stop;

		//Задание2а. В сформированном массиве отсортируйте каждую строку по
		//убыванию значений. Используйте сортировку "выбором"
		sortByChoice(p, N, M);
		printOneDimArrayWitnEndl(p, N*M, M);
		stop;

		//Задание2б. Объявите одномерный массив размерностью N.
		//Сформируйте значение i-ого элемента одномерного массива
		//равным среднему значению элементов i-ой строки
		//двухмерного массива
		double *p2 = columnAverage(p, N, M);
		printOneDimArray(p2, N);

		//Подсказка - не забудьте освободить память!
		delete[]p;
		p = nullptr;
		delete[]p2;
		p2 = nullptr;
		stop
	}*/

	/////////////////////////////////////////////////////////////////////
	//Задание 3. а) Напишите фрагмент кода, который вводит NN целых чисел с помощью
	//потока ввода в объявленный Вами встроенный одномерный массив, каждый раз
	//упорядочивая полученное значение по возрастанию
	/*{
		int NN, arraySize = 1;
		int* myArray = (int*)malloc(arraySize * sizeof(int));// Выделяю блок памяти на массив.
		int i = 0;
		while (true) {
			std::cout << "Enter number: ";
			std::cin >> NN;
			if (i == 0) {
				arrayAppend(myArray, NN, i, arraySize);
				i++;
				continue;
			}
			arrayAppend(myArray, NN, i, arraySize);
			sortByBubble(myArray, i);
			printOneDimArray(myArray, i + 1);
			i++;
		}
	}
	stop;*/

	//б) Простой поиск.
	//Модифицируйте предыдущее задание следующим образом:очередное значение
	//вводится в массив только при условии, что там еще такого нет (то есть 
	//дубли игнорируются
	/*{
		int NN, arraySize = 1;
		int* myArray = (int*)malloc(arraySize * sizeof(int));// Выделяю блок памяти на массив.
		int i = 0;
		while (true) {
			std::cout << "Enter number: ";
			std::cin >> NN;
			if (i == 0) {
				arrayAppend(myArray, NN, i, arraySize);
				i++;
				continue;
			}
			if (arrayExist(myArray, NN, i)) {
				std::cout << "This number " << NN << " is exist" << std::endl;
				continue;
			}
			arrayAppend(myArray, NN, i, arraySize);
			sortByBubble(myArray, i);
			printOneDimArray(myArray, i + 1);
			i++;
		}
	}
	stop;*/

	/*
		///////////////////////////////////////////////////////////////////////////
		//Задание 4.С помощью данной заготовки напишите программу,
		//которая:
		//вводит строки с клавиатуры с помощью cin>>...
		//в объявленный Вами двухмерный встроенный массив 5*80 элементов типа char;
		//признаком конца ввода является символ * (то есть строка - "*") или
		//заполнение массива (больше свободных строк нет);
		//сортировка строк в алфавитном порядке. Пояснение: крайне
		//не рекомендуется для сортировки сложных объектов физически
		//перемещать их в памяти. Намного эффективнее завести массив
		//указателей на соответствующие строки и перемещать только
		//указатели.

		//Подсказка: для лексиграфического сравнения строк пользуйтесь
		//функцией стандартной библиотеки strcmp(...), заголовочный файл <string>.
	*/
	/*{
		//Определите необходимые значения как константы
		//STOP_STRING  -  "*"	//признак "прекратить ввод"
		//N  -  10	//максимальное количество строк в массиве
		//M  -  80	//максимальный размер одной строки

		// в файле other.cpp

		//Объявите двухмерный массив с именем cBuffer типа char и
		// размерностью N*M
		char cBuffer[N][M];

		//Объявите массив (с именем cPointers) указателей на строки
		//размерностью N
		char* cPointers[N];

		unsigned int rows = sizeof(cBuffer) / sizeof(cBuffer[0]);
		unsigned int columns = sizeof(cBuffer[0]) / sizeof(cBuffer[0][0]);

		fillStaticArrayThroughCin(cBuffer, rows, columns);

		//Присвойте элементу массива cPointers с индексом nIndex
		//указатель на строку с номером nIndex в массиве cBuffer
		for (size_t nIndex = 0; nIndex < rows; nIndex++) {
			cPointers[nIndex] = cBuffer[nIndex];
		}

		//Выдать диагностику о том, что прием строк завершен.
		std::cout << "Line reception complete!" << std::endl;
		printTwoDimArray(cBuffer, N, M);
		//Теперь сортируем строки:

		//Цикл сортировки строк по методу "всплывающего пузырька" в
		//порядке возрастания. На каждой итерации - промежуточная печать
		//отсортированных строк

		printTwoDimArray(cPointers, N, M);
		sortByBubble(cPointers, N);
		printTwoDimArray(cPointers, N, M);
		stop;
	}*/
	//Задание 5. Реализуйте задание №4, используя не встроенные,
	//а динамические массивы (массив?). Так как строки могут быть разной длины,
	//эффективным решением было бы отводить под каждую строку ровно столько байтов,
	//сколько требуется для ее хранения.
	//При этом необходимые параметры (количество строк
	// сформируйте с помощью потока ввода
	//int nStringNumber;
	/*{
		//Определите необходимые значения как константы
		//STOP_STRING  -  "*"	//признак "прекратить ввод"

		unsigned int nStringNumber = 1;
		std::cout << "Please enter number of lines (1<=N<=99):" << std::endl << "=> ";
		std::cin >> nStringNumber;
		if (1 > nStringNumber || nStringNumber > 99) {
			std::cout << "Set in nStringNumber default value (" << 1 << "):" << std::endl;
			nStringNumber = 1;
		}

		//Объявите двухмерный динамический массив с именем cBuffer типа char
		char **cBuffer = (char**)malloc(nStringNumber * sizeof(char));
		for (size_t i = 0; i < nStringNumber; i++)
			cBuffer[i] = (char*)malloc(1 * sizeof(char));

		//Объявите динамический массив (с именем cPointers) указателей на строки
		//размерностью N
		char **cPointers = (char**)malloc(nStringNumber * sizeof(char));

		// Объявляем массив хранящий длины вводимых строк
		size_t *cBuffStrLen = (size_t*)malloc(nStringNumber * sizeof(size_t));

		fillDynamicArrayThroughCin(cBuffer, nStringNumber, cBuffStrLen);

		std::cout << "Strlen array______" << std::endl;
		printOneDimArray(cBuffStrLen, nStringNumber);

		for (size_t nIndex = 0; nIndex < nStringNumber; nIndex++) {
			//Присвойте элементу массива cPointers с индексом nIndex
			//указатель на строку с номером nIndex в массиве cBuffer
			cPointers[nIndex] = cBuffer[nIndex];
		}

		//Выдать диагностику о том, что прием строк завершен.
		std::cout << "Line reception complete!" << std::endl;
		std::cout << "Print cBuffer" << std::endl;
		printTwoDimArray(cBuffer, nStringNumber, cBuffStrLen);

		//Теперь сортируем строки:

		//Цикл сортировки строк методом "всплывающего пузырька" в
		//порядке возрастания кода первого символа
		printTwoDimArray(cPointers, nStringNumber, cBuffStrLen);
		sortByBubbleDynArr(cPointers, nStringNumber, cBuffStrLen);
		std::cout << "Print sorted Array" << std::endl;
		printTwoDimArray(cPointers, nStringNumber, cBuffStrLen);

		//Освобождение занятой памяти:
		for (size_t i = 0; i < nStringNumber; i++) {
			free(cBuffer[i]);
		}
		stop;
	}*/


	//Задание 6. Объявление и использование указателей на многомерные
	// массивы. Проинициализируйте трехмерный массив
	//double dArray[4][3][3] так, как показано на рисунке и напишите фрагмент
	//кода, который меняет местами значения элементов четных
	//и нечетных слоев:

	//	было:			     |--------|
	//  				   / |4  4  4 |
	//					 |--------|	4 |
	//				   / |3  3  3 |	4 |
	//    			 |---------|3 |   |
	//			   / | 2  2  2 |3 | /
	//			  |---------|2 |__|
	//			  | 1  1  1 |2 | /
	//			  | 1  1  1 |__|
	//			  | 1  1  1 | /
	//			  |_________|

	//	стало:			     |--------|
	//  				   / |3  3  3 |
	//					 |--------|	3 |
	//				   / |4  4  4 |	3 |
	//    			 |---------|4 |   |
	//			   / | 1  1  1 |4 | /
	//			  |---------|1 |__|
	//			  | 2  2  2 |1 | /
	//			  | 2  2  2 |__|
	//			  | 2  2  2 | /
	//			  |_________|

	//for(int i=0; i<...; ...)
	//{
	////Замечание: НЕ НУЖНО МОДИФИЦИРОВАТЬ ВЫРАЖЕНИЯ СПРАВА ОТ ЗНАКА РАВЕНСТВА!!!
	//	... =  dArray[i];
	//	... =  dArray[i+1];
	//	//переставляем местами элементы i-того и i+1-ого слоев
	/*{
		//Определите необходимые значения как константы

		//Объявите двухмерный динамический массив с именем cBuffer типа double
		double dArray[N6][M6][P6];
		for (size_t i = 0; i < N6; i++) {
			for (size_t j = 0; j < M6; j++) {
				for (size_t k = 0; k < P6; k++) {
					dArray[i][j][k] = i + 1;
				}
			}
		}
		std::cout << "\n____________Source____________\n";
		for (size_t i = 0; i < N6; i++) {
			printTwoDimArray(dArray[i], M6, P6);
		}
		std::cout << "______________________________\n";
		// Меняем местами матрицы в мессиве
		swapEvenMatrices(dArray);
		std::cout << "\n____________Result____________\n";
		for (size_t i = 0; i < N6; i++) {
			printTwoDimArray(dArray[i], M6, P6);
		}
		std::cout << "______________________________\n";
		stop;
	}*/

	///////////////////////////////////////////////////////////////////////////
	//Задание 7а. Объявите двухмерный встроенный массив элементов типа char.
	//Сформируйте значения элементов массива с помощью генератора случайных 
	//чисел таким образом, чтобы в массиве были только символы '*' и '_'
	//В каждой строке "сдвиньте звездочки" в начало строки, например:
	//было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
	//стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
	//и распечатайте массив по строкам - "постройте распределение"
	{
		srand(time(0));
		const int N = 10, M = 50;
		char myArray[N][M];
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < M; j++) {
				myArray[i][j] = (char)rand() % 2 ? '_' : '*';
			}
		}
		printTwoDimArray(myArray, N, M);
		for (size_t i = 0; i < N; i++) {
			bool notSorted = true;
			while (notSorted) {
				notSorted = false;
				for (size_t j = 0; j < (M - 1); j++) {
					//std::cout << myArray[i][j] << " - " << myArray[i][j + 1] << " <- ";
					//std::cout << (myArray[i][j] == '_' && myArray[i][j + 1] == '*') << std::endl;
					if (myArray[i][j] == '_' && myArray[i][j + 1] == '*') {
						myArray[i][j] ^= myArray[i][j + 1] ^= myArray[i][j] ^= myArray[i][j + 1];
						notSorted = true;
					}
				}
			}
		}
		printTwoDimArray(myArray, N, M);
		//stop
	}
	// 7б. Модифицируйте предыдущее задание следующим способом:
	//После заполнения массива с помощью генератора случайных чисел
	//"сдвиньте" звездочки по столбцам вниз и распечатайте полученное
	//"распределение"
	{
		srand(time(0));
		const int N = 10, M = 50;
		char myArray[N][M];
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < M; j++) {
				myArray[i][j] = (char)rand() % 2 ? '_' : '*';
			}
		}
		printTwoDimArray(myArray, N, M);

		for (size_t j = 0; j < M; j++) {
			bool notSorted = true;
			while (notSorted) {
				notSorted = false;
				for (size_t i = 0; i < (N - 1); i++) {
					//std::cout << myArray[i][j] << " - " << myArray[i+1][j] << " <- ";
					//std::cout << (myArray[i][j] == '*' && myArray[i+1][j] == '_') << std::endl;
					if (myArray[i][j] == '*' && myArray[i + 1][j] == '_') {
						myArray[i][j] ^= myArray[i + 1][j] ^= myArray[i][j] ^= myArray[i + 1][j];
						notSorted = true;
					}
				}
				//printTwoDimArray(myArray, N, M);
				//stop
			}
		}
		printTwoDimArray(myArray, N, M);
		stop
	}
	return 0;
}

template<typename T>
void printOneDimArray(const T arr, size_t rows) {
	std::cout << "/ -----" << " Print one-dimensional Array with";
	std::cout << " Values: " << rows << std::endl << "[";
	for (size_t i = 0; i < rows; i++) {
		std::cout << arr[i];
		if (i != (rows - 1)) {
			std::cout << " ";
		}
	}
	std::cout << "]" << std::endl;
	std::cout << "/ -----" << std::endl;
}

template<typename T>
void printOneDimArrayWitnEndl(const T arr, size_t rows, size_t delimiter) {
	std::cout << "/ -----" << " Print two-dimensional Array with";
	std::cout << " Values: " << rows << std::endl << "|";
	for (size_t i = 0; i < rows; i++) {
		if (((i % delimiter) == 0) && i != 0) {
			std::cout << "|" << std::endl << "|";
		}
		std::cout << arr[i];
		if ((i != (rows - 1)) && (((i + 1) % delimiter) != 0)) {
			std::cout << " ";
		}
	}
	std::cout << "|" << std::endl;
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

template<typename T>
void printTwoDimArray(const T arr, size_t rows, size_t * arrStrLen)
{
	std::cout << "/ -----" << " Print two-dimensional Array with";
	std::cout << " Rows: " << rows << std::endl;
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < arrStrLen[i]; j++) {
			if (j == 0) {
				std::cout << "/ ";
			}
			std::cout << arr[i][j];
			if (j == (arrStrLen[i] - 1)) {
				std::cout << " /" << std::endl;
			}
		}
	}
	std::cout << "/ -----" << std::endl;
}
