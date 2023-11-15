/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandHEeader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HandHeader.hpp"

HandHeader::HandHeader()
{
	_first = NULL;
	_last = NULL;
}

HandHeader::HandHeader(HandHeader &rhs)
{
	*this = rhs;
}

HandHeader::~HandHeader()
{
	MatHandler *tmp = _first;
	MatHandler *tmp2;
	while (tmp != NULL)
	{
		tmp->set_prev(NULL);
		AMateria *MatTmp = tmp->get_mat();
		tmp2 = tmp->get_next();
		if (tmp2 == tmp)
			tmp2 = NULL;
		delete tmp;
		if (MatTmp->get_use() == 0 && MatTmp->get_owner() == this)
			delete MatTmp;
		tmp = tmp2;
	}
}

HandHeader &HandHeader::operator=(HandHeader &rhs)
{
	_first = rhs.get_first();
	_last = rhs.get_last();
	return *this;
}

MatHandler *HandHeader::get_first()
{
	return _first;
}
MatHandler *HandHeader::get_last()
{
	return _last;
}
void HandHeader::set_first(AMateria *rhs)
{
	MatHandler *tmp = new MatHandler();
	tmp->set_next(_first);
	tmp->set_mat(rhs);
	if (_first != NULL)
		_first->set_prev(tmp);
	_first = tmp;
}
void HandHeader::set_last(AMateria *rhs)
{
	MatHandler *tmp = new MatHandler();
	if (_last == NULL && _first == NULL)
	{
		_first = tmp;
		_last = tmp;
		tmp->set_mat(rhs);
		return;
	}
	tmp->set_prev(_last);
	tmp->set_mat(rhs);
	if (_last !=NULL)
		_last->set_next(tmp);
	_last = tmp;
}

void HandHeader::rm_mat(AMateria *rhs)
{
	MatHandler *tmp;
	MatHandler *tmp1;
	MatHandler *tmp2;
	tmp = _first;
	while (tmp != NULL && tmp->get_mat() != rhs)
		tmp = tmp->get_next();
	if (tmp == NULL)
		return;
	tmp1 = tmp->get_prev();
	tmp2= tmp->get_next();
	if (tmp1 != NULL)
		tmp1->set_next(tmp2);
	else
		_first = tmp2;
	if (tmp2 != NULL)
		tmp2->set_prev(tmp1);
	else
		_last = tmp1;
	delete tmp;
}

void HandHeader::add_mat(AMateria *rhs)
{
	MatHandler *tmp;
	tmp = _first;
	while (tmp != NULL)
	{
		if (tmp->get_mat() == rhs)
			return;
		tmp = tmp->get_next();
	}	
	this->set_last(rhs);
}
