/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_comp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void test_comp()
{

	Fixed a(5.5f);
	Fixed b(1.5f);
	Fixed c(a);

	std::cout << GREEN << "Prueba de sobrecarga de operadores de comparación" << RESET << std::endl;
	std::cout << BLUE << "Prueba sobrecarga comparador <" << RESET << std::endl;
	std::cout << "El valor de a:" << a << " es < que el valor de b:" << b << " Resultado: " << (a < b) << std::endl;
	std::cout << BLUE << "Prueba sobrecarga comparador <=" << RESET << std::endl;
	std::cout << "El valor de c:" << c << " es <= que el valor de a:" << a << " Resultado: " << (c <= a) << std::endl;
	std::cout << "El valor de b:" << b << " es <= que el valor de a:" << a << " Resultado: " << (b <= a) << std::endl;
	std::cout << BLUE << "Prueba sobrecarga comparador >=" << RESET << std::endl;
	std::cout << "El valor de c:" << c << " es >= que el valor de a:" << a << " Resultado: " << (c >= a) << std::endl;
	std::cout << "El valor de b:" << b << " es >= que el valor de a:" << a << " Resultado: " << (b >= a) << std::endl;
	std::cout << BLUE << "Prueba sobrecarga comparador ==" << RESET << std::endl;
	std::cout << "El valor de c:" << c << " es == que el valor de a:" << a << " Resultado: " << (c == a) << std::endl;
	std::cout << "El valor de b:" << b << " es == que el valor de a:" << a << " Resultado: " << (b == a) << std::endl;
	std::cout << BLUE << "Prueba sobrecarga comparador !=" << RESET << std::endl;
	std::cout << "El valor de c:" << c << " es != que el valor de a:" << a << " Resultado: " << (c != a) << std::endl;
	std::cout << "El valor de b:" << b << " es != que el valor de a:" << a << " Resultado: " << (b != a) << std::endl;
}
