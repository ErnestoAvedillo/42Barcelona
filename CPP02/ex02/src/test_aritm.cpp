
#include "../inc/main.h"

void test_aritm()
{
	Fixed a(5.42f);
	Fixed b(2.33f);

	std::cout << GREEN << "Prueba de sobrecarga de operadores aritméticos" << RESET << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador +" << RESET << std::endl;
	std::cout << "a = " << a << " + b= " << b << " =c = " << (a + b) << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador -" << RESET << std::endl;
	std::cout << "a = " << a << " - b= " << b << " =c = " << (a - b) << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador *" << RESET << std::endl;
	std::cout << "a = " << a << " * b= " << b << " =c = " << (a * b) << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador /" << RESET << std::endl;
	std::cout << "a = " << a << " / b= " << b << " =c = " << (a / b) << std::endl;
}