/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:27:03 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/26 21:27:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "../inc/Weapon.hpp"


class HumanA
{
    private:
        std::string my_name;
        Weapon      &my_weapon;
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
};
#endif
