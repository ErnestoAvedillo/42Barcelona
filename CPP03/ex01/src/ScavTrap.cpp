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
	std::cout << "ScavTrap Creating " << this->GetName() << " warrior."<< std::endl;
	this->SetHitPoints(100);
	this->SetEnergy(50);
	this->SetDamage(20);
	_guard_gate = false;
}

ScavTrap::ScavTrap(std::string my_name) : ClapTrap(my_name)
{
	std::cout << "ScavTrap Creating " << this->GetName() << " warrior." << std::endl;
	this->SetHitPoints(100);
	this->SetEnergy(50);
	this->SetDamage(20);
	_guard_gate = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
	_guard_gate = !_guard_gate;
	if (!_guard_gate)
		std::cout << "Guard Gate deactivated" << std::endl;
	else
		std::cout << "Guard Gate activated" << std::endl;
}