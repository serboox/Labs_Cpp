/*************************************************************
//������������ ������� �5. ���������
//������������ ������ ��������
//�����
//����������
//���������� � �����
//������ �� �����
*************************************************************/
#include <iostream>
#include <string>
#include "cmath"
#include "book.h"
#include "other.h"

#define      stop __asm nop

int main() {
	//����������� ��������� BOOK, ��������� � ���������� ������.
	//��� ����� ���������� ���������� � ���������� � ������� �����
	//book.h � book.cpp

	BOOK book;
	std::printf("Static size: %d\n", (int) sizeof(book));

	std::printf("\nBook authorFirstName size: %d\n", (int) sizeof(book.authorFirstName));
	std::printf("Book authorLastName size: %d\n", (int) sizeof(book.authorLastName));
	std::printf("Book bookTitle size: %d\n", (int) sizeof(book.bookTitle));
	std::printf("Book bookYear size: %d\n", (int) sizeof(book.bookYear));
	std::printf("Book bookPrice size: %d\n", (int) sizeof(book.bookPrice));
	std::printf("Book bookCategory size: %d\n\n", (int) sizeof(book.bookCategory));
	stop;

	//���������:
	//1. ����� ����� � �������� ����� ������� �� ������ �����
	//2. ��� ������ ����� �������� ���������� �������. ���� �������
	//   �� ������ ��������, �� � ������� ������� �������, �������
	//   �) ������������ ������������ ��������� �����/������ - wprintf(), wscanf()
	//   �) ������� ������ ��� ����������� - wchar_t
	//   �) ���������� ��������� - setlocale(LC_CTYPE, ".866");


	//������� 1. ������� ����������.
	//���������� - ��� ������ �������� => ����� ����� ������ �������.
	//���������: ������ ������� �������� ������������� ���� ���������� ���� =>
	//����� ������ ���� ����� ������???


	//������������ ������ ����� ����������� �� ������ ������� ���������
	//������ �������� � ���������� => ����� ����� ����������� ���
	//������������: ��� ����� ��������� ��� ����� "����" (��������
	//��������� �������� � ��������������� ������� ������������), ��������:
	//����������� ���������� ��������� (1)
	//������ ����� ����� (2)
	//������� ������������(��) (3)
	//�������� ������� ���������� ��������� � ���� (4)
	//������� �� ����� ���������� � ��������� (5)
	//...
	//����� �� ��������� (...)


	//���������� ����������� ������� ������ ����������� ������ � ����������




	//���������: ��� ��������� �����/������ ����������� ������� fprintf � fscanf
	//(������������ ���� <cstdio>








	//****************************************************************
	//������� 2. ������������ ������������ ����������� �������� �������� ����
	//� ������������ ������� => �������� ������� (�������) ���������� �������
	//�� ������ �� ����� ���������.
	//���������: ������� - "�� ������ ���� ���������" ����� ������ � �������
	//������������.



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