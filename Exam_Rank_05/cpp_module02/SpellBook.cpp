#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook()
{

	std::map<std::string, ASpell*>::iterator it_bgn = _book.begin();
	std::map<std::string, ASpell*>::iterator it_end = _book.end();
	while (it_bgn != it_end)
	{
		delete it_bgn->second;
		it_bgn++;
	}
	_book.clear();
}
void SpellBook::learnSpell(ASpell*sp)
{
	if (sp)
		_book.insert(std::pair<std::string, ASpell *>(sp->getName(), sp->clone(    )));
}
void SpellBook::forgetSpell(std::string const &str)
{
	std::map<std::string, ASpell*>::iterator it = _book.find(str);
	if (it != _book.end())
		delete (it->second);
	_book.erase(it);
}
ASpell* SpellBook::createSpell(std::string const &str)
{
	ASpell *sp = _book[str];
	if (sp)
		return (sp);
	return NULL;
}
