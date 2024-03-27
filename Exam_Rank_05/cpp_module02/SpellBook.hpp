#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp" 

class SpellBook
{
	private:
		std::map<std::string, ASpell*> _book;	
	public: 
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);

};

#endif
