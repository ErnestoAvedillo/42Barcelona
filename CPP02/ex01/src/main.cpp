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

int main( int av, char **ac ) 
{
	{
		std::cout << "-------------Subject tests------------------" << std::endl;
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		std::cout << BLUE << "-------------My own tests------------------" << RESET << std::endl;
		Fixed a;
		float c;

		std::cout << BLUE << "Conversion float to fixed and then to integer" << RESET << std::endl;
		if (av < 2)
			c = 35.4235;
		else
		{
			c = std::atof(ac[1]);
		}
		a = c;
		std::cout << "Value in float asigned to c is " << c << std::endl;
		std::cout << "After a (Fixed) = c (Float), value a is = " << a << std::endl;
		std::cout << "Convert a (Fixed) to float " << a.toFloat() << std::endl;
		std::cout << "Convert a(Fixed) to int " << a.toInt() << std::endl;
	}
	return 0;
}
