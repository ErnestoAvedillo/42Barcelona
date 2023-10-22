/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Gato Callejero")
{
	std::cout << "Creating " << _type << " cat."<< std::endl;
}

Cat::Cat(std::string my_name) : Animal(my_name)
{
	std::cout << "Creating " << _type << " cat." << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	std::cout << "Copy method  " << _type << " dog from " << rhs.getType() << std::endl;
	*this = rhs;
}
Cat & Cat::operator = (const Cat &rhs)
{
	std::cout << "Asignation method  " << _type << " dog from " << rhs.getType() << std::endl;
	this->_type = rhs.getType();
	return *this;
}

Cat::~Cat()
{
	std::cout << "Destroy " << _type << " cat." << std::endl;
}

void Cat::makeSound() const
{
	std::cout  << BLUE << "Miau requete Miau" << RESET << std::endl;
}
