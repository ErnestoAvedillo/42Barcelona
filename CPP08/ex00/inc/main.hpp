/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:34:10 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/08 15:31:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>

template < typename T>
typename T::iterator easyfind(T &v,int N)
{
	typename T::iterator pos =  std::find(v.begin(), v.end(), N);
	if (pos != v.end())
		return (pos);
	throw std::runtime_error("Value not found\n");
}
#endif

template <typename T>
void test (T & val, int to_find,std::string text)
{
	std::cout << text << std::endl;
	srand((unsigned int)time((time_t *)NULL));
	for (int i = 0; i < 20; i++)
		val.push_back(rand() % to_find);
	int target = rand() % to_find;
	try
	{
		typename T::iterator i = easyfind(val, rand() % to_find);
		std::cout << "Value " << target << " found at pos : " << (i - val.begin()) <<  std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Target " << target << " " << e.what() << '\n';
	}
}
