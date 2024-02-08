/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:53:44 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/08 16:18:05 by eavedill         ###   ########.fr       */
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

Span::Span(Span const &rhs)
{
	if (this == rhs)
		return *this;
	_num = rhs.GetNum()
	return *this;
}

unsigned int Span::GetNum()
{
	return _num;
}

Span &Span::operator=(Span const &rhs)
{
	if (_num != rhs.GetNum())
	{
		_num = rhs.GetNum()
		_vec
	}
}
void Span::addNumber(int N){}
void Span::shortestSpan(){}
void Span::longestSpan(){}