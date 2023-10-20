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

Cat::Cat()
{
	_type = "Gato Callejero";
	_my_brain = new Brain ();
	std::cout << "Creating " << _type << " cat." << std::endl;
}

Cat::Cat(std::string my_name)
{
	_type = my_name;
	_my_brain = new Brain ("Cat ideas");
	std::cout << "Creating " << _type << " cat." << std::endl;
}

Cat::~Cat()
{
	delete _my_brain;
	std::cout << "Destroy " << _type << " cat." << std::endl;
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
