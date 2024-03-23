
#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>
	
class SpellBook
{
	private:
		std::map<std::string, ASpell*> _book;
	public:
		SpellBook();
		SpellBook(ASpell *);
		~SpellBook();
		void learnSpell(ASpell *);
		void forgetSpell(std::string );
		void launchSpell(std::string , ATarget const &);};


#endif
