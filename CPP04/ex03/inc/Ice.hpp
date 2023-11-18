/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP
#define __ICE_HPP
#include <iostream>
#include "../inc/colors.h"
#include "../inc/AMateria.hpp"
class Ice: public AMateria
{
private:

public:
	Ice();
	Ice(std::string const &);
	Ice(AMateria const &);
	~Ice();
	Ice &operator=(AMateria const &);
	AMateria * clone() const;
	void use(ICharacter &);
};
#endif
