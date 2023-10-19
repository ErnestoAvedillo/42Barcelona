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
#include "../inc/AAnimal.hpp"
#include "../inc/Brain.hpp"
#include "../inc/colors.h"
#include <iostream>

class Dog: public AAnimal
{
	private:
		std::string	_type;
		Brain *_my_brain;

	public:
		Dog();
		//Dog(std::string);
		~Dog();
		void makeSound() const;
};

#endif
