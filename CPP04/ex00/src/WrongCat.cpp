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

WrongCat::WrongCat(): WrongAnimal("Gato Callejero")
{
 	
	std::cout << "Creating " << _type << " cat."<< std::endl;
}

WrongCat::WrongCat(std::string my_name) : WrongAnimal(my_name)
{
	std::cout << "Creating " << _type << " cat." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destroy " << _type << " cat." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout  << BLUE << "Miau requete Miau"  << RESET << std::endl;
}
