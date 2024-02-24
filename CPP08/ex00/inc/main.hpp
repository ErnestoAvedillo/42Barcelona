/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:34:10 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/24 13:17:53 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include "../inc/colors.h"

template < typename T>
unsigned int easyfind(T &v,int N)
{
	typename T::iterator posmax;
	typename T::iterator pos;
	posmax = v.end(); 
	pos =  std::find(v.begin(), v.end(), N);
	std::cout << "Size de vector " << posmax - v.begin() << std::endl;
	if (pos - v.begin() != posmax - v.begin())
	{
		std::cout << "The first position where is the value " << N << " is :" GREEN << pos - v.begin() << RESET << std::endl;
		return (pos - v.begin());
	}
	throw std::runtime_error("Value not found\n");
}
#endif

template <typename T>
void printvalues (T &v)
{
	typename T::iterator pos;
	std::cout << MGENTA "Printing values of container   :" RESET;
	for (unsigned int i = 0; i < (v.end() - v.begin()); i++)
	{
		std::cout << v.at(i);
		if (i == v.end() - v.begin() - 1)
			std::cout << ".\n";
		else
			std::cout << ", ";
	}
}

template <typename T>
void test (T & val, int to_find,std::string text)
{
	srand((unsigned int)time((time_t *)NULL));
	for (int i = 0; i <to_find; i++)
		val.push_back(rand() % to_find);
	int target = rand() % to_find;
	std::cout << CYAN "Test with " << YELLOW << text << CYAN << " of length " << to_find << ". searching the value:" << target << "." RESET << std::endl;
	try
	{
		printvalues (val);
		unsigned int i = easyfind(val, target);
		std::cout << "Value " << target << " found at pos : " << i <<  std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Target " << target << " " << e.what() << '\n';
	}
}
