/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : _type("Gato Callejero")
{
	std::cout << "Creating " << _type << " cat."<< std::endl;
}

WrongCat::WrongCat(std::string my_name) : _type(my_name)
{
	std::cout << "Creating " << _type << " cat." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destroy " << _type << " cat." << std::endl;
}

std::string WrongCat::getType() const
{
	return _type;
}

void WrongCat::setType(std::string &my_type)
{
	_type = my_type;
}

void WrongCat::makeSound() const
{
	std::cout << "Miau requete Miau" << std::endl;
}