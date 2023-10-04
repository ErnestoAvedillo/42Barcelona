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

#ifndef __POINT_HPP
 #define __POINT_HPP
 #include"../inc/Fixed.hpp"
#include <iostream>
class Point
{
    private:
        Fixed _x;
        Fixed _y;
    public:
        Point();
        Point (int valx, int valy);
        Point (float valx, float valy);
        Point (const Point&);
		~Point();
		Fixed GetXCoord( void ) const;
		Fixed GetYCoord( void ) const;
		Point &operator=(const Point&);
        
};
std::ostream &operator<<(std::ostream &, Point const &);

#endif