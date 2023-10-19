/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
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
		AAnimal();

	public:
		static AAnimal* createInstance();
		AAnimal(std::string);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal& rhs);
		std::string getType() const;
		void setType(std::string&);
		virtual void makeSound() const;
};

#endif
