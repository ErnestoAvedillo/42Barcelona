/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/18 19:24:32 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp" 


Fireball::Fireball():ASpell("Fireball", "burnt to a crisp"){}

Fireball::~Fireball(){}

ASpell *Fireball::clone() const
{
	return (new Fireball());
}
