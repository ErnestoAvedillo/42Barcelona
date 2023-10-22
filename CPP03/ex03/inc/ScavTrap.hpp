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

#ifndef __SCAVTRAP_HPP
#define __SCAVTRAP_HPP
#include "../inc/ClapTrap.hpp"
#include <iostream>
# define INIT_SCAV_HIT_POINTS 100
# define INIT_SCAV_ENERGY 50
# define INIT_SCAV_ATACK_DAMAGE 20
class ScavTrap: virtual public ClapTrap
{
    private:
        bool _guard_gate;

    public:
        ScavTrap();
        ScavTrap(std::string my_nam);
        ~ScavTrap();
        void attack(const std::string &target);
        void guardGate();
        void ViewStatus();
};
#endif
