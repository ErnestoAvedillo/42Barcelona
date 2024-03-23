#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::SpellBook(ASpell *rhs)
{
	this->learnSpell(rhs);
}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell*>::iterator it_bgn = _book.begin();
	std::map<std::string, ASpell*>::iterator it_end = _book.end();
	while (it_bgn != it_end)
	{
		delete(it_bgn->second);
		it_bgn++;
	}
	_book.clear();
}
void SpellBook::learnSpell(ASpell *sp)
{
	if (sp)
	_book.insert(std::pair<std::string, ASpell*>(sp->getName(), sp->clone()));
}
void SpellBook::forgetSpell(std::string str)
{
	std::map<std::string, ASpell*>::iterator it = _book.find(str);
	if (it != _book.end())
	{
		delete it->second;
	}
	_book.erase(str);

}
void SpellBook::launchSpell(std::string str , ATarget const &at)
{
	ASpell *sp = _book[str];
	if (sp)
	{
		sp->launch(at);
	}
}
