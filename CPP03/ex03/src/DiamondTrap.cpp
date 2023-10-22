/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamondAnonimous_clap_name_"),ScavTrap("DiamondAnonimous") , FragTrap("DiamondAnonimous") ,_Name("DiamondAnonimous")
{
	
	std::cout << "DiamondTrap Creating " << _Name << " warrior." << std::endl;
	this->FragTrap::SetHitPoints(INIT_FRAG_HIT_POINTS);
	this->ScavTrap::SetEnergy(INIT_SCAV_ENERGY);
	this->FragTrap::SetDamage(INIT_FRAG_ATACK_DAMAGE);
}

DiamondTrap::DiamondTrap(std::string my_name) : ClapTrap( my_name + "_clap_name_"), ScavTrap( my_name + "_clap_name_"), FragTrap( my_name + "_clap_name_"), _Name(my_name)
{
	std::cout << "DiamondTrap Creating " << _Name << " warrior." << std::endl;
	this->FragTrap::SetHitPoints(INIT_FRAG_HIT_POINTS);
	this->ScavTrap::SetEnergy(INIT_SCAV_ENERGY);
	this->FragTrap::SetDamage(INIT_FRAG_ATACK_DAMAGE);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroyed" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap :I am " << _Name << " a ClapTrap " << this->_Name << "- Hey guys, I am the terror of the warriors." << std::endl;
}
