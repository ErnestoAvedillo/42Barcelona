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
	_my_brain = new Brain();
	std::cout << "Creating " << _type << " dog." << std::endl;
}

Dog::Dog(std::string my_name) : _type(my_name)
{
	_my_brain = new Brain ("Dog Ideas");
	std::cout << "Creating " << _type << " dog." << std::endl;
}

Dog::~Dog()
{
	delete _my_brain;
	std::cout << "Destroy " << _type << " dog." << std::endl;
}

std::string Dog::getIdea(int n)
{
	std::cout << "Getting the idea nr. " << n << " of the cat." << std::endl;
	return _my_brain->getIdea(n);
}

void Dog::addIdea(std::string s)
{
	std::cout << "Adding the idea " << s << " into the cat." << std::endl;
	_my_brain->addIdea(s);
	return;
}

int Dog::getCurIdea ()
{
	return _my_brain->getCurIdea();
}

void Dog::makeSound() const
{
	std::cout  << BLUE << "Guau Guau Guau" << RESET << std::endl;
}
