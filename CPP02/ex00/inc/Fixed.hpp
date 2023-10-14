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

class Fixed
{
	private:
		static  const int	_bits_dec = 8;
		int					_value;
	public:
		Fixed();
		Fixed(const Fixed&);
		~Fixed();
		void operator = (const Fixed &);
		int getRawBits(void) const;
		void setRawBits ( int const raw );

};
#endif
