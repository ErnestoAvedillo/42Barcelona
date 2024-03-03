/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:37:59 by marvin            #+#    #+#             */
/*   Updated: 2024/03/03 18:53:54 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
/*
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
	std::deque<int>::iterator it2 = lst2.begin();
	size_t pos, old_pos;

	lst1.insert(it1, _mylist.begin(), _mylist.begin() + _mylist.size() / 2);
	lst2.insert(it2, _mylist.begin() + _mylist.size() / 2, _mylist.end());
	it1 = lst1.begin();	
	it2 = lst2.begin();	
	printCont(lst1.begin(), lst1.end());
	printCont(lst2.begin(), lst2.end());
	for (size_t i = 0; i < lst1.size(); i++)
	{
		if (*it1 < *it2)
			swapval(it1, it2);
		it1++;
		it2++;
	}
	std::cout << "control 1 swap1" << std::endl;
	printCont(lst1.begin(), lst1.end());
	printCont(lst2.begin(), lst2.end());
	if (lst1.size() == 2)
	{
		if(lst1.at(0) > lst1.at(1))
		{
			std::cout << "control 2 swap2 - " << *it1 << " - " << *it2 <<  std::endl;
			it1 = lst1.begin();
			it2 = it1 + 1;
			swapval(it1, it2);
			printCont(lst1.begin(), lst1.end());
			printCont(lst2.begin(), lst2.end());
		}
	}
	else
	{
		PmergeMe	sublst(lst1);
		sublst.sort();
	}
	std::cout << "control out - " << *it1 << " - " << *it2 <<  std::endl;
	out.push_back(lst2.at(0));
	out.push_back(lst1.at(0));
	out.push_back(lst1.at(1));
	printCont(out.begin(), out.end());
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
	printCont(_mylist.begin(), _mylist.end());
}

void PmergeMe::AddVal(int val)
{
	_mylist.push_back(val);
}

size_t PmergeMe::size()
{
	return (_mylist.size());
}
*/
