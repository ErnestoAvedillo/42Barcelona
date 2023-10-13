
#include "../inc/main.h"

void test_aritm()
{
	Fixed a(5.42f);
	Fixed b(2.33f);
	Fixed c = Fixed(3.45f) * Fixed(2.22f);
	Fixed e = Fixed(0);

	std::cout << GREEN << "Prueba de sobrecarga de operadores aritméticos" << RESET << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador +" << RESET << std::endl;
	std::cout << "a = " << a << " + b= " << b << " =c = " << (a + b) << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador -" << RESET << std::endl;
	std::cout << "a = " << a << " - b= " << b << " =c = " << (a - b) << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador *" << RESET << std::endl;
	std::cout << "a = " << a << " * b= " << b << " =c = " << (a * b) << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador /" << RESET << std::endl;
	std::cout << "a = " << a << " / b= " << b << " = " << (a / b) << std::endl;
	std::cout << "a = " << a << " / e= " << e << " = " << (a / e) << std::endl;
	std::cout << BLUE << "Prueba alternativa de sobrecarga de operador *" << RESET << std::endl;
	std::cout << "3.45 (" << Fixed(3.45f) << ") * 2.22 (" << Fixed(2.22f) << ") = " << c << std::endl;
}
