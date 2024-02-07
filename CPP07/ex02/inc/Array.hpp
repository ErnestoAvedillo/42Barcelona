/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:58:59 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/07 14:36:20 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template<typename T> 
class Array
{
	private:
		T *_ptr;
		unsigned int _my_size;

	public:
		Array();
		Array(unsigned int);
		~Array();
		Array(const Array &);
		T GetVal(unsigned int n);
		unsigned int GetSize() const;
		Array &operator=(Array const &rhs);
		T &operator[](unsigned int);
		T &operator[](unsigned int n) const;
		void print_all_val();
};

#endif
