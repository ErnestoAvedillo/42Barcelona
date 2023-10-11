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
#define __DOG_HPP
#include "../inc/Animal.hpp"
#include <iostream>

class WrongDog: public Animal
{
	private:
		std::string	_type;

	public:
		WrongDog();
		WrongDog(std::string);
		~WrongDog();
		std::string getType() const;
		void setType(std::string&);
		void makeSound() const;
};

#endif