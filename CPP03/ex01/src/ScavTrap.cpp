/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Creating " << this->GetName() << " warrior."<< std::endl;
	this->SetHitPoints(100);
	this->SetEnergy(50);
	this->SetDamage(20);
}

ScavTrap::ScavTrap(std::string my_name): base(my_name)
{
	std::cout << "Creating " << this->GetName() << " warrior."<< std::endl;
	this->SetHitPoints(100);
	this->SetEnergy(50);
	this->SetDamage(20);
}


