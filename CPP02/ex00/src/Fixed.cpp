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

Fixed::Fixed()
{
	b = 0;
}

Fixed::Fixed(int raw): b(raw){}

Fixed::~Fixed(){}

void Fixed::Fixed(const Fixed& f)
{
	f.setRawBits(this->b);
}

void Fixed::operator = (Fixed f)
{
	f.b = this->b;
}

int	Fixed::getRawBits( void ) const
{
	return b;
}

void Fixed::setRawBits ( int const raw )
{
	b = raw;
}