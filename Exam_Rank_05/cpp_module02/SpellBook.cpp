/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/19 21:59:49 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp" 
#include <map>

SpellBook::SpellBook(){}
SpellBook::SpellBook(SpellBook const &rhs)
{ *this = rhs;}
SpellBook &SpellBook::operator=(SpellBook const &rhs)
{
	this->_name = rhs.getEffects();
	this->_effects = rhs.getName();
	return *this;
}

SpellBook::SpellBook(std::string &myname, std::string &myeffects)
{
	this->_name = myname;
	this->_effects = myeffects;
}
SpellBook::SpellBook(const std::string &myname, const std::string &myeffects)
{
	this->_name = myname;
	this->_effects = myeffects;
}
SpellBook::~SpellBook()
{
}

void learnSpell(ASpell*)
{
	
}
void forgetSpell(string const &){}
ASpell* createSpell(string const &){}
