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
	Point a(0, 0);
	Point b(2, 0);
	Point c(0, 2);
	Point d(1, 1);
	Point e(0.5f, 0.5f);
	Point f(2, 2);

	std::cout << "Punto a " << a << std::endl;
	std::cout << "Punto b " << b << std::endl;
	std::cout << "Punto c " << c << std::endl;
	std::cout << "Punto d= " << d << std::endl;
	std::cout << "Punto e= " << d << std::endl;
	std::cout << "Punto f= " << d << std::endl;
	if (p_in_tr(a,b,c,d))
		std::cout << "El punto d se encuentra dentro del triángulo " << std::endl;
	else
		std::cout << "El punto d se encuentra fuera del triángulo " << std::endl;
	if (p_in_tr(a,b,c,e))
		std::cout << "El punto e se encuentra dentro del triángulo " << std::endl;
	else
		std::cout << "El punto e se encuentra fuera del triángulo " << std::endl;
	if (p_in_tr(a,b,c,f))
		std::cout << "El punto f se encuentra dentro del triángulo " << std::endl;
	else
		std::cout << "El punto f se encuentra fuera del triángulo " << std::endl;

	
	return 0;
}
