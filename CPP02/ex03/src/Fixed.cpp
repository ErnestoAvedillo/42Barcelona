/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(int val) : _value(val << _bits_dec){}

Fixed::Fixed(float val) : _value(val * (1 << _bits_dec)){}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		this->_value = f.getRawBits();
	return *this;
}
int	Fixed::getRawBits( void ) const
{
	return _value;
}

void Fixed::setRawBits ( int raw )
{
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)_value / (1 << _bits_dec));
}

int Fixed::toInt( void ) const
{
	return (_value >> _bits_dec);
}

std::ostream &operator<<(std::ostream &ost, Fixed const &f)
{
	ost << f.toFloat();
	return ost;
}

//--------------------Sobrecarga operador preincremento----------------
Fixed &Fixed::operator++(void)
{
	++this->_value;
	return *this;
}

//--------------------Sobrecarga operador postincremento----------------
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	++*this;
	return tmp;
}


//--------------------Sobrecarga operador predecremento----------------
Fixed &Fixed::operator--(void)
{
	--this->_value;
	return *this;
}

//--------------------Sobrecarga operador postdecremento----------------
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	--*this;
	return tmp;
}

// -------------------Sobrecarga de los operadores de comparación------------
bool Fixed::operator<(const Fixed &a)
{
	return (this->getRawBits() < a.getRawBits());
}

bool Fixed::operator<=(const Fixed &a)
{
	return (this->getRawBits() <= a.getRawBits());
}

bool Fixed::operator>(const Fixed &a)
{
	return (this->getRawBits() > a.getRawBits());
}

bool Fixed::operator>=(const Fixed &a)
{
	return (this->getRawBits() >= a.getRawBits());
}

bool Fixed::operator==(const Fixed &a)
{
	return (this->getRawBits() == a.getRawBits());
}

bool Fixed::operator!=(const Fixed &a)
{
	return (this->getRawBits() != a.getRawBits());
}

// -------------------Sobrecarga de los operadores aritméticos------------
Fixed Fixed::operator+(const Fixed &a)
{
	Fixed tmp = *this;
	tmp.setRawBits(this->getRawBits() + a.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &a)
{
	Fixed tmp = *this;
	tmp.setRawBits(this->getRawBits() - a.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &a)
{
	Fixed	tmp = *this;
	int	j = this->getRawBits() * a.getRawBits();
	tmp.setRawBits(j >> _bits_dec);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &a)
{
	Fixed tmp = *this;
	int j = (this->getRawBits() << _bits_dec) / (a.getRawBits());
	//std::cout << "result " << j << std::endl;
	tmp.setRawBits(j);
	return (tmp);
}

//--------------------Sobrecarga de las funciones max y min----------------

Fixed max(const Fixed &a, const Fixed &b)
{
	if(a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed min(const Fixed &a, const Fixed &b)
{
	if(a.getRawBits() < b.getRawBits())
		return a;
	return b;
}