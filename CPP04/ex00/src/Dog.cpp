/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Perro Callejero")
{
	std::cout << "Creating " << _type << " dog."<< std::endl;
}

Dog::Dog(std::string my_name) : Animal(my_name)
{
	std::cout << "Creating " << _type << " dog." << std::endl;
}

Dog::Dog(const Dog &rhs)
{
	std::cout << "Copy method  " << _type << " dog from " << rhs.getType() << std::endl;
	*this = rhs;
}
Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Asignation method  " << _type << " dog from " << rhs.getType() << std::endl;
	this->_type = rhs.getType();
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destroy " << _type << " dog." << std::endl;
}

void Dog::makeSound() const
{
	std::cout  << BLUE << "Guau Guau Guau" << RESET << std::endl;
}
