#include "Warlock.hpp"

Warlock::Warlock(){}
Warlock::Warlock(Warlock const &rhs)
{
	*this = rhs;
	std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock &Warlock::operator=(Warlock const &rhs)
{
	name = rhs.name;
	title = rhs.title;
	std::cout << name << ": This looks like another boring day." << std::endl;
	return *this;
}
Warlock::Warlock(std::string const &str1,std::string const &str2)
{
	name = str1;
	title = str2;
	std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!"<< std::endl;
}
std::string const & Warlock::getName() const{return name;}
std::string const & Warlock::getTitle() const{return title;}
void Warlock::setTitle (std::string const &str)
{
	title = str;
}
void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!"<< std::endl;
}

void Warlock::learnSpell(ASpell *sp)
{
	_book.learnSpell(sp);
}
void Warlock::forgetSpell(std::string str)
{
	_book.forgetSpell(str);
}
void Warlock::launchSpell(std::string str, ATarget const &tg)
{
	ASpell *sp = _book.createSpell(str);
	if (sp)
		sp->launch(tg);		
}
