/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal() : _type("Anonimous")
{
	std::cout << "Creating " << _type << " animal."<< std::endl;
}

AAnimal::AAnimal(std::string my_name) : _type(my_name)
{
	std::cout << "Creating " << _type << " animal." << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs)
{
	std::cout << "Copy method  " << _type << " dog from " << rhs.getType() << std::endl;
	*this = rhs;
}

AAnimal &AAnimal::operator=(const AAnimal& rhs)
{
	std::cout << "Asignation method  " << _type << " dog from " << rhs.getType() << std::endl;
	this->_type = rhs.getType();
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Destroy " << _type << " AAnimal." << std::endl;
}

std::string AAnimal::getType() const
{
	return _type;
}

void AAnimal::setType(std::string &my_type)
{
	_type = my_type;
}
