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
#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"
#include "../inc/colors.h"
#include <iostream>

class Cat: public Animal
{
	private:
		Brain *_my_brain;

	public:
		Cat();
		Cat(std::string);
		~Cat();
		Cat(const Cat &rhs);
		Cat & operator = (const Cat &a);
		std::string getIdea(int);
		void addIdea(std::string);
		int getCurIdea();
		void makeSound() const;
		void prtIdeas();
};

#endif
