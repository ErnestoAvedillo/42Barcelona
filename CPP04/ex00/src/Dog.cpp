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

Dog::Dog() : _type("Perro Callejero")
{
	std::cout << "Creating " << _type << " dog."<< std::endl;
}

Dog::Dog(std::string my_name) : _type(my_name)
{
	std::cout << "Creating " << _type << " dog." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destroy " << _type << " dog." << std::endl;
}

std::string Dog::getType() const
{
	return _type;
}

void Dog::setType(std::string &my_type)
{
	_type = my_type;
}

void Dog::makeSound() const
{
	std::cout << "Guau Guau Guau" << std::endl;
}