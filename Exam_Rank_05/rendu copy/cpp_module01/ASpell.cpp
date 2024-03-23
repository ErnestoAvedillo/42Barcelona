#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::ASpell( ASpell &rhs)
{
	*this= rhs;
}

ASpell &ASpell::operator= (ASpell const &rhs)
{
	_name = rhs._name;
	_effects = rhs._effects;
	return *this;
}

ASpell::ASpell(std::string const &str1, std::string const &str2)
{
	_name = str1;
	_effects = str2;
}

ASpell::~ASpell(){}

std::string ASpell::getName() const{return (_name);}

std::string ASpell::getEffects() const{return (_effects);}

void ASpell::setEffects(std::string const &str)
{
	_effects = str;
}

void ASpell::launch(ATarget const &rhs)const
{
	rhs.getHitBySpell(*this);
}
