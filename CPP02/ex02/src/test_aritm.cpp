/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_aritm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void test_aritm()
{
	Fixed a(5.42f);
	Fixed b(2.33f);
	Fixed c = Fixed(3.45f) * Fixed(2.22f);
	Fixed d;
	d = a;
	std::cout << GREEN << "Prueba de sobrecarga de operadores aritméticos" << RESET << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador +" << RESET << std::endl;
	std::cout << "c = " << a << " + b= " << b << " =c = " << (a + b) << std::endl;
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
	d += b;
	std::cout << a << " += " << b << " = " << d << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador -" << RESET << std::endl;
	std::cout << "a = " << a << " - b= " << b << " =c = " << (a - b) << std::endl;
	std::cout <<  a << " - " << b << " = " << (a - b) << std::endl;
	d = a;
	d -= b;
	std::cout << a << " -= " << b << " = " << d << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador *" << RESET << std::endl;
	std::cout << "a = " << a << " * b= " << b << " =c = " << (a * b) << std::endl;
	std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	d = a;
	d *= b;
	std::cout << a << " *= " << b << " = " << d << std::endl;
	std::cout << BLUE << "Prueba alternativa de sobrecarga de operador *" << RESET << std::endl;
	std::cout << "3.45 (" << Fixed(3.45f) << ") * 2.22 (" << Fixed(2.22f) << ") = " << c << std::endl;
	std::cout << BLUE << "Prueba de sobrecarga de operador /" << RESET << std::endl;
	std::cout << "a = " << a << " / b= " << b << " = " << (a / b) << std::endl;
	d = a;
	d /= b;
	std::cout << a << " /= " << b << " = " << d << std::endl;
}
