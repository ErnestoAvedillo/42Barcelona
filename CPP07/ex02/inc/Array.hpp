/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:58:59 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/07 14:25:58 by eavedill         ###   ########.fr       */
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

template <typename T>
Array<T>::Array()
{
	_ptr = NULL;
	_my_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	if (n == 0)
		_ptr = NULL;
	else
	{
		_my_size = n;
		_ptr = new T[n];
		for (unsigned int i = 0; i < _my_size; i++)
			_ptr[i] = 0;
	}
}

template <typename T>
Array<T>::Array(const Array<T> &rhs)
{
	this->_ptr = new T[1];
	this->_ptr[0] = 0;
	_my_size = 1;
	*this = rhs;
}

template <typename T>
Array<T>::~Array()
{
	if (_ptr)
		delete[] _ptr;
}

template <typename T>
unsigned int Array<T>::GetSize() const
{
	return _my_size;
}

template <typename T>
T Array<T>::GetVal(unsigned int n)
{
	return this->_ptr[n];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this == &rhs)
		return *this;
	if (_my_size != rhs.GetSize())
	{
		_my_size = rhs.GetSize();
		if (_ptr)
			delete []this->_ptr;
		if(_my_size == 0)
			this->_ptr = NULL;
		else
			this->_ptr = new T[_my_size];
	}
	for (unsigned int i = 0; i < _my_size; i++)
		this->_ptr[i] = rhs[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (!this->_ptr)
		throw std::runtime_error("NULL array in class defined!");
	if (n >= _my_size || n < 0)
		throw std::runtime_error("index outside limits!");
	return (this->_ptr[n]);
}

template <typename T>
T &Array<T>::operator[](unsigned int n) const
{
	if (!this->_ptr)
		throw std::runtime_error("NULL array in class defined!");
	if (n >= _my_size)
		throw std::runtime_error("index outside limits!");
	return (this->_ptr[n]);
}

template <typename T>
void Array<T>::print_all_val()
{
	if (!_ptr)
	{
		std::cout << "NULL array in class defined!" << std::endl;
		return;
	}
	for (unsigned int i = 0; i < _my_size; i++)
	{
		if (i == _my_size - 1)
			std::cout << _ptr[i];
		else
			std::cout << _ptr[i] << "; ";
	}
	std::cout << std::endl;
}
#endif
