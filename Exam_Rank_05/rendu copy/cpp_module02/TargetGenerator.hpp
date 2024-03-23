
#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include "ATarget.hpp"
#include <map>
	
class TargetGenerator
{
	private:
		std::map<std::string, ATarget*> _book;
	public:
		TargetGenerator();
		TargetGenerator(ATarget *);
		~TargetGenerator();
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);

};
#endif
