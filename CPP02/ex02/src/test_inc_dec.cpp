/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_inc_dec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
