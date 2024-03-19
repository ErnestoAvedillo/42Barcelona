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
	if (sp)
		_aspell.insert(std::pair<std::string,ASpell*>(sp->getName(),sp->clone()));
}

void Warlock::forgetSpell(std::string const &str) 
{
	std::map<std::string, ASpell *>::iterator it = _aspell.find(str);
	if (it != _aspell.end())
	{	
		delete it->second;
		_aspell.erase(it);
	}
	
}
void Warlock::launchSpell(std::string const &str, ATarget const &tg)
{
	std::map<std::string, ASpell *>::iterator it = _aspell.find(str);
	if (it != _aspell.end())
	{	
		it->second->launch(tg);
	}

}
