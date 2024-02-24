/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:33:32 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/24 13:28:52 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

static float getValue(std::string str)
{
	int32_t out = 0;

	std::stringstream ss;
	out = 0;
	if (str.empty())
		return out;
	if (str.find_first_not_of("0123456789") != std::string::npos)
		return out;
	ss << str;
	ss >> out;
	return out; 
}

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
			to_find = getValue(value);
			if (to_find <= 0)
			{
				std::cout << "Argument " << value << "not valid." << std::endl;
				std::cout << "Only an integer > 0 is valid.(Only numbers)" << std::endl;
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
