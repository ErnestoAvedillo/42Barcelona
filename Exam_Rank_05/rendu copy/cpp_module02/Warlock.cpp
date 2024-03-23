#include "Warlock.hpp"

Warlock::Warlock(){}
Warlock::Warlock( Warlock const &rhs)
{
	*this = rhs;
}
Warlock &Warlock::operator= (Warlock const &rhs)
{
	_name = rhs._name;
	_title = rhs._title;
	return *this;
}
Warlock::Warlock(std::string const &str1, std::string const &str2)
{
	_name = str1;
	_title = str2;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}
std::string const &Warlock::getName() const {return (_name);}
std::string const &Warlock::getTitle() const {return (_title);}
void Warlock::setTitle(std::string const &str)
{
	_title = str;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}
void Warlock::learnSpell(ASpell *sp)
{
	sp_bk.learnSpell(sp);
}
void Warlock::forgetSpell(std::string str)
{
	sp_bk.forgetSpell(str);	
}
void Warlock::launchSpell(std::string str , ATarget const &at)
{	
	sp_bk.launchSpell(str,at);
}
