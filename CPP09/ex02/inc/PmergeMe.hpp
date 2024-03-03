/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:37:45 by marvin            #+#    #+#             */
/*   Updated: 2024/03/03 19:33:53 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iterator>
/*
class PmergeMe
{
private:
	std::deque<int> _mylist;

public:
	PmergeMe();
	PmergeMe(std::deque<int>);
	PmergeMe(PmergeMe const &);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &);
	void sort();
	std::deque<int> getList();
	void printList();
	void AddVal(int);
	size_t size();
};
*/
template<class InputIterator>
void printCont(InputIterator first, InputIterator last)
{
	while (first < last)
	{
		std::cout << *first;
		if (first == last - 1)
			std::cout << "." << std::endl;
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
	it1 += pos;
	it2 = it1 + 2;
	while (!(*it1 <= val && *it2 >= val))
	{
		if (*it1 >= val)
			it1 += pos / 2;
		else
			it1 += pos / 2;
		it2 = it1 + 1;
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
	Iterator it1;
	Iterator it2;
	size_t pos, old_pos;
	if (last < first)
		throw std::runtime_error("First iterator smaller than the second one.");
	else if (last == first + 1)
		return vec;
	if (len_cont == 2)
	{
		if (*first > *last)
			swapval(first, last);
		return vec;
	}
	it1 = first;
	it2 = first + len_cont / 2;
	printCont(first, it2);
	printCont(it2, last);
	for (size_t i = 0; i < len_cont / 2; i++)
	{
		if (*it1 < *it2)
			swapval(it1, it2);
		it1++;
		it2++;
	}
	it1 = first + len_cont / 2;
	std::cout << "control 1 swap1" << std::endl;
	printCont(first, it1);
	printCont(it1, last);
	PmergeMe(first, it1, vec);
	PmergeMe(it1, last, vec);
	printCont(first, it1);
	printCont(it1, last);
	old_pos = 0;
	for (size_t i = 1; ; i++)
	{
		pos = std::min(static_cast<size_t>((pow(2, i + 1) + pow(-1, i))) / 3, len_cont - len_cont / 2);
		it2 = it1 + old_pos;
		vec.insert(it2, *it1);
		vec.erase(it1);
		while (pos > old_pos + 1)
		{
			it1 = first + old_pos + 1;
			it2 = first + pos;
			it2 = bin_search(first, it1 , *it2);
			vec.insert(it2,*it1);
			vec.erase(it1);
			pos--;
			old_pos++;
		}
		old_pos = pos;
	}
	return vec;
}
