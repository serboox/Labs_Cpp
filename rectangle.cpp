
#include "rectangle.h"

void Rectangle::fillFromStdIn() {
	std::fprintf(stdout, "Please enter fields\n");

	while (true) {
		std::fprintf(stdout, "weight (float): ");
		std::scanf("%f", &this->width);
		std::cin.ignore();
		if (this->width < 0) {
			std::fprintf(stderr, "The weight of the rectangle can not be less than %d!\n", 0);
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}

	while (true) {
		std::fprintf(stdout, "height (float): ");
		std::scanf("%f", &this->height);
		std::cin.ignore();
		if (this->width < 0) {
			std::fprintf(stderr, "The height of the rectangle can not be less than %d!\n", 0);
			_sleep(100);// делаем ожидание для корректного вывода текстовый полей в консоль
			continue;
		}
		break;
	}
	this->area = this->width * this->height;
	std::cout << std::endl;
}

void Rectangle::print() {
	std::printf("Rectangle{\n"
		"\t weight (float):%f\n"
		"\t height (float): %f\n"
		"\t area (float): %f\n}\n",
		this->width,
		this->height,
		this->area);
};

bool validateColumnTitle(const std::string str)
{
	if (!str.compare(COLUMN_WIDTH_TITLE.c_str())) {
		return true;
	}
	else if (!str.compare(COLUMN_HEIGHT_TITLE.c_str())) {
		return true;
	}
	else if (!str.compare(COLUMN_AREA_TITLE.c_str())) {
		return true;
	}
	return false;
}