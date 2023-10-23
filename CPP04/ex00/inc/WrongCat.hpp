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
#define __WRONGCAT_HPP
#include "../inc/WrongAnimal.hpp"
#include "../inc/colors.h"
#include <iostream>

class WrongCat: public WrongAnimal
{
	private:
		std::string	_type;

	public:
		WrongCat();
		WrongCat(std::string);
		WrongCat(const WrongCat&);
		WrongCat &operator=(const WrongCat&);
		~WrongCat();
		void makeSound() const;
};

#endif
