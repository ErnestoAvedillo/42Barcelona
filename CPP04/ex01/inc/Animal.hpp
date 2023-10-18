/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP
#define __ANIMAL_HPP
#include <iostream>
#include "../inc/colors.h"
class Animal
{
	private:
		std::string	_type;

	public:
		Animal();
		Animal(std::string);
		virtual ~Animal();
		Animal &operator=(const Animal& rhs);
		std::string getType() const;
		void setType(std::string&);
		virtual void makeSound() const;
};

#endif
