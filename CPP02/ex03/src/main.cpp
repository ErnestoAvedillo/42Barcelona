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
	Point a(8, 8);
	Point b(2, 1);
	Point c(1, 2);
	Point d(2, 2);

	std::cout << "Punto a " << a << std::endl;
	std::cout << "Punto b " << b << std::endl;
	std::cout << "Punto c " << c << std::endl;
	std::cout << "Punto d= " << d << std::endl;
	if (p_in_tr(a,b,c,d))
		std::cout << "El punto se encuentra dentro del triángulo " << std::endl;
	else
		std::cout << "El punto se encuentra fuera del triángulo " << std::endl;

	
	return 0;
}