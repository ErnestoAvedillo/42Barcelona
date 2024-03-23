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

	std::map<std::string, ASpell*>::iterator it_bgn = _book.begin();
	std::map<std::string, ASpell*>::iterator it_end = _book.end();
	while (it_bgn != it_end)
	{
		delete(it_bgn->second);
		it_bgn++;
	}
	_book.clear();
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
	if (sp)
	_book.insert(std::pair<std::string, ASpell*>(sp->getName(), sp->clone()));
}
void Warlock::forgetSpell(std::string str)
{
	std::map<std::string, ASpell*>::iterator it = _book.find(str);
	if (it != _book.end())
	{
		delete it->second;
	}
	_book.erase(str);
	
}
void Warlock::launchSpell(std::string str , ATarget const &at)
{	
	ASpell *sp = _book[str];
	if (sp)
	{
		sp->launch(at);
	}
}
