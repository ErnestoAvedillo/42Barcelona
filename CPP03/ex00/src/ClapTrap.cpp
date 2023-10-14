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
	_hit_points = INIT_HIT_POINTS;
	_energy = INIT_ENERGY;
	_damage = INIT_ATACK_DAMAGE;
}

ClapTrap::ClapTrap(std::string my_name) : _Name(my_name)
{
	std::cout << "Creating " << _Name << " warrior." << std::endl;
	_hit_points = INIT_HIT_POINTS;
	_energy = INIT_ENERGY;
	_damage = INIT_ATACK_DAMAGE;
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
		std::cout << "ClapTrap " << _Name << " has not enough hit_points to attack.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _Name << " has not enough energy to attack.!" << std::endl;
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
		std::cout << "ClapTrap " << _Name << " has not enough hit_points to attack.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _Name << " has not enough energy to attack.!" << std::endl;
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
		std::cout << "ClapTrap " << _Name << " has not enough hit_points to beRepaired.!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _Name << " has not enough energy to beRepaired.!" << std::endl;
}
