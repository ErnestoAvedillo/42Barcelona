/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:37:59 by marvin            #+#    #+#             */
/*   Updated: 2024/03/02 22:45:25 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/*
static void swapval(int *it1, int *it2)
{
	int aux;
	if (*it1 > *it2)
		return;
	aux = *it2;
	*it1 = *it2;
	*it2 = aux;
	return;
}
*/

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(std::deque<int> lista)
{
	_mylist = lista;
}

PmergeMe::PmergeMe(PmergeMe const &rhs)
{
	*this = rhs;
}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator= (PmergeMe const &rhs)
{
	_mylist = rhs._mylist;
	return *this;
}

void PmergeMe::sort(){
	std::deque<int> lst1, lst2, out;
	std::deque<int>::iterator it1 = lst1.begin();
	std::deque<int>::iterator it2 = lst1.begin();
	size_t pos, old_pos;

	lst1.insert(it1, _mylist.begin(), _mylist.begin() + _mylist.size() / 2);
	lst2.insert(it2, _mylist.begin() + _mylist.size() / 2 + 1, _mylist.end());
	for (size_t i = 0; i < lst1.size(); i++)
		swap(it1, it2);
	if (lst1.size() == 2 && lst1.at(0) < lst1.at(1))
	{
		it2 = it1 + 1;
		swap(it1, it2);
	}
	else
	{
		PmergeMe	sublst(lst1);
		sublst.sort();
	}
	out.push_back(lst1.at(0));
	out.push_back(lst2.at(0));
	old_pos = 0;
	for (size_t i = 0; i < lst2.size(); i++)
	{
		pos = std::min(static_cast<size_t>((pow(2, i + 1) + pow(-1, i))) / 3, lst2.size());
		if (pos > lst2.size())
			pos = lst2.size();
		for (size_t k = old_pos + 1; k >= pos; k--)
		{
			out.push_back(lst1.at(k));
		}		
		for (size_t j = pos; j >= pos; j--)
		{
			it1 = bin_search(out.begin(), out.end(), lst2.at(pos));
			out.insert(it1,lst2.at(pos));
		}
		old_pos = pos;
	}
	_mylist = out;
}

std::deque<int> PmergeMe::getList()
{
	return (_mylist);
}

void PmergeMe::printList()
{
	size_t ln = _mylist.size();
	
	for (size_t i = 0; i < ln; i++)
	{
		std::cout << _mylist.at(i);
		if (i == ln - 1)
			std::cout << "." << std::endl;
		else
			std::cout << ", ";
	}
}

void PmergeMe::AddVal(int val)
{
	_mylist.push_back(val);
}
