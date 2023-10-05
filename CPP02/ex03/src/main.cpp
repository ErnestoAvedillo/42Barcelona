/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/main.h"

int main( void ) 
{
	Point a(0, 1);
	Point b(1, 0);
	Point c(0, 0);
	Fixed d = prod_escalar(a,b);
	Fixed e (49);
	Triangle t1(a, b, c);

	std::cout << "Punto a " << a << std::endl;
	std::cout << "Punto b " << b << std::endl;
	std::cout << "Punto c " << c << std::endl;
	std::cout << "Valor d= " << d << std::endl;
	std::cout << "Modulo a= " << modulo(a) << std::endl;
	std::cout << "Modulo = " << modulo(c) << std::endl;
	std::cout << "Raiz de e= " << e << " = " << sqrt(e) << std::endl;
	std::cout << "Prod escalar a·b = " << sqrt(Fixed(1)-prod_escalar(a,b)) << std::endl;
	std::cout << "Area del trángulo = " << t1.GetArea() << std::endl;

	return 0;
}