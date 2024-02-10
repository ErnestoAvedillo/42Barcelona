/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:34:10 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/09 08:53:32 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <string>
#include <cmath>

template < typename T>
unsigned int easyfind(T &v,int N)
{
	unsigned int pos = v.size(); //=  std::find(v.begin(), v.end(), N);
	std::cout << "Size de vector " << pos << std::endl;
	std::cout << "Listado de valores (<* val > es encontrado en posicion val) " << std::endl;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		std::cout << v.at(i);
		if (v.at(i) == N && pos == v.size())
		{
			pos = i;
			std::cout << "<* " << i << ">";
		}
		else if (v.at(i) == N)
		{
			std::cout << "<* " << i << ">";
		}
		if (i != v.size() - 1)
			std::cout << ",";
		else
			std::cout << ".";
	}
	std::cout << std::endl;
	if (pos != v.size())
		return (pos);
	throw std::runtime_error("Value not found\n");
}
#endif

template <typename T>
void test (T & val, int to_find,std::string text)
{
	srand((unsigned int)time((time_t *)NULL));
	for (int i = 0; i <to_find; i++)
		val.push_back(rand() % to_find);
	int target = rand() % to_find;
	std::cout << "Test with " << text << " of length " << to_find << ". searching the value:" << target << "." << std::endl;
	try
	{
		unsigned int i = easyfind(val, target);
		std::cout << "Value " << target << " found at pos : " << i <<  std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Target " << target << " " << e.what() << '\n';
	}
}
