/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/17 11:33:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp" 


ATarget::ATarget(){}
ATarget::ATarget(ATarget const &rhs)
{ *this = rhs;}
ATarget &ATarget::operator=(ATarget const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

ATarget::ATarget(std::string &mytype)
{
	this->_type = mytype;
}
ATarget::ATarget(const std::string &mytype)
{
	this->_type = mytype;
}
ATarget::~ATarget()
{
}
std::string const &ATarget::getType() const
{ return _type;}
void ATarget::getHitBySpell(ASpell const &sp) const
{
	std::cout << _type << " has been " << sp.getEffects() << "!" << std::endl;
}

