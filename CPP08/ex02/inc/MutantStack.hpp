/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:20:00 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/09 21:28:33 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iostream>
#include <iterator>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack<T>() {}
	MutantStack<T>(const MutantStack<T> &src) { *this = src; }
	~MutantStack<T>() {}

	MutantStack<T> &operator=(const MutantStack<T> &src)
	{
		if (this == &src)
			return (*this);
		std::cout << "test" << std::endl;
		std::stack<T>::operator=(src);
		std::cout << "test2" << std::endl;
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return (std::stack<T>::c.begin()); }
	iterator end() { return (std::stack<T>::c.end()); }

	const_iterator begin() const { return (std::stack<T>::c.begin()); }
	const_iterator end() const { return (std::stack<T>::c.end()); }

	reverse_iterator rbegin() { return (std::stack<T>::c.rbegin()); }
	reverse_iterator rend() { return (std::stack<T>::c.rend()); }

	const_reverse_iterator rbegin() const { return (std::stack<T>::c.rbegin()); }
	const_reverse_iterator rend() const { return (std::stack<T>::c.rend()); }
};

#endif
/*
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
private:

public:
	std::stack<T, Container>::MutantStack();
	std::stack<T, Container>::~MutantStack();
	std::stack<T, Container>::MutantStack(MutantStack &){
		*this = rhs;
	}
	MutantStack &operator=(MutantStack &){
		if (this == &rhs)
			return *this;
		*this = rhs return *this;
	};
	std::stack<T, Container>::begin() {return std::begin(c); }
	std::stack<T, Container>::end() { return std::end(c); }

	std::stack<T, Container>::begin() const { return std::begin(c); }
	std::stack<T, Container>::end() const { return std::end(c); }
};

#endif*/
