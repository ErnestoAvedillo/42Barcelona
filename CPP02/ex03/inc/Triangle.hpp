/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TRIANGLE_HPP
 #define __TRIANGLE_HPP
 #include"../inc/Point.hpp"
 #include"../inc/Fixed.hpp"

 class Triangle
 {
	private:
		Point _a;
		Point _b;
		Point _c;

	public:
		Triangle():_a(0,0),_b(0,0),_c(0,0);
		Triangle(Point p1, Point p2, Point p3): _a(p1),_b(p2),_c(p3);
		Fixed &GetArea();
 }
 #endif