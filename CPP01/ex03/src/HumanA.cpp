/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:27:03 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/26 21:27:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
# include <stdlib.h>


HumanA::HumanA(std::string name, Weapon &weapon): my_name(name), my_weapon(weapon){}

void HumanA::attack()
{
	std::cout << my_name << " attacks with their " << my_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
}