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

#ifndef __FIXED_HPP
 #define __FIXED_HPP
#include <iostream>
#include <cmath>


class Fixed
{
	private:
		static const int	_bits_dec = 12;
		int					_value;
	public:
		Fixed();
		Fixed(int);
		Fixed(float);
		Fixed(const Fixed&);
		~Fixed();
		Fixed &operator=(const Fixed &);
		int getBitsDec(void) const;
		int getRawBits(void) const;
		void setRawBits ( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		//-----operadores de incremento decremento-----
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		//------operadores de comparación.
		bool operator<(const Fixed &);
		bool operator<=(const Fixed &);
		bool operator>(const Fixed &);
		bool operator>=(const Fixed &);
		bool operator==(const Fixed &);
		bool operator!=(const Fixed &);
		//------operadores de aritméticos.
		Fixed operator+(const Fixed &);
		Fixed operator-(const Fixed &);
		Fixed operator*(const Fixed &);
		Fixed operator/(const Fixed &);
};

std::ostream &operator<<(std::ostream &, Fixed const &);
Fixed max(const Fixed&, const Fixed&);
Fixed min(const Fixed&, const Fixed&);
Fixed sqrt(const Fixed&);
#endif
