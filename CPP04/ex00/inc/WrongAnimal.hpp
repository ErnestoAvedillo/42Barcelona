/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP
#define __ANIMAL_HPP
#include <iostream>

class WrongAnimal
{
	private:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(std::string);
		~WrongAnimal();
		std::string getType() const;
		void setType(std::string&);
		void makeSound() const;
};

#endif