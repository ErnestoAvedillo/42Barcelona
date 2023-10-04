/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Point.hpp"

Point::Point()
{
    Fixed _x(0);
    Fixed _y(0);
}

Point::Point (int valx, int valy): _x(valx),_y(valy){}

Point::Point (float valx, float valy): _x(valx),_y(valy){}

Point::Point(const Point &p)
{
	*this = p;
}

Point::~Point(){}

Fixed Point::GetXCoord(void) const
{
	return this->_x;
}
Fixed Point::GetYCoord( void ) const
{
	return this->_y;
}
Point &Point::operator=(const Point &p) const
{
	*this->_x = p.GetXCoord();
	*this->_y = p.GetYCoord();
	return *this;
}

std::ostream &operator<<(std::ostream &ost, Point const &p)
{
	ost << "(" << p.GetXCoord() << "," << p.GetYCoord() << ")";
	return ost;
}
