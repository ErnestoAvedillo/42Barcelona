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
	_my_brain = new Brain("Dog Ideas");
	std::cout << "Creating " << _type << " dog." << std::endl;
}
/*
Dog::Dog(std::string my_name) : _type(my_name)
{
	_my_brain = new Brain;
	std::cout << "Creating " << _type << " dog." << std::endl;
}
*/
Dog::~Dog()
{
	delete _my_brain;
	std::cout << "Destroy " << _type << " dog." << std::endl;
}

void Dog::makeSound() const
{
	std::cout  << BLUE << "Guau Guau Guau" << RESET << std::endl;
}
