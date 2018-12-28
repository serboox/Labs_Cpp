#include <iostream> // ��� ������ � ��������
#include <string>// ���������� ��� ������ �� ��������
#include "cmath" // ��� �������������� ��������
#include "other.h" // ������������ ���� � ����� ���������
// ������� ��� ����������� ��
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <Windows.h> // ���������� ��� ����������� ��������� � �������
#else
#include <unistd.h> // ���������� ��� sleep
#endif 

#define      stop __asm nop // ��� ������������

int main()
{
	/*11. ����������� �������� ���������� ����������� ������ ��� �������� ���������������.
	���������� ��������� ���������������� :
	�) �������� ������������� � ������
	�) ������ �� ������ ��� ��������������, ������� ������� ��������� � ���������
	�) ��������� ������ � �����
	�) ��������� ������ �� �����
	�) ����������� ������ �������� ��������� ��������*/

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	SetConsoleCP(1251);//1251 | CP_UTF8
	SetConsoleOutputCP(1251);//1251 | CP_UTF8
	// ������� ��� ����������� ��������� � ������� �� 7 �����
#else
	std::cout << "You are run this app in Linux;\n" << std::endl;
#endif
	run(); 
	return 0;
}