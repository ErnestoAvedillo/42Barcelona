/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:53:44 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/09 11:10:22 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span()
{
	_num = 10;
	_vec.reserve(_num);
}

Span::~Span()
{}

Span::Span(unsigned int N)
{
	_num = N;
	_vec.reserve(_num);
}

Span::Span(Span &rhs)
{
	*this = rhs;
}

unsigned int Span::GetSize() const
{
	return _vec.size();
}

unsigned int Span::GetNum() const
{
	return _num;
}

Span &Span::operator=(Span &rhs)
{
	if (this == &rhs)
		return *this;
	if (_num != rhs.GetNum())
	{
		_num = rhs.GetNum();
		_vec.clear();
		_vec.reserve(_num);
	}
	for (std::vector<int>::size_type i = 0; i < _vec.size(); i++)
		_vec[i] = rhs[i];
	return *this;
}

int &Span::operator[](std::vector<int>::size_type i) 
{
	return _vec[i];
}

void Span::addValue(int N) 
{
	if (_vec.size() == _num)
		throw std::runtime_error("Size exceeded.");
	_vec.push_back(N);
}
int Span::getValue(unsigned int i) 
{
	return (_vec.at(i));
}
int Span::shortestSpan()
{
	std::vector<int> aux(_vec);
	
	if (_vec.size() < 2)
		throw std::runtime_error("Operaiton impossible with less than 2 values.");
	std::sort(aux.begin(), aux.end());
	int mindist = aux.at(1) - aux.at(0);

	for (unsigned int i = 1; i < aux.size() - 1; i++)
		if(mindist > (aux.at(i + 1) - aux.at(i)))
			mindist = aux.at(i + 1) - aux.at(i);
	return (mindist);
}

int Span::longestSpan()
{
	std::vector<int> aux(_vec);

	if (_vec.size() < 2)
		throw std::runtime_error("Operaiton impossible with less than 2 values.");
	std::sort(aux.begin(), aux.end());
	return (aux.at(aux.size() - 1) - aux.at(0));
}
