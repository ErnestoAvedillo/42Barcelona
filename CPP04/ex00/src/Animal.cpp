/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : _type("Anonimous")
{
	std::cout << "Creating " << _type << " animal."<< std::endl;
}

Animal::Animal(std::string my_name) : _type(my_name)
{
	std::cout << "Creating " << _type << " animal." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destroy " << _type << " warrior." << std::endl;
}

std::string Animal::GetType()
{
	return _type;
}

void Animal::SetType(std::string &my_type)
{
	_type = my_type;
}
