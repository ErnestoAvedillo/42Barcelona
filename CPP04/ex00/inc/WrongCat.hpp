/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP
#define __CAT_HPP
#include "../inc/Animal.hpp"
#include <iostream>

class WrongCat: public Animal
{
	private:
		std::string	_type;

	public:
		WrongCat();
		WrongCat(std::string);
		~WrongCat();
		std::string getType() const;
		void setType(std::string&);
		void makeSound() const;
};

#endif