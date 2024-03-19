/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/18 19:23:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp" 


Polymorph::Polymorph():ASpell("Polymorph", "turned into a critter"){}

Polymorph::~Polymorph(){}

ASpell *Polymorph::clone() const
{
	return (new Polymorph());
}
