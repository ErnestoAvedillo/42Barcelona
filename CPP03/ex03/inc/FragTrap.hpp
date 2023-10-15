/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP
#define __FRAGTRAP_HPP
#include "../inc/ClapTrap.hpp"
#include <iostream>
#include <cmath>
#define INIT_FRAG_HIT_POINTS 100
#define INIT_FRAG_ENERGY 100
#define INIT_FRAG_ATACK_DAMAGE 30
class FragTrap : virtual public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string);
		~FragTrap();
		void highFivesGuys(void);
};

#endif