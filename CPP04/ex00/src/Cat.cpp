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

Cat::Cat() : _type("Gato Callejero")
{
	std::cout << "Creating " << _type << " cat."<< std::endl;
}

Cat::Cat(std::string my_name) : _type(my_name)
{
	std::cout << "Creating " << _type << " cat." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destroy " << _type << " cat." << std::endl;
}

std::string Cat::getType() const
{
	return _type;
}

void Cat::setType(std::string &my_type)
{
	_type = my_type;
}

void Cat::makeSound() const
{
	std::cout << "Miau requete Miau" << std::endl;
}