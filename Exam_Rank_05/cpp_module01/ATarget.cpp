#include "ATarget.hpp"

ATarget::ATarget(){}
ATarget::ATarget(ATarget const &rhs)
{
	*this = rhs;
}
ATarget &ATarget::operator=(ATarget const &rhs)
{
	type = rhs.type;
	return *this;
}
ATarget::ATarget(std::string const &str1)
{
	type = str1;
}
ATarget::~ATarget()
{
}
std::string const & ATarget::getType() const{return type;}
void ATarget::setType (std::string const &str)
{
	type = str;
}

void ATarget::getHitBySpell(ASpell const &sp) const
{
	std::cout << type << " has been " << sp.getEffects() << "!" << std::endl;
}
