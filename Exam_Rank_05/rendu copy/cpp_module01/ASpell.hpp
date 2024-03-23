
#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"
class ATarget;

	
class ASpell
{
	private:
		std::string _name;
		std::string _effects;
	public:
		ASpell();
		ASpell( ASpell &);
		ASpell &operator= (ASpell const &);
		ASpell(std::string const &, std::string const &);
		virtual ~ASpell();
		std::string getName() const;
		std::string getEffects() const;
		void setEffects(std::string const &);
		virtual ASpell *clone() const = 0;
		void launch(ATarget const &) const;
};


#endif
