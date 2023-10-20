/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP
#define __CAT_HPP
#include "../inc/AAnimal.hpp"
#include "../inc/Brain.hpp"
#include "../inc/colors.h"
#include <iostream>

class Cat: public AAnimal
{
	private:
		std::string	_type;
		Brain *_my_brain;

	public:
		Cat();
		Cat(std::string);
		~Cat();
		std::string getIdea(int);
		void addIdea(std::string);
		void makeSound() const;
		int getCurIdea();
};

#endif
