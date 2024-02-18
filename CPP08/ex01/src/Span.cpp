/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:53:44 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/18 17:27:06 by eavedill         ###   ########.fr       */
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

unsigned int Span::getSize() const
{
	return static_cast<unsigned int>(_vec.size());
}

unsigned int Span::getNum() const
{
	return _num;
}

Span &Span::operator=(Span &rhs)
{
	if (this == &rhs)
		return *this;
	if (_num != rhs.getNum())
	{
		_num = rhs.getNum();
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

void Span::addNumber(int N) 
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

void Span::addRange(Span &rhs)
{
	if (this->getSize() + rhs.getSize() > _num)
		throw std::runtime_error("Not enoug space into the vector");
	int aux = std::max(this->_num - this->getSize(), rhs.getSize());
	for(int i = 0; i < aux - 1; i++)
		this->_vec.push_back(rhs.getValue(i));

}

void Span::printRange(unsigned int N1, unsigned int N2)
{
	if (N1 > _num - 1)
	{
		std::cerr << "Nothing to print." << N1 << "greater than vector length " << _num << std::endl;
		throw std::runtime_error ("Nothing to be done.");
	}
	if (N1 > N2)
	{
		std::cerr << "Nothing to print.Second parameter " << N2 << "greater than first parameter " << N1 << std::endl;
		throw std::runtime_error ("Nothing to be done.");
	}
	unsigned int aux = std::min(N2, _num);
	for (unsigned int i = N1; i< aux; i++)
	{
		std::cout << this->getValue(i);
		if (i == aux - 1)
			std::cout << "." << std::endl;
		else
			std::cout << ", ";
	}	
	
}
