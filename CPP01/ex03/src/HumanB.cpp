/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:27:03 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/26 21:27:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"	

HumanB::HumanB(std::string name)
{
	my_name = name;
}

void HumanB::attack()
{
	std::cout << my_name << " attacks with their " << my_weapon.get_type() << std::endl;
}