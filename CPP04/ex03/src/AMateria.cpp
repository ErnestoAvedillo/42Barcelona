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
	std::cout << "Creating " << _type << " AMateria in pointer " << this << std::endl;
	_usage = 0;
	_owner = NULL;
}
AMateria::AMateria(std::string const & my_material) : _type(my_material)
{
	std::cout << "Creating " << _type << " AMateria in pointer " << this << std::endl;
	_usage = 0;
	_owner = NULL;
}

AMateria::~AMateria()
{
	if (_owner != NULL)
		_owner->erase_mat(this);
	std::cout << "deleting AMateria with ptr " << this << std::endl;
}

AMateria::AMateria(AMateria const &rhs)
{
	*this = rhs;
	std::cout << "Creating " << _type << " AMateria in pointer " << this <<std::endl;
}
AMateria &AMateria::operator=(AMateria const &rhs)
{
	this->_type = rhs.getType();
	this->_usage = 0; 
	_owner = NULL;
	std::cout << "Asigning " << _type << " AMateria in pointer " << this <<std::endl;
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
	std::cout << "*incremento uso AMateria " << _type << " * pointer " << this << " * " << _usage << "->";
	_usage++;
	std::cout << _usage << std::endl;
}

void AMateria::dec_use()
{
	std::cout << "*decremento uso AMateria " << _type << " * " << this << " * " << _usage << "->";
	_usage--;
	std::cout << _usage << std::endl;
}
int AMateria::get_use()
{
	return _usage;
}

IHandHeader *AMateria::get_owner()
{
	return _owner;
}
void AMateria::set_owner(IHandHeader *rhs)
{
	_owner = rhs;
}
