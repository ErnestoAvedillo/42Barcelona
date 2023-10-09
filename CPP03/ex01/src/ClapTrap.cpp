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
	std::cout << "Creating " << _Name << " warrior."<< std::endl;
	_hit_points = 10;
	_energy = 10;
	_damage = 0;
}

ClapTrap::ClapTrap(std::string my_name) : _Name(my_name)
{
	std::cout << "Creating " << _Name << " warrior." << std::endl;
	_hit_points = 10;
	_energy = 10;
	_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destroy " << _Name << " warrior." << std::endl;
}

void ClapTrap::attack(const std::string &target) 
{
	if(_energy > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << _Name << " attacks " << target << " causing " << _damage << " points of damage !" << std::endl;
		_energy--;

	}
	else if (_hit_points == 0)
		std::cout << "ClapTrap " << _Name << " has not hit_points enough to attack.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _Name << " has not energy enough to attack.!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) 
{
	if (_energy > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << _Name << " attacked had " << _hit_points << " points.";
		this->_hit_points -= amount;
		if (this->_hit_points < 0)
			this->_hit_points = 0;
		std::cout << " Points lost " << amount << " .Now has " << _hit_points << "points." << std::endl;
		this->_energy--;
	}
	else if (_hit_points == 0)
		std::cout << "ClapTrap " << _Name << " has not hit_points enough to attack.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _Name << " has not energy enough to attack.!" << std::endl;

}
void ClapTrap::beRepaired(unsigned int amount) 
{
	if (_energy > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << _Name << " repared had " << _hit_points << " points.";
		this->_hit_points += amount;
		std::cout << " Points won " << amount << " .Now has " << _hit_points << "points." << std::endl;
		this->_energy--;
	}
	else if (_hit_points == 0)
		std::cout << "ClapTrap " << _Name << " has not hit_points enough to beRepaired.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _Name << " has not energy enough to beRepaired.!" << std::endl;
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

std::string ClapTrap::GetName()
{
	return _Name;
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

