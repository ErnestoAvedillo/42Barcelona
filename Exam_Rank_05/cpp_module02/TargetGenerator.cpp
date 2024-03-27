#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator()
{

	std::map<std::string, ATarget*>::iterator it_bgn = _book.begin();
	std::map<std::string, ATarget*>::iterator it_end = _book.end();
	while (it_bgn != it_end)
	{
		delete it_bgn->second;
		it_bgn++;
	}
	_book.clear();
}
void TargetGenerator::learnTargetType(ATarget*sp)
{
	if (sp)
		_book.insert(std::pair<std::string, ATarget *>(sp->getType(), sp->clone(    )));
}
void TargetGenerator::forgetTargetType(std::string const &str)
{
	std::map<std::string, ATarget*>::iterator it = _book.find(str);
	if (it != _book.end())
		delete (it->second);
	_book.erase(it);
}
ATarget* TargetGenerator::createTarget(std::string const &str)
{
	ATarget *sp = _book[str];
	if (sp)
		return (sp);
	return NULL;
}
