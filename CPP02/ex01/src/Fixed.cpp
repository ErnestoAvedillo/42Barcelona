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

Fixed::Fixed(const int val) : _value(val << _bits_dec) 
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float val) : _value(val * (1 << _bits_dec)) 
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
	int val;
	int dec_filter = 1 * (1 << (_bits_dec - 1));
	if ((dec_filter & _value) == dec_filter)
		val = (_value >> _bits_dec) + 1;
	else
		val = (_value >> _bits_dec);

	return (val);
}

std::ostream &operator<<(std::ostream &ost, Fixed const &f)
{
	ost << f.toFloat();
	return ost;
}
