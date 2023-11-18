/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure") 
{
	std::cout << "Default constructor Cure" << std::endl;
}

Cure::Cure(std::string const &name):AMateria(name)
{
	std::cout << "Constructor Cure with asigned name " << name << std::endl;
}

Cure::Cure(AMateria const &rhs)
{	
	std::cout << "Copy constructor Cure from " << rhs.getType() << std::endl;
	*this = rhs;
}

Cure::~Cure()
{
	std::cout << "Destructor Cure " << std::endl;
}

Cure &Cure::operator=(AMateria const &rhs)
{
	_type = rhs.getType();
	return *this;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &rhs)
{
	std::cout << " * heals "<< rhs.getName() << "'s wounds *" << std::endl;
}
