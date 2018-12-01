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
	{
		int NN, arraySize = 1;
		int* myArray = (int*)malloc(arraySize * sizeof(int));// Выделяю блок памяти на массив.
		int i = 0;
		while (true) {
			std::cout << "Enter number: ";
			std::cin >> NN;
			arrayAppend(myArray, NN, i, arraySize);
			/*if (i==0) {
				myArray[i] = NN;
				i++;
				continue;
			}
			if (arraySize< i+1) {
				arraySize *= 2;
				myArray = (int*)realloc(myArray, arraySize * sizeof(int));
			}
			myArray[i] = NN;*/

			bool notSorted = true;
			while (notSorted) {
				notSorted = false;
				for (size_t j = 0; j < i; j++) {
					if (myArray[j] > myArray[j + 1]) {
						myArray[j] ^= myArray[j + 1] ^= myArray[j] ^= myArray[j + 1];
						notSorted = true;
					}
				}
			}
			printOneDimArray(myArray, i + 1);
			i++;
		}
	}
	stop;

	//б) Простой поиск.
	//Модифицируйте предыдущее задание следующим образом:очередное значение
	//вводится в массив только при условии, что там еще такого нет (то есть 
	//дубли игнорируются
	//{
	//	int NN, arraySize = 1;
	//	int* myArray = (int*)malloc(arraySize * sizeof(int));// Выделяю блок памяти на массив.
	//	int i = 0;
	//	while (true) {
	//		std::cout << "Enter number: ";
	//		std::cin >> NN;
	//		if (i == 0) {
	//			myArray[i] = NN;
	//			i++;
	//			continue;
	//		}
	//		bool numberIsExist = false;
	//		for (size_t j = 0; j < i; j++) {
	//			if (myArray[j] == NN) {
	//				numberIsExist = true;
	//				std::cout << "This number is exist" << std::endl;
	//				break;
	//			}
	//		}
	//		if (numberIsExist) {
	//			continue;
	//		}
	//		if (arraySize < i + 1) {
	//			arraySize *= 2;
	//			myArray = (int*)realloc(myArray, arraySize * sizeof(int));
	//		}
	//		myArray[i] = NN;
	//		bool notSorted = true;
	//		while (notSorted) {
	//			notSorted = false;
	//			for (size_t j = 0; j < i; j++) {
	//				if (myArray[j] > myArray[j + 1]) {
	//					myArray[j] ^= myArray[j + 1] ^= myArray[j] ^= myArray[j + 1];
	//					notSorted = true;
	//				}
	//			}
	//		}
	//		printOneDimArray(myArray, i + 1);
	//		i++;
	//	}
	//}
	//	stop


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
	{
		//Определите необходимые значения как константы
		//STOP_STRING  -  "*"	//признак "прекратить ввод"
		//N  -  10	//максимальное количество строк в массиве
		//M  -  80	//максимальный размер одной строки
		const char STOP_STRING[] = "*";
		const char END_LINE[] = "\n";
		const size_t N = 3;
		const size_t M = 80;

		//Объявите двухмерный массив с именем cBuffer типа char и
		// размерностью N*M
		char cBuffer[N][M];

		//Объявите массив (с именем cPointers) указателей на строки
		//размерностью N
		char* cPointers[N];

		unsigned int rows = sizeof(cBuffer) / sizeof(cBuffer[0]);
		unsigned int columns = sizeof(cBuffer[0]) / sizeof(cBuffer[0][0]);
		std::cout << "N: " << rows << " M: " << columns << std::endl;

		//Цикл ввода строк:
		for (size_t nIndex = 0; nIndex < rows; nIndex++) {
			//а) выведите приглашение для ввода		
			std::cout << "Please enter string " << nIndex + 1 << " (len<=" << M << "): " << std::endl;
			std::cout << "=> ";
			//б) пока не введена строка STOP_STRING или не заполнен весь массив
			size_t mIndex = 0;
			char strBuff[] = { " " };
			while (strcmp(strBuff, STOP_STRING) && mIndex < columns) {
				//ввод строки в массив cBuffer:
				std::cin.read(strBuff, 1);
				//если в из потока вывода приходит знак переноса строки переходим к следующей итерации
				if (!strcmp(strBuff, END_LINE)) {
					continue;
				}
				//если введена строка - признак окончания, то выйти из цикла
				if (!strcmp(strBuff, STOP_STRING)) {
					break;
				}
				std::cout << "(N:" << nIndex + 1 << "|M:" << mIndex + 1 << "): " << strBuff << std::endl;
				cBuffer[nIndex][mIndex] = strBuff[0];
				mIndex++;
			}
			//Присвойте элементу массива cPointers с индексом nIndex
			//указатель на строку с номером nIndex в массиве cBuffer

			cPointers[nIndex] = cBuffer[nIndex];
		}

		//Выдать диагностику о том, что прием строк завершен.
		std::cout << "Line reception complete!" << std::endl;
		printTwoDimArray(cBuffer, N, M);
		//Теперь сортируем строки:

		//Цикл сортировки строк по методу "всплывающего пузырька" в
		//порядке возрастания. На каждой итерации - промежуточная печать 
		//отсортированных строк

		printOneDimArray(cPointers, N);
		//Повторяем, пок не отсортируем массив.
		bool notSorted = true;
		while (notSorted) {
			//Предполагаем, что не правильных пар нет.
			notSorted = false;
			for (size_t i = 0; i < (rows - 1); i++) {
				std::cout << "CMP: " << strcmp(cPointers[i], cPointers[i + 1]) << std::endl;
				if (strcmp(cPointers[i], cPointers[i + 1]) > 0) {
					// Меняем их местами
					char *temp = cPointers[i];
					cPointers[i] = cPointers[i + 1];
					cPointers[i + 1] = temp;

					// Масив еще не отсортирован.
					notSorted = true;
				}
			}
		}
		printOneDimArray(cPointers, N);
	}
	stop
		/*
			//Задание 5. Реализуйте задание №4, используя не встроенные,
			//а динамические массивы (массив?). Так как строки могут быть разной длины,
			//эффективным решением было бы отводить под каждую строку ровно столько байтов,
			//сколько требуется для ее хранения.
			//При этом необходимые параметры (количество строк
			// сформируйте с помощью потока ввода
			int nStringNumber;
		{
			//Определите необходимые значения как константы
			//STOP_STRING  -  "*"	//признак "прекратить ввод"
			const char STOP_STRING[] = "*";
			const char END_LINE[] = "\n";
			// размер malloc при инициализациии
			const size_t INITIALISATION_SIZE = 1;

			unsigned int nStringNumber = 1;
			std::cout << "Please enter number of lines (1<=N<=99):" << std::endl << "=> ";
			std::cin >> nStringNumber;
			if (1>nStringNumber || nStringNumber>99) {
				std::cout << "Set in nStringNumber default value (" << 1 << "):" << std::endl;
				nStringNumber = 1;
			}

			//Объявите двухмерный динамический массив с именем cBuffer типа char
			char **cBuffer = (char**)malloc(nStringNumber * sizeof(char));
			for (size_t i = 0; i < nStringNumber; i++)
				cBuffer[i] = (char*)malloc(INITIALISATION_SIZE * sizeof(char));

			//Объявите динамический массив (с именем cPointers) указателей на строки
			//размерностью N
			char **cPointers = (char**)malloc(nStringNumber * sizeof(char));

			//Цикл ввода строк:
			for (size_t nIndex = 0; nIndex < nStringNumber; nIndex++) {
				//а) выведите приглашение для ввода
				std::cout << "Please enter string " << nIndex + 1 << ": " << std::endl;
				std::cout << "=> ";
				//б) пока не введена строка STOP_STRING или не заполнен весь массив
				size_t mIndex = 0;
				char strBuff[] = { " " };
				size_t dinBuffSize = INITIALISATION_SIZE;
				char *dinBuff = (char*)malloc(dinBuffSize * sizeof(char));
				while (strcmp(strBuff, STOP_STRING)) {
					//ввод строки в массив cBuffer:
					std::cin.read(strBuff, 1);
					//если в из потока вывода приходит знак переноса строки переходим к следующей итерации
					if (!strcmp(strBuff, END_LINE)) {
						continue;
					}
					//если введена строка - признак окончания, то выйти из цикла
					if (!strcmp(strBuff, STOP_STRING)) {
						std::cout << "Record in cBuffer[" << nIndex << "]: " << mIndex << " symbols." << std::endl;
						if (INITIALISATION_SIZE < mIndex) {
							// изменяем размер блока выделенной памяти так чтобы хватало ровно под строку
							cBuffer[nIndex] = (char*)realloc(cBuffer[nIndex], mIndex * sizeof(char));
						}
						// записываем введенные символы в память
						for (size_t k = 0; k < mIndex; k++) {
							cBuffer[nIndex][k] = dinBuff[k];
						}
						break;
					}
					//если блока памяти выделенного для массива недостаточно, увеличиваем его вдвое
					if (dinBuffSize <= (mIndex+1)) {
						std::cout << "Size dinBuff " << dinBuffSize << " -> " << dinBuffSize * 2 << std::endl;
						dinBuffSize *= 2;
						// увеличиваем блок памяти вдвое
						dinBuff = (char*)realloc(dinBuff,dinBuffSize * sizeof(char));
					}
					dinBuff[mIndex] = strBuff[0];
					std::cout << "(N:" << nIndex + 1 << "|M:" << mIndex + 1 << "|Buff:" << dinBuffSize << "): ";
					std::cout << strBuff << std::endl;
					std::cout << "dinBuff: " << dinBuff << std::endl;
					mIndex++;
				}
				//Присвойте элементу массива cPointers с индексом nIndex
				//указатель на строку с номером nIndex в массиве cBuffer
				cPointers[nIndex] = cBuffer[nIndex];
			}

			//Выдать диагностику о том, что прием строк завершен.
			std::cout << "Line reception complete!" << std::endl;
			std::cout << "Print cBuffer" << std::endl;
			printOneDimArray(cBuffer, nStringNumber);

			//Теперь сортируем строки:

			//Цикл сортировки строк методом "всплывающего пузырька" в
			//порядке возрастания кода первого символа

			//Повторяем, пок не отсортируем массив.
			char symbolOne[] = { "" }, symbolTwo[] = {" "};
			bool notSorted = true;
			while (notSorted) {
				//Предполагаем, что не правильных пар нет.
				notSorted = false;
				for (size_t i = 0; i < (nStringNumber - 1); i++) {
					symbolOne[0] = *cPointers[i];
					symbolTwo[0] = *cPointers[i + 1];
					std::cout << "CMP: (" << symbolOne << "," << symbolTwo << ")->";
					std::cout << strcmp(symbolOne, symbolTwo) << std::endl;
					if (strcmp(symbolOne,symbolTwo) > 0) {
						// Меняем их местами
						char *temp = cPointers[i];
						cPointers[i] = cPointers[i + 1];
						cPointers[i + 1] = temp;

						// Масив еще не отсортирован.
						notSorted = true;
					}
				}
			}
			std::cout << "Print sorted Array" << std::endl;
			printOneDimArray(cPointers, nStringNumber);

			//Освобождение занятой памяти:
			system("pause");
			for (size_t i = 0; i < nStringNumber; i++) {
				free(cBuffer[i]);
			}
			return 0;
		}
			//Цикл ввода строк:
			//Цикл сортировки строк методом "всплывающего пузырька" в
			//порядке возрастания кода первого символ
			//Освобождение занятой памяти:
		*/

		/*
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

			for(int i=0; i<...; ...)
			{
			//Замечание: НЕ НУЖНО МОДИФИЦИРОВАТЬ ВЫРАЖЕНИЯ СПРАВА ОТ ЗНАКА РАВЕНСТВА!!!
				... =  dArray[i];
				... =  dArray[i+1];
				//переставляем местами элементы i-того и i+1-ого слоев


			}
			*/
			/*
				{
				//Определите необходимые значения как константы
				const size_t INITIALISATION_SIZE = 1; // размер malloc при инициализациии
				const size_t N = 4;
				const size_t M = 3;
				const size_t P = 3;

				//Объявите двухмерный динамический массив с именем cBuffer типа double
				double ***dArray = (double***)malloc(N * sizeof(double));
				for (size_t i = 0; i < N; i++) {
					dArray[i] = (double**)malloc(M * sizeof(double));
					for (size_t j = 0; j < M; j++) {
						dArray[i][j] = (double*)malloc(P * sizeof(double));
						for (size_t k = 0; k < M; k++) {
							dArray[i][j][k] = i+1;
						}
					}
				}
				for (size_t i = 0; i < N; i++) {
					printTwoDimArray(dArray[i], M, P);
				}
				//Цикл ввода строк:
				for (size_t i = 0; i < N; i+=2) {
					double **buff = dArray[i];
					dArray[i] = dArray[i + 1];
					dArray[i + 1] = buff;
				}
				for (size_t i = 0; i < N; i++) {
					printTwoDimArray(dArray[i], M, P);
				}
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
void printOneDimArray(const T arr, size_t values) {
	std::cout << "/ -----" << " Print one-dimensional Array with";
	std::cout << " Values: " << values << std::endl << "[";
	for (size_t i = 0; i < values; i++) {
		std::cout << arr[i];
		if (i != (values - 1)) {
			std::cout << " ";
		}
	}
	std::cout << "]" << std::endl;
	std::cout << "/ -----" << std::endl;
}

template<typename T>
void printOneDimArrayWitnEndl(const T arr, size_t values, size_t delimiter) {
	std::cout << "/ -----" << " Print two-dimensional Array with";
	std::cout << " Values: " << values << std::endl << "|";
	for (size_t i = 0; i < values; i++) {
		if (((i % delimiter) == 0) && i != 0) {
			std::cout << "|" << std::endl << "|";
		}
		std::cout << arr[i];
		if ((i != (values - 1)) && (((i + 1) % delimiter) != 0)) {
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