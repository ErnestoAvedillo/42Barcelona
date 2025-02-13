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

#ifndef __CLAPTRAP_HPP
#define __CLAPTRAP_HPP
#include <iostream>
#include <cmath>
#include "../inc/colors.h"
# define INIT_HIT_POINTS 10
# define INIT_ENERGY 10
# define INIT_ATACK_DAMAGE 0
class ClapTrap
{
	private:
		std::string	_Name;

	protected:
		int			_hit_points;
		int 		_energy;
		int 		_damage;

	public:
		ClapTrap();
		ClapTrap(std::string);
		~ClapTrap();
		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		bool CanActuate();
		std::string GetName();
		int GetHitPoints();
		int GetEnergy();
		int GetDamage();
		void SetName(std::string);
		void SetHitPoints(int);
		void SetEnergy(int);
		void SetDamage(int);
		virtual void ViewStatus();
};
#endif
