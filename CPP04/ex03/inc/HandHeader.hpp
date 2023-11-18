/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandHEeader.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HANDHEADER_HPP
#define __HANDHEADER_HPP
#include <iostream>
#include "../inc/colors.h"

class HandHeader;
#include "../inc/IHandHeader.hpp"
#include "../inc/MatHandler.hpp"
#include "../inc/AMateria.hpp"
class HandHeader: public IHandHeader
{
	private:
		MatHandler *_first;
		MatHandler *_last;
	public:
		HandHeader();
		HandHeader(HandHeader&);
		~HandHeader();
		HandHeader &operator=(HandHeader&);
		MatHandler *get_first();
		MatHandler *get_last();
		void set_first(AMateria *);
		void set_last(AMateria *);
		void rm_mat(AMateria *);
		void add_mat(AMateria *);
		void erase_mat(AMateria *);
};
#endif
