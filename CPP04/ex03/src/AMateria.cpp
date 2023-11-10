/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria() : _type("void") 
{
	std::cout << "Creating " << _type << " AMateria." << std::endl;
	_usage = 0;
}
AMateria::AMateria(std::string const & my_material) : _type(my_material)
{
	std::cout << "Creating " << _type << " AMateria." << std::endl;
	_usage = 0;
}

AMateria::~AMateria()
{

}

AMateria::AMateria(AMateria const &rhs)
{
	*this = rhs;
	std::cout << "Creating " << _type << " AMateria." << std::endl;
}
AMateria &AMateria::operator=(AMateria const &rhs)
{
	this->_type = rhs.getType();
	this->_usage = 0; 
	std::cout << "Asigning " << _type << " AMateria." << std::endl;
	return *this;
}
std::string const &AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &)
{
	std::cout << "*Orininal message from AMateria " << _type << "*" << std::endl;
}

void AMateria::inc_use()
{
	std::cout << "*incremento uso AMateria " << _type << " * " << _usage << "->";
	_usage++;
	std::cout << _usage << std::endl;
}

void AMateria::dec_use()
{
	std::cout << "*decremento uso AMateria " << _type << " * " << _usage << "->";
	_usage--;
	std::cout << _usage << std::endl;
}
int AMateria::get_use()
{
	return _usage;
}
