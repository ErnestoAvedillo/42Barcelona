/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:33:32 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/08 15:37:32 by eavedill         ###   ########.fr       */
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
		}
		catch(const std::exception& e)
		{
			std::cerr << "No conversion to int possible Bye." << '\n';
			std::cerr << e.what() << '\n';
			return 0;
		}
	}	
	std::vector<int> val;
	test (val, to_find, "Test with vectors");
	std::deque<int> val2;
	test (val2, to_find, "Test with deque");
	std::list<int> val3;
	test (val2, to_find, "Test with deque");
}
