#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
class ASpell;
#include "ASpell.hpp"
class ATarget
{
	private:
		std::string type;
	public: 
		ATarget();
		ATarget(ATarget const &);
		ATarget &operator=(ATarget const &);
		virtual ~ATarget();
		ATarget(std::string const &);
		std::string const &getType() const;
		void setType (std::string const &);
		virtual ATarget *clone() const = 0;
		void getHitBySpell(ASpell const &)const;
};

#endif
