/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:27:03 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/26 21:27:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "../inc/Weapon.hpp"


class HumanB
{
    private:
        Weapon      *my_weapon;
        std::string my_name;
    public:
        HumanB(std::string name);
        void attack();
        void setWeapon(Weapon weapon);
};
#endif