/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:33:32 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/09 08:50:20 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int main(int av, char **ac)
{
	int to_find;
	if (av < 2)
		to_find = 5;
	else
	{
		try
		{
			std::string value(ac[1]);
			to_find = std::stoi(value);	
			if (to_find <= 10)
			{
				std::cout << "A positive > 0 integer as argument or no argument is possible." << std::endl;
				return 0;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << "No conversion " << e.what() << " to int possible, Bye." << '\n';
			return 0;
		}
	}	
	std::vector<int> val;
	test (val, to_find, "vectors");
	std::deque<int> val2;
	test (val2, to_find, "deque");
}
