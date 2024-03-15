/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:37:45 by marvin            #+#    #+#             */
/*   Updated: 2024/03/15 11:05:54 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iterator>

template<class InputIterator>
void printCont(InputIterator first, InputIterator last)
{
	InputIterator aux = last;
	std::string str = ".";
	if (last - first > 100)
	{
		aux = first + 10;
		str = "[...]";
	}
	while (first < aux)
	{
		std::cout << *first;
		if (first == aux - 1)
			std::cout << str << std::endl;
		else
			std::cout << ", ";
		first++;
	}
}

template <class InputIterator, class T>
InputIterator bin_search(InputIterator first, InputIterator last, T &val)
{
	size_t v_len = last - first;
	size_t pos = v_len / 2;
	InputIterator it1, it2;
	it1 = first + pos;
	it2 = max(it1 - 1, first);
	while (!(*it1 >= val && *it2 <= val) && !(it1 == first && *it1 >= val) && !(it1 == last && *it2 <= val))
	{
		if (it1 != last)
		{
			if (*it1 >= val)
			{
				if (it1 >first + pos)
					it1 = first;
				else
					it1 -= pos;
			}
			else
					it1 += pos;
		}
		else
		{
			if (last > it1 + pos)
				it1 = last;
			else
				it1 -= pos;
		}
		pos = pos / 2 + pos % 2;
		if (it1 > first)
			it2 = it1 - 1;
	}
	return it1;
}

template <typename InputIterator>
static void swapval(InputIterator &it1, InputIterator &it2)
{
	int aux;
	aux = *it1;
	*it1 = *it2;
	*it2 = aux;
	return;
}
#endif

template<class Iterator, typename T>
T PmergeMe(Iterator first, Iterator last, T &vec)
{
	size_t	len_cont = last - first;
	Iterator it1, it2, it3, it4, it5;
	it1 = last - 1;
	if (last < first)
		throw std::runtime_error("First iterator smaller than the second one.");
	else if (last == first + 1)
		return vec;
	if (len_cont == 2)
	{
		if (*first > *it1)
			swapval(first, it1);
		return vec;
	}
	it1 = first;
	it2 = first + len_cont / 2;
	for (size_t i = 0; i < len_cont / 2; i++)
	{
		if (*it1 < *it2)
			swapval(it1, it2);
		it1++;
		it2++;
	}
	it1 = first + len_cont / 2;
	PmergeMe(first, it1, vec);
	PmergeMe(it1, last, vec);
	it3 = first;
	for (it4 = it1; it4 > it3; it4--)
	{
		it5 = it4 - 1;
		swapval(it5, it4);
	}
	it1++;
	it2 =last -1;;
	while (it2 >= it1)
	{
		it3 = bin_search(first, it1 , *it2);
		for (it4 = it2; it4 > it3; it4--)
		{
			it5 = it4 - 1;
			swapval(it5, it4);
		}
		it1++;
	}
	return vec;
}
