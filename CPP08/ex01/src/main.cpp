/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:48:39 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/09 11:45:30 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int main (int av, char **ac)
{
	unsigned int to_find;
	if (av < 2)
		to_find = 1;
	else
	{
		try
		{
			std::string value(ac[1]);
			to_find = std::stoi(value);
			if (to_find <= 0)
			{
				std::cout << "A positive > 0 integer as argument or no argument is possible." << std::endl;
				return 0;
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << "No conversion " << e.what() << " to int possible, Bye." << '\n';
			return 0;
		}
	}
	Span sp(to_find);
	std::cout << "valores añadidos " << std::endl;
	srand((unsigned int)time((time_t *)NULL));
	for (unsigned int i = 0; i < to_find; i++)
	{
		sp.addValue(rand() % to_find * 100);
		std::cout << sp.getValue(i);
		if (i == to_find - 1)
			std::cout << "." << std::endl;
		else
			std::cout << ", ";
	}
	try
	{
		std::cout << RED " Test adding more values than " << to_find << "by operator requested"  RESET << std::endl;
		sp.addValue(rand() % 40);
	}
	catch (const std::exception &e)
	{
		std::cout << " Vector oversized." << e.what();
	}
	std::cout << std::endl;
	std::cout << GREEN " Visualize all values" RESET << std::endl;
	for (unsigned int i = 0; i < sp.GetSize(); i++)
	{
		std::cout << "pos " << i << " = " << sp.getValue(i) << ", ";
	}
	std::cout << std::endl;

	std::cout << GREEN " Getting longest and shortest" RESET << std::endl;
	try
	{
		std::cout << "The longest span is: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "The shortest span is: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
