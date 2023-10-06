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
	Point a(6, 6);
	Point b(2, 0);
	Point c(0, 2);
	Point d(2, 2);

	Triangle t1(a, b, c);
	Triangle t2(d, b, c);
	Triangle t3(a, d, c);
	Triangle t4(a, b, d);

	std::cout << "Punto a " << a << std::endl;
	std::cout << "Punto b " << b << std::endl;
	std::cout << "Punto c " << c << std::endl;
	std::cout << "Punto d= " << d << std::endl;
	std::cout << "Area del trángulo 1= " << t1.GetArea() << std::endl;
	std::cout << "Area del trángulo 2= " << t2.GetArea() << std::endl;
	std::cout << "Area del trángulo 3= " << t3.GetArea() << std::endl;
	std::cout << "Area del trángulo 4= " << t4.GetArea() << std::endl;
	Fixed sum_area = t2.GetArea() + t3.GetArea() +t4.GetArea();
	std::cout << "Area total trángulo 2-3-4= " << sum_area << std::endl;
	if (sum_area <= t1.GetArea())
		std::cout << "El punto se encuentra dentro del triángulo " << std::endl;
	else
		std::cout << "El punto se encuentra fuera del triángulo " << std::endl;

	
	return 0;
}