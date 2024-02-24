/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:20:00 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/24 16:34:04 by eavedill         ###   ########.fr       */
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
		std::stack<T>::operator=(src);
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

	T at(unsigned int N)  {
		if (N > std::stack<T>::c.end() - std::stack<T>::c.begin() || N < 0)
			throw std::runtime_error("Index out of range.");
		iterator mycont = std::stack<T>::c.begin();
		for (unsigned int i = 0; i < N; i++) {++mycont;}
		return *mycont;
		}
};

#endif
