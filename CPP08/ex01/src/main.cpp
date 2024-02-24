/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:48:39 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/24 14:50:52 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

static float getValue(std::string str)
{
	int32_t out = 0;

	std::stringstream ss;
	out = 0;
	if (str.empty())
		throw std::runtime_error("Argument not valid.");
	if (str.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Argument not valid.");
	ss << str;
	ss >> out;
	return out; 
}

int main (int av, char **ac)
{
	unsigned int to_find;
	unsigned int to_find1;
	
	if (av < 2)
	{
		to_find = 10;
		to_find1 = 40;
	}
	else if (av < 3)
		try
		{
			std::string value(ac[1]);
			to_find = getValue(value);
			to_find1 = to_find + 30;
		}
		catch (const std::exception &e)
		{
			std::cerr << "No conversion. " << e.what() << '\n';
			return 0;
		}
	else
	{
		try
		{
			std::string value(ac[1]);
			to_find = getValue(value);
			std::string value1(ac[2]);
			to_find1 = getValue(value1);
		}
		catch (const std::exception &e)
		{
			std::cerr << "No conversion. " << e.what() << '\n';
			return 0;
		}
	}
	if (to_find <= 0 || to_find1 <= 0)
	{
		std::cout << "A positive > 0 integer as argument or no argument is possible." << std::endl;
		return 0;
	}
	std::cout << MGENTA "Size of vectors too test: 1sr:" << to_find << "; 2nd : " << to_find1 << RESET << std::endl;

	Span sp(to_find);
	std::cout << "valores añadidos " << std::endl;
	srand((unsigned int)time((time_t *)NULL));
	for (unsigned int i = 0; i < to_find; i++)
	{
		try
		{
			sp.addNumber(rand()% (to_find * 100));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			break;
		}
	}
	try
	{
		sp.printRange(0, to_find);
		std::cout << RED " Test adding more values than " << to_find << "by operator requested"  RESET << std::endl;
		sp.addNumber(rand() % 40);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << GREEN " Visualize all values" RESET << std::endl;
	try
	{
		sp.printRange(0, sp.getSize());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
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
	std::cout << RED " Test the function add range with enough capacity"  RESET << std::endl;
	Span sp2 (to_find1);
	srand((unsigned int)time((time_t *)NULL));
	for (unsigned int i = 0; i < to_find1 - to_find -1; i++)
	{
		try
		{
			sp2.addNumber(rand()% (20 * 100));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			break;
		}
	}	
	try
	{
		std::cout << GREEN " Before adding the first vector"  RESET << std::endl;
		sp2.printRange(0, sp2.getSize());
		sp2.addRange(sp);
		std::cout << MGENTA " After adding the first vector"  RESET << std::endl;
		sp2.printRange(0, sp2.getSize());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << RED " Test the function add range with not enough capacity"  RESET << std::endl;
	Span sp3 (to_find1);
	srand((unsigned int)time((time_t *)NULL));
	for (unsigned int i = 0; i < to_find1 - 1; i++)
	{
		try
		{
			sp3.addNumber(rand()% (20 * 100));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			break;
		}
	}	
	try
	{
		std::cout << GREEN " Before adding the first vector"  RESET << std::endl;
		sp3.printRange(0, sp3.getSize());
		sp3.addRange(sp);
		std::cout << MGENTA " After adding the first vector"  RESET << std::endl;
		sp3.printRange(0, sp3.getSize());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
