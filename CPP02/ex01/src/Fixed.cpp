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

Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int val) : _value(val << _bits_dec) 
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(float val) : _value(val * (1 << _bits_dec)) 
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &f)
		this->_value = f.getRawBits();
	return *this;
}
int	Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits ( int raw )
{
	_value = raw;
	//std::cout << "setRawBits member function called" << std::endl;
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
