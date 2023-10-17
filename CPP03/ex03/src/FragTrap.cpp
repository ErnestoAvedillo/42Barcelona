/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Creating " << this->GetName() << " warrior." << std::endl;
	this->SetHitPoints(INIT_FRAG_HIT_POINTS);
	this->SetEnergy(INIT_FRAG_ENERGY);
	this->SetDamage(INIT_FRAG_ATACK_DAMAGE);
}

FragTrap::FragTrap(std::string my_name) : ClapTrap(my_name)
{
	std::cout << "FragTrap Creating " << this->GetName() << " warrior." << std::endl;
	this->SetHitPoints(INIT_FRAG_HIT_POINTS);
	this->SetEnergy(INIT_FRAG_ENERGY);
	this->SetDamage(INIT_FRAG_ATACK_DAMAGE);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->GetName() << "- Hey guys, give me a five." << std::endl;
}
