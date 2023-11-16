/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MatHandler.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATHANDLER_HPP
#define __MATHANDLER_HPP
#include <iostream>
#include "../inc/colors.h"
#include "../inc/AMateria.hpp"

class MatHandler
{
	private:
		MatHandler	*_prev;
		MatHandler	*_next;
		AMateria	*_mat_point;
	public:
	MatHandler();
	MatHandler(MatHandler&);
	MatHandler &operator=(MatHandler&);
	~MatHandler();
	MatHandler *get_handler(AMateria*);
	MatHandler *get_next();
	void set_next(MatHandler *rhs);
	MatHandler *get_prev();
	void set_prev(MatHandler *rhs);
	AMateria *get_mat();
	void set_mat(AMateria * rhs);
	void rm_mat(AMateria * rhs);
};

#endif
