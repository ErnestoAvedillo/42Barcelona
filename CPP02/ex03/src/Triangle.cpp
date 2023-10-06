/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include"../inc/Triangle.hpp"
 #include"../inc/main.h"

Triangle::Triangle() : _a(0, 0), _b(0, 0), _c(0, 0) {};
Triangle::Triangle(Point p1, Point p2, Point p3) : _a(p1), _b(p2), _c(p3) {};

Fixed Triangle::GetArea()
{
   Point v1 = this->_b - this->_a;
   Point v2 = this->_c - this->_a;
   Fixed high = modulo(v1);
   Fixed base = modulo(v2);
   Fixed cos = prod_escalar(v1,v2) / base / high;
   Fixed sen = sqrt( (Fixed) 1 - cos * cos);
   //std::cout << "valores " << sen << "-" << cos << "-" << high << "-" << base << std::endl;
   Fixed area = high * sen * base / (Fixed)2;
   return (area);
}
