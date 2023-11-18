/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IHandHEeader.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IHANDHEADER_HPP
#define __IHANDHEADER_HPP
#include <iostream>
#include "../inc/colors.h"

class IHandHeader;
#include "../inc/AMateria.hpp"
class IHandHeader
{
	public:
		virtual ~IHandHeader(){};
		virtual void set_first(AMateria *) = 0;
		virtual void set_last(AMateria *) = 0;
		virtual void rm_mat(AMateria *) = 0;
		virtual void add_mat(AMateria *rhs) = 0;
		virtual void erase_mat(AMateria *rhs) = 0;
};
#endif
