/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Anonimous")
{
	std::cout << "Creating " << _type << " animal."<< std::endl;
}

WrongAnimal::WrongAnimal(std::string my_name) : _type(my_name)
{
	std::cout << "Creating " << _type << " animal." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& rhs)
{
	this->_type = rhs.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destroy " << _type << " Animal." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::setType(std::string &my_type)
{
	_type = my_type;
}

void WrongAnimal::makeSound() const
{
	std::cout  << GREEN << "Mi animal que hace Brrrrbrrrrr" << RESET << std::endl;
}