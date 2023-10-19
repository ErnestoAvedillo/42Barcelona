/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGDOG_HPP
#define __WRONGDOG_HPP
#include "../inc/WrongAnimal.hpp"
#include "../inc/colors.h"
#include <iostream>

class WrongDog: public WrongAnimal
{
	private:
		std::string	_type;

	public:
		WrongDog();
		//WrongDog(std::string);
		~WrongDog();
		void makeSound() const;
};

#endif