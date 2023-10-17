/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name_DiamondAnonimous"), _Name("DiamondAnonimous")
{
	
	std::cout << "DiamondTrap Creating " << _Name << " warrior." << std::endl;
	this->SetHitPoints(INIT_FRAG_HIT_POINTS);
	this->SetEnergy(INIT_SCAV_ENERGY);
	this->SetDamage(INIT_FRAG_ATACK_DAMAGE);
	//this->attack();
}

DiamondTrap::DiamondTrap(std::string my_name) : ClapTrap("_clap_name_" + my_name), _Name(my_name)
{
	std::cout << "DiamondTrap Creating " << _Name << " warrior." << std::endl;
	this->SetHitPoints(INIT_FRAG_HIT_POINTS);
	this->SetEnergy(INIT_SCAV_ENERGY);
	this->SetDamage(INIT_FRAG_ATACK_DAMAGE);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroyed" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap :I am " << _Name << " a ClapTrap " << this->GetName() << "- Hey guys, I am the terror of the warriors." << std::endl;
}

void DiamondTrap::attack (const std::string &target)
{
	this->ScavTrap::attack(target);
}
