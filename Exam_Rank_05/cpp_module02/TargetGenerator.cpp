/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/19 21:59:49 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "TargetGenerator.hpp" 

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget*at)
{
	if (at)
		_book.insert(std::pair<std::string, ATarget* >(at->getType(), at->clone()));
}
void TargetGenerator::forgetTargetType(std::string const &str)
{
	std::map<std::string, ATarget *>::iterator it = _book.find(str);
	if (it != _book.end())
	{
		delete it->second;
		_book.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(std::string const &str)
{
	std::map<std::string, ATarget *>::iterator it = _book.find(str);
	if (it != _book.end())
	{
		return it->second;
	}
	return NULL;
}
