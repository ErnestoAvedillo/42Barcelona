/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"
#include <iostream>

Zombie::Zombie ()
{
    std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie (std::string name): _myname(name)
{
    std::cout << "Zombie created" << _myname << std::endl;
}

Zombie::~Zombie ()
{
    std::cout << "Zombie destroyed" << std::endl;
}

void Zombie::announce (void)
{
    std::cout << _myname << ":BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getname()
{
    return _myname;
}

void Zombie::putname(std::string name)
{
    _myname = name;
}
