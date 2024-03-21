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

SpellBook::SpellBook(){}

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell*sp)
{
	if (sp)
		_book.insert(std::pair<std::string,ASpell*>(sp->getName(),sp->clone()));
}
void SpellBook::forgetSpell(std::string const &str)
{
	std::map<std::string, ASpell*>::iterator it = _book.find (str);
	if (it != _book.end())
	{
		delete it->second;
		_book.erase(it);
	}

}
ASpell* SpellBook::createSpell(std::string const &str)
{
	std::map<std::string, ASpell*>::iterator it = _book.find (str);
	if (it != _book.end())
		return (it->second);
	else return NULL;
}
