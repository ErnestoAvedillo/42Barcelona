#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::ASpell(ASpell const &rhs)
{
	*this = rhs;
}
ASpell &ASpell::operator=(ASpell const &rhs)
{
	name = rhs.name;
	effects = rhs.effects;
	return *this;
}
ASpell::ASpell(std::string const &str1,std::string const &str2)
{
	name = str1;
	effects = str2;
}
ASpell::~ASpell()
{
}
std::string ASpell::getName() const{return name;}
std::string ASpell::getEffects() const{return effects;}
void ASpell::setEffects (std::string const &str)
{
	effects = str;
}
void ASpell::launch(ATarget const &tg) const
{
	tg.getHitBySpell(*this);
}
