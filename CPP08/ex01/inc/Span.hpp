/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:44:43 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/18 13:02:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
class Span
{
private:
	unsigned int _num;
	std::vector<int> _vec;
public:
	Span();
	~Span();
	Span(unsigned int);
	Span(Span &);
	unsigned int getNum() const;
	unsigned int getSize() const;
	Span &operator=(Span &);
	int &operator[](std::vector<int>::size_type ) ;
	void addNumber(int N);
	int getValue(unsigned int i);
	int shortestSpan();
	int longestSpan();
	void addRange(Span &);
	void printRange(unsigned int, unsigned int);

};
#endif
