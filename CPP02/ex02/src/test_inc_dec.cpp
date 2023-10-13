
#include "../inc/main.h"

void test_inc_dec()
{
	Fixed a;

	std::cout << GREEN << "Prueba de sobrecarga de operadores incremento decremento (pre y post)" << RESET << std::endl;
	std::cout << BLUE << "Prueba sobrecarga operador preincremenento" << RESET << std::endl;
	std::cout << "valor inicial de a: " << a << std::endl;
	std::cout << "valor incremental de ++a: " << ++a << std::endl;
	std::cout << "valor incremental de ++a: " << ++a << std::endl;
	std::cout << "valor final de a: " << a << std::endl;
	std::cout << BLUE << "Prueba sobrecarga operador postincremenento" << RESET << std::endl;
	std::cout << "valor inicial de a: " << a << std::endl;
	std::cout << "valor incremental de a++: " << a++ << std::endl;
	std::cout << "valor final de a: " << a << std::endl;
	std::cout << BLUE << "Prueba sobrecarga operador predecremenento" << RESET << std::endl;
	std::cout << "valor inicial de a: " << a << std::endl;
	std::cout << "valor decremental de --a: " << --a << std::endl;
	std::cout << "valor final de a: " << a << std::endl;
	std::cout << BLUE << "Prueba sobrecarga operador postdecremenento" << RESET << std::endl;
	std::cout << "valor inicial de a: " << a << std::endl;
	std::cout << "valor decremental de a--: " << a-- << std::endl;
	std::cout << "valor final de a: " << a << std::endl;
}
