/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP
#define __DOG_HPP
#include "../inc/Animal.hpp"
#include "../inc/colors.h"
#include <iostream>

class Dog: public Animal
{
	private:
		//std::string	_type;

	public:
		Dog();
		Dog(std::string);
		Dog(const Dog&);
		Dog &operator=(const Dog&);
		~Dog();
		void makeSound() const;
};

#endif
