/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/Ice.hpp"

Ice::Ice():AMateria("ice"){}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
	return new Ice (*this);
}
void Ice::use(ICharacter &rhs)
{
	std::cout << " * shoots an ice bolt at " << rhs.getName() << " *" << std::endl;
}
