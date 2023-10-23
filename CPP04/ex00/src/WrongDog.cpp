/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("Perro Callejero")
{
	std::cout << "Creating " << _type << " WrongDog."<< std::endl;
}

WrongDog::WrongDog(std::string my_name) : WrongAnimal(my_name)
{
	std::cout << "Creating " << _type << " WrongDog." << std::endl;
}

WrongDog::WrongDog(const WrongAnimal &rhs): WrongAnimal(rhs)
{
	std::cout << "Copy constructor " << _type << " WrongDog." << std::endl;
	
}
WrongDog &WrongDog::operator=(const WrongAnimal &rhs)
{
	std::cout << "Asignement operator " << _type << " WrongDog." << std::endl;
	this->_type = rhs.getType();
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << "Destroy " << _type << " WrongDog." << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << BLUE << "Guau Guau Guau" << RESET << std::endl;
}
