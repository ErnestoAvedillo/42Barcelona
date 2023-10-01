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

class Fixed
{
	private:
		static const int	w = 8;
		const int			b;
	public:
		Fixed();
		Fixed(int);
		Fixed(const Fixed&);
		void operator = (Fixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits ( int const raw );

};
#endif