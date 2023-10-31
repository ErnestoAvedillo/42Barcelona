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

Dog::Dog() : AAnimal("Perro Callejero")
{
	_my_brain = new Brain();
	std::cout << YELLOW "Creating " << _type << " dog." RESET  << std::endl;
}

Dog::Dog(std::string my_name) : AAnimal(my_name)
{
	_my_brain = new Brain ("Dog Ideas");
	std::cout << YELLOW "Creating " << _type << " dog." RESET  << std::endl;
}


Dog::Dog(const Dog &rhs) : AAnimal(rhs)
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
	delete _my_brain;
	std::cout << RED "Destroy " << _type << " dog." RESET  << std::endl;
}

std::string Dog::getIdea(int n)
{
	std::cout << PURPLE "Getting the idea nr. " << n << " of the cat." RESET << std::endl;
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

void Dog::prtIdeas()
{
	_my_brain->prtAllIdeas();
}
