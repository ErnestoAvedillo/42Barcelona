/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/17 11:33:17 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp" 


ASpell::ASpell(){}
ASpell::ASpell(ASpell const &rhs)
{ *this = rhs;}
ASpell &ASpell::operator=(ASpell const &rhs)
{
	this->_name = rhs.getEffects();
	this->_effects = rhs.getName();
	return *this;
}

ASpell::ASpell(std::string &myname, std::string &myeffects)
{
	this->_name = myname;
	this->_effects = myeffects;
}
ASpell::ASpell(const std::string &myname, const std::string &myeffects)
{
	this->_name = myname;
	this->_effects = myeffects;
}
ASpell::~ASpell()
{
}
std::string const &ASpell::getName() const
{ return _name;}
std::string const &ASpell::getEffects() const
{ return _effects;}

void ASpell::launch(ATarget const &rhs)
{
	rhs.getHitBySpell(*this);
}
