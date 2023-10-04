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

void print_help()
{
	std::cout << "options for testing" << std::endl;
	std::cout << "'comp'- to test the compare operartors" << std::endl;
	std::cout << "'inc_dec'- to test the increment decrement operators" << std::endl;
	std::cout << "'aritm'- to test the arithmetic operators" << std::endl;
	std::cout << "'min_max'- to test the min max functions" << std::endl;
}

int main( int av, char **ac ) 
{
	std::string tests[] = {"comp", "inc_dec", "aritm", "min_max"};
	void (*test_func[])() = {&test_comp, &test_inc_dec, &test_aritm, &test_min_max};

	if (av < 2)
		for (int i = 0; i < 4; i++)
			(*test_func[i])();
	else
	{
		std::string arg = ac[1];
		if (arg == "-h")
			print_help();
		for (int j = 1; j < av; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (tests[i] == ac[j])
					(*test_func[i])();
			}
		}	
	}
// std::cout << b << std::endl;
// std::cout << Fixed::max(a, b) << std::endl;
return 0;
}