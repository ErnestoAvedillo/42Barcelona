/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/18 19:27:21 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brickwall.hpp" 


Brickwall::Brickwall():ATarget("Inconspicuous Red-brick Wall"){}
Brickwall::~Brickwall()
{}

ATarget *Brickwall::clone() const
{
	return (new Brickwall()); 
}
