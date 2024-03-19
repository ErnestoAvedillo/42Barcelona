/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/18 19:43:30 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
class SpellBook;
#include "ATarget.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell*> _book;
		SpellBook(SpellBook const &);

	public:
		SpellBook();
		SpellBook(std::string &, std::string &);
		SpellBook(const std::string &, const std::string &);
		SpellBook &operator=(SpellBook const &);
		virtual ~SpellBook();
		std::string const &getName() const;
		std::string const &getEffects() const;
		void learnSpell(ASpell*);
		void forgetSpell(string const &);
		ASpell* createSpell(string const &);
};

#endif
