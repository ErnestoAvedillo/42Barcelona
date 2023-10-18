/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongDog.hpp"

WrongDog::WrongDog() : _type("Perro Callejero")
{
	std::cout << "Creating " << _type << " dog."<< std::endl;
}

/*WrongDog::WrongDog(std::string my_name) : _type(my_name)
{
	std::cout << "Creating " << _type << " dog." << std::endl;
}
*/
WrongDog::~WrongDog()
{
	std::cout << "Destroy " << _type << " dog." << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << BLUE << "Guau Guau Guau" << RESET << std::endl;
}
