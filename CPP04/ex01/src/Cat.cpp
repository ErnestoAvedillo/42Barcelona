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

Cat::Cat() : Animal ("Gato Callejero")
{
	_my_brain = new Brain ();
	std::cout << BLUE "Creating " << _type << " cat." RESET << std::endl;
}

Cat::Cat(std::string my_name): Animal(my_name)
{
	_my_brain = new Brain ("Cat ideas");
	std::cout << BLUE "Creating " << _type << " cat." RESET << std::endl;
}

Cat::Cat(const Cat &rhs): Animal(rhs)
{
	std::cout << "Copy method  " << _type << " dog from " << rhs.getType() << std::endl;
}
Cat & Cat::operator = (const Cat &rhs)
{
	std::cout << "Asignation method  " << _type << " dog from " << rhs.getType() << std::endl;
	this->_type = rhs.getType();
	return *this;
}

Cat::~Cat()
{
	delete _my_brain;
	std::cout << RED "Destroy " << _type << " cat." RESET << std::endl;
}

std::string Cat::getIdea(int n)
{
	std::cout << "Getting the idea nr. " << n << " of the cat." << std::endl;
	return _my_brain->getIdea(n);
}

void Cat::addIdea(std::string s)
{
	std::cout << "Adding the idea " << s << " into the cat." << std::endl;
	_my_brain->addIdea(s);
	return;
}

int Cat::getCurIdea ()
{
	return _my_brain->getCurIdea();
}

void Cat::makeSound() const
{
	std::cout  << BLUE << "Miau requete Miau" << RESET << std::endl;
}

void Cat::prtIdeas()
{
	_my_brain->prtAllIdeas();
}
