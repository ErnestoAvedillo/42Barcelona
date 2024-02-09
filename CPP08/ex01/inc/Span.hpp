/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:44:43 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/09 10:56:34 by eavedill         ###   ########.fr       */
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
	unsigned int GetNum() const;
	unsigned int GetSize() const;
	Span &operator=(Span &);
	int &operator[](std::vector<int>::size_type ) ;
	void addValue(int N);
	int getValue(unsigned int i);
	int shortestSpan();
	int longestSpan();
};
#endif
