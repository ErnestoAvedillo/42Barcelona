/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("Anonimous")
{
	_hit_points = INIT_HIT_POINTS;
	_energy = INIT_ENERGY;
	_damage = INIT_ATACK_DAMAGE;
	std::cout << "Creating " << BLUE << _Name << RESET << " warrior. " << std::endl;
	this->VewStatus();
}

ClapTrap::ClapTrap(std::string my_name) : _Name(my_name)
{
	_hit_points = INIT_HIT_POINTS;
	_energy = INIT_ENERGY;
	_damage = INIT_ATACK_DAMAGE;
	std::cout << "Creating " << BLUE << _Name << RESET << " warrior." << std::endl;
	this->VewStatus();
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destroy " << BLUE << _Name << RESET << " warrior." << std::endl;
}

void ClapTrap::attack(const std::string &target) 
{
	if(_energy > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << BLUE << _Name << RESET << " attacks " << target << " causing " << _damage << " points of damage ! ";
		_energy--;
		this->VewStatus();
	}
	else if (_hit_points == 0)
		std::cout << "ClapTrap " << BLUE << _Name << RESET << " has not enough hit_points to attack.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << BLUE << _Name << RESET << " has not enough energy to attack.!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) 
{
	if (_energy > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << BLUE << _Name << RESET << " attacked had " << _hit_points << " points.";
		this->_hit_points -= amount;
		std::cout << " Points lost " << amount << " .";
		this->_energy--;
		this->VewStatus();
	}
	else if (_hit_points == 0)
		std::cout << "ClapTrap " << BLUE << _Name << RESET << " has not enough hit_points to attack.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << BLUE << _Name << RESET << " has not enough energy to attack.!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) 
{
	if (_energy > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << BLUE << _Name << RESET << " repared had " << _hit_points << " points.";
		this->_hit_points += amount;
		std::cout << " Points won " << amount << " .";
		this->_energy--;
		this->VewStatus();
	}
	else if (_hit_points == 0)
		std::cout << "ClapTrap " << BLUE << _Name << RESET << " has not enough hit_points to beRepaired.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << BLUE << _Name << RESET << " has not enough energy to beRepaired.!" << std::endl;
}

bool ClapTrap::CanActuate()
{
	if (this->_energy <= 0 || this->_hit_points <= 0)
		return false;
	return true;
}

std::string ClapTrap::GetName()
{
	return _Name;
}

int ClapTrap::GetHitPoints()
{
	return _hit_points;
}

int ClapTrap::GetEnergy()
{
	return _energy;
}

int ClapTrap::GetDamage()
{
	return _damage;
}

void ClapTrap::SetName(std::string my_name)
{
	_Name = my_name;
}

void ClapTrap::SetHitPoints(int val)
{
	_hit_points = val;
}

void ClapTrap::SetEnergy(int val)
{
	_energy = val;
}

void ClapTrap::SetDamage(int val)
{
	_damage = val;
}

void ClapTrap::VewStatus()
{
	std::cout << YELLOW << " HPTS = " << _hit_points << RESET << ". ";
	std::cout << CYAN << " ENERG = " << _energy << RESET << ". ";
	std::cout << GREEN << " DAMAGE = " << _damage << RESET << ". " << std::endl;
}
