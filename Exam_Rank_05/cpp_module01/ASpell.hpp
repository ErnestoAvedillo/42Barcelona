#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

class ATarget;
#include "ATarget.hpp"

class ASpell
{
	private:
		std::string name;
		std::string effects;
	public: 
		ASpell();
		ASpell(ASpell const &);
		ASpell &operator=(ASpell const &);
		virtual ~ASpell();
		ASpell(std::string const &,std::string const &);
		std::string getName() const;
		std::string getEffects() const;
		void setEffects (std::string const &);
		virtual ASpell *clone() const = 0;
		void launch(ATarget const &) const;
};

#endif
