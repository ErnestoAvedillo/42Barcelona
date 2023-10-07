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

#include "../inc/Fixed.hpp"

ClapTrap::Fixed() : _Name("Anonimous") {}

ClapTrap::Fixed(std::string my_name) : _Name(my_name) {}

ClapTrap::~Fixed() {}

void ClapTrap::attack(const std::string &target) {}
void ClapTrap::takeDamage(unsigned int amount) {}
void ClapTrap::beRepaired(unsigned int amount) {}
