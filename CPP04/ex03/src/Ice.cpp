/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/Ice.hpp"

Ice::Ice():AMateria("ice")
{
	std::cout << "Default constructor Ice" << std::endl;
}

Ice::Ice(std::string const &name):AMateria(name)
{
	std::cout << "Constructor Ice with asigned name " << name << std::endl;
}

Ice::Ice(AMateria const &rhs)
{	
	std::cout << "Copy constructor Ice from " << rhs.getType() << std::endl;
	*this = rhs;
}

Ice::~Ice()
{
	std::cout << "Destructor Ice " << std::endl;
}

Ice &Ice::operator=(AMateria const &rhs)
{
	_type = rhs.getType();
	return *this;
}
AMateria *Ice::clone() const
{
	return new Ice (*this);
}

void Ice::use(ICharacter &rhs)
{
	std::cout << " * shoots an ice bolt at " << rhs.getName() << " *" << std::endl;
}
