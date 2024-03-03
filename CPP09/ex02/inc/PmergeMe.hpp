/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:37:45 by marvin            #+#    #+#             */
/*   Updated: 2024/03/02 22:42:15 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>

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
};

template <class InputIterator, class T>
InputIterator bin_search(InputIterator first, InputIterator last, const T &val)
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

#endif
