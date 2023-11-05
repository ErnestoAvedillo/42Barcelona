/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP
#define __CURE_HPP
#include <iostream>
#include "../inc/colors.h"
#include "../inc/AMateria.hpp"
class Cure: public AMateria
{
private:
	/* data */
public:
	Cure();
	~Cure();
	AMateria *clone() const;
	void use(ICharacter &);
};
#endif
