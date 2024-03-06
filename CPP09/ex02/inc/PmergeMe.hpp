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
	it1 = first + pos;
	it2 = max(it1 - 1, first);
	//it2 = min(it1 + 2, last) - 1;
//	printCont(first, last);
	while (!(*it1 >= val && *it2 <= val) && !(it1 == first && *it1 > val) && !(it1 == last && *it2 < val))
	{
//	std::cout << "Posic - " << pos << " punteros it1 " << &it1 << " - it2 " << &it2 << " - first " << &first << " - last " << &last << std::endl;
//	std::cout << "Valor - " << val << " punteros it1 " << *it1 << " - it2 " << *it2 << " - first " << *first << " - last " << *last << std::endl;
//	printCont(first, last);
		if (it1 != last)
		{
			if (*it1 >= val)
			{
			//	if (pos == 1)
			//		it1 = first;
			//	else
					it1 -= pos;
			}
			else
			//	if (pos == 1)
			//		it1 = last;
			//	else
					it1 += pos;
		}
		else
		{
			it1 -= pos;
		}
//		if (pos == 1)
//			pos = 0;
//		else
			pos = pos / 2 + pos % 2;
		it2 = max(it1 - 1, first);
	}
//	std::cout << "Valor - " << val << " punteros it1 " << *it1 << " - it2 " << *it2 << " - first " << *first << " - last " << *last << std::endl;
//	printCont(first, last);
	return it1;
}

template <typename InputIterator>
static void swapval(InputIterator &it1, InputIterator &it2)
{
	int aux;
//	std::cout << "punteros first " << &it1 << " - it1 " << &it2 << std::endl;
//	std::cout << "punteros first " << *it1 << " - it1 " << *it2 << std::endl;
	aux = *it1;
	*it1 = *it2;
	*it2 = aux;
//	std::cout << "punteros first " << &it1 << " - it1 " << &it2 << std::endl;
//	std::cout << "punteros first " << *it1 << " - it1 " << *it2 << std::endl;
	return;
}
#endif

template<class Iterator, typename T>
T PmergeMe(Iterator first, Iterator last, T &vec)
{
	size_t	len_cont = last - first;
	Iterator it1, it2, it3;
//	size_t pos, old_pos;
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
//	printCont(first, it2);
//	printCont(it2, last);
	for (size_t i = 0; i < len_cont / 2; i++)
	{
		if (*it1 < *it2)
			swapval(it1, it2);
		it1++;
		it2++;
	}
	it1 = first + len_cont / 2;
//	std::cout << "control 1 swap1" << std::endl;
//	printCont(first, it1);
//	printCont(it1, last);
//	std::cout << "punteros first " << &first << " - it1 " << &it1 << " - last " << &last << std::endl;
//	std::cout << "punteros first " << *first << " - it1 " << *it1 << " - last " << *last << std::endl;
	PmergeMe(first, it1, vec);
//	std::cout << "punteros first " << &first << " - it1 " << &it1 << " - last " << &last << std::endl;
//	std::cout << "punteros first " << *first << " - it1 " << *it1 << " - last " << *last << std::endl;
	PmergeMe(it1, last, vec);
//	std::cout << "punteros first " << &first << " - it1 " << &it1 << " - last " << &last << std::endl;
//	std::cout << "punteros first " << *first << " - it1 " << *it1 << " - last " << *last << std::endl;
//	printCont(vec.begin(), vec.end());
//	printCont(first, it1);
//	printCont(it1, last);
//	old_pos = 0;
	it3 = first;
//	for (size_t i = 2; ; i++)
//	{
		vec.insert(it3, *it1);
		it1++;
//		std::cout << "punteros it1 " << *it1 << " - it2 " << *it2 << " - it3 " << *it3 << std::endl;
		vec.erase(it1);
//		std::cout << "punteros it1 " << *it1 << " - it2 " << *it2 << " - it3 " << *it3 << std::endl;
//		printCont(vec.begin(), vec.end());
		//pos = std::min(static_cast<size_t>((pow(2, i + 1) + pow(-1, i))) / 3, len_cont - len_cont / 2) - 2;
		it2 =last -1;;
		while (it2 >= it1)
		{
			it3 = bin_search(first, it1 , *it2);
			vec.insert(it3,*it2);
			it2++;
			vec.erase(it2);
			it1++;
			it2--;
		//	if (pos > 0)
		//		pos--;
		//	old_pos++;
		}
		//old_pos = pos;
//		it3 = it1;
//		if (it1 == last)
//			break;
//	}
	return vec;
}
