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
#include <iostream>

class Cat: public Animal
{
	private:
		std::string	_type;

	public:
		Cat();
		Cat(std::string);
		virtual ~Cat();
		virtual std::string getType() const;
		void setType(std::string&);
		virtual void makeSound() const;
};

#endif