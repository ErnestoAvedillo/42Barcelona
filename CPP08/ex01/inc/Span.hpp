/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:44:43 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/08 16:11:32 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>

class Span
{
private:
	unsigned int _num;
	std::vector<int> _vec;
public:
	Span();
	~Span();
	Span(int);
	Span(Span const &);
	unsigned int GetNum();
	Span &operator=(Span const &);
	void addNumber(int N);
	void shortestSpan();
	void longestSpan();
};
#endif