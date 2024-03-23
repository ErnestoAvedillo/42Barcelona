
#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"
class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock( Warlock const &);
		Warlock &operator= (Warlock const &);
		SpellBook sp_bk;		
	public:
		Warlock(std::string const &, std::string const &);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &);
		void introduce() const ;
		void learnSpell(ASpell *);
		void forgetSpell(std::string );
		void launchSpell(std::string , ATarget const &);
};

#endif
