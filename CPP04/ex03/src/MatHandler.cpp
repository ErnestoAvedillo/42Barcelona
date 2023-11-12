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

#include "../inc/MatHandler.hpp"
#include "../inc/AMateria.hpp"

MatHandler::MatHandler()
{
	_prev= NULL;
	_next = NULL;
	_mat_point = NULL;
}

MatHandler::MatHandler(MatHandler &rhs)
{
	_prev= rhs.get_prev();
	_next = rhs.get_next();
	_mat_point = rhs.get_mat();
}
MatHandler &MatHandler::operator=(MatHandler &rhs)
{
	_prev= rhs.get_prev();
	_next = rhs.get_next();
	_mat_point = rhs.get_mat();
	return *this;
}
MatHandler::~MatHandler()
{
	std::cout << "Delete handler " << this << "With material " << _mat_point->getType();
	std::cout << " and Pointer " _mat_point << std::endl;
}

MatHandler *MatHandler::get_handler(AMateria *rsh)
{
	MatHandler *tmp = this;
	while (tmp->get_mat() != rsh && tmp->get_next())
		tmp = tmp->get_next();
	if (tmp->get_mat() != rsh)
		return tmp;
	return NULL;
}

MatHandler *MatHandler::get_next()
{
	return _next;
}
void MatHandler::set_next(MatHandler *rhs)
{
	_next = rhs;
}
MatHandler * MatHandler::get_prev()
{
	return _prev;
}
void MatHandler::set_prev(MatHandler *rhs)
{
	_prev = rhs;
}

AMateria *MatHandler::get_mat()
{
	return _mat_point;
}

void MatHandler::set_mat(AMateria * rhs)
{
	_mat_point = rhs;
}
