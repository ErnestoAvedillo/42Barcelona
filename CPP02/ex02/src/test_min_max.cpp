/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_min_max.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void test_min_max()
{
	Fixed a(5.44f);
	Fixed b(2.32f);
	Fixed c = max (a, b);
	Fixed d = min (a, b);
	Fixed e(-5.44f);
	Fixed f(-2.32f);
	Fixed g = max (e, f);
	Fixed h = min (e, f);

	std::cout << GREEN << "Prueba de sobrecarga de funciones min y max" << RESET << std::endl;
	std::cout << BLUE << "Prueba sobrecarga operador max" << RESET << std::endl;
	std::cout << "max(a=" << a << " ,b=" << b << ") = " << c << std::endl;
	std::cout << "control max(a=" << a << " ,b=" << b << ") = " << max (a, b) << std::endl;
	std::cout << "max(e=" << e << " ,f=" << f << ") = " << g << std::endl;
	std::cout << "control max(e=" << e << " ,f=" << f << ") = " << max (e, g) << std::endl;
	std::cout << BLUE << "Prueba sobrecarga operador min" << RESET << std::endl;
	std::cout << "min(a=" << a << " ,b=" << b << ") = " << d << std::endl;
	std::cout << "control min(a=" << a << " ,b=" << b << ") = " << min (a, b) << std::endl;
	std::cout << "min(e=" << e << " ,f=" << f << ") = " << h << std::endl;
	std::cout << "control min(e=" << e << " ,f=" << f << ") = " << min (e, g) << std::endl;
}
