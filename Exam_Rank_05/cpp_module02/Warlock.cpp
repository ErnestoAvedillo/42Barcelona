/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/17 11:36:26 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp" 


Warlock::Warlock(){}
Warlock::Warlock(Warlock const &rhs)
{ *this = rhs;}
Warlock &Warlock::operator=(Warlock const &rhs)
{
	this->_name = rhs.getTitle();
	this->_title = rhs.getName();
	return *this;
}

Warlock::Warlock(std::string &myname, std::string &mytitle)
{
	this->_name = myname;
	this->_title = mytitle;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::Warlock(const std::string &myname, const std::string &mytitle)
{
	this->_name = myname;
	this->_title = mytitle;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}
std::string const &Warlock::getName() const
{ return _name;}
std::string const &Warlock::getTitle() const
{ return _title;}
void Warlock::setTitle(std::string &str)
{ _title = str;}
void Warlock::setTitle(const std::string &str)
{ _title = str;}
void Warlock::introduce() const
{ 
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *sp) 
{
	_spellBook.learnSpell(sp);
}

void Warlock::forgetSpell(std::string const &str) 
{
	_spellBook.forgetSpell(str);	
}
void Warlock::launchSpell(std::string const &str, ATarget const &tg)
{
	ASpell *sp = _spellBook.createSpell(str);

	sp->launch(tg);
}
