
#include "rectangle.h" // Подключаем заголовочный файл с определением

// fillFromStdIn функция заполняет поля прямогулольника через stdin
void Rectangle::fillFromStdIn()
{
	std::fprintf(stdout, "Please enter fields\n"); // Выводим в консоль пригласительную строку

	// Запускаем бесконечный цикл для запонения поля width
	while (true)
	{
		std::fprintf(stdout, "weight (float): "); // Выводим онформационное сообщение
		std::scanf("%f", &this->width);			  // Получаем значение ширины прямоугольника используя маску "%f"
		// Используем ignore для сброса символа переноса строки ('\n') оставшегося в потоке ввода числа
		std::cin.ignore();
		// Проверяем
		if (this->width < 0)
		{
			std::fprintf(stderr, "The weight of the rectangle can not be less than %d!\n", 0);
			/*
			 *  Делаем ожидание для корректного вывода текстовый полей в консоль иначе текст может поехать
			 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_sleep(100);
#else
			sleep(200);
#endif
			continue;
		}
		break;
	}

	while (true)
	{
		std::fprintf(stdout, "height (float): "); // Выводим онформационное сообщение
		std::scanf("%f", &this->height);		  // Получаем значение высоты прямоугольника используя маску "%f"
		//  Используем ignore для сброса символа переноса строки ('\n') оставшегося в потоке ввода числа
		std::cin.ignore();
		if (this->width < 0)
		{
			std::fprintf(stderr, "The height of the rectangle can not be less than %d!\n", 0);
			/*
			 *  Делаем ожидание для корректного вывода текстовый полей в консоль иначе текст может поехать
			 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			_sleep(100);
#else
			sleep(200);
#endif
			continue;
		}
		break;
	}
	this->area = this->width * this->height;
	this->nextRectangle = nullptr;
	this->prevRectangle = nullptr;
	std::cout << std::endl;
}

// print метод печати прямоугольника в stdout (консоль)
void Rectangle::print()
{
	std::printf("Rectangle{\n"
				"\t weight (float):%f\n"
				"\t height (float): %f\n"
				"\t area (float): %f\n}\n",
				this->width,
				this->height,
				this->area);
};

/* validateColumnTitle функция производящая проверку соответствует ли строка
	названию одной одной из колонок */
bool validateColumnTitle(const std::string str)
{
	if (!str.compare(COLUMN_WIDTH_TITLE.c_str()))
	{
		return true;
	}
	else if (!str.compare(COLUMN_HEIGHT_TITLE.c_str()))
	{
		return true;
	}
	else if (!str.compare(COLUMN_AREA_TITLE.c_str()))
	{
		return true;
	}
	return false;
}