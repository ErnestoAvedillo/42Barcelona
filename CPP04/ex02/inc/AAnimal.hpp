/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP
#define __AANIMAL_HPP
#include <iostream>
#include "../inc/colors.h"
class AAnimal
{
	private:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(std::string);
		AAnimal(const AAnimal &);
		AAnimal &operator=(const AAnimal&);
		virtual ~AAnimal();
		std::string getType() const;
		void setType(std::string&);
		virtual void makeSound() const = 0 ;
};

#endif
