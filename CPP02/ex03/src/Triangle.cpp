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

 Fixed &Triangle::GetArea()
 {
    Fixed high = modulo(this->_a,this->_b);
    Fixed base = modulo(this->_a, this->_c);
    Fixed alfa = prod_escalar
 }
