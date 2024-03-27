#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(Warlock const &);
		Warlock &operator=(Warlock const &);
		std::map<std::string, ASpell*> _book;
	public: 
		~Warlock();
		Warlock(std::string const &,std::string const &);
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle (std::string const &);
		void introduce() const;
		void learnSpell(ASpell *);
		void forgetSpell(std::string);
		void launchSpell(std::string, ATarget const &);
};

#endif
