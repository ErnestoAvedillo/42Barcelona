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
	this->SetHitPoints(INIT_SCAV_HIT_POINTS);
	this->SetEnergy(INIT_SCAV_ENERGY);
	this->SetDamage(INIT_SCAV_ATACK_DAMAGE);
	_guard_gate = false;
}

ScavTrap::ScavTrap(std::string my_name) : ClapTrap(my_name)
{
	std::cout << "ScavTrap Creating " << this->GetName() << " warrior." << std::endl;
	this->SetHitPoints(INIT_SCAV_HIT_POINTS);
	this->SetEnergy(INIT_SCAV_ENERGY);
	this->SetDamage(INIT_SCAV_ATACK_DAMAGE);
	_guard_gate = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target) 
{
	if(_energy > 0 && _hit_points > 0)
	{
		std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " attacks " << target << " causing " << _damage << " points of damage ! ";
		_energy--;
		this->ViewStatus();
	}
	else if (_hit_points == 0)
		std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " has not enough hit_points to attack.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " has not enough energy to attack.!" << std::endl;
}

void ScavTrap::guardGate()
{
	_guard_gate = !_guard_gate;
	if (!_guard_gate)
		std::cout << "ScavTrap Guard Gate deactivated" << std::endl;
	else
		std::cout << "ScavTrap Guard Gate activated" << std::endl;
}

void ScavTrap::ViewStatus()
{
	std::cout << "Showing status of " << BLUE << this->GetName() << RESET << "-->" ;
	std::cout << YELLOW << " HPTS = " << _hit_points << RESET << ". ";
	std::cout << CYAN << " ENERG = " << _energy << RESET << ". ";
	std::cout << GREEN << " DAMAGE = " << _damage << RESET << ". ";
	std::cout << RED << " Guard Gate = " << _guard_gate << RESET << ". " << std::endl;
}
