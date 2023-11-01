/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ICharacter.hpp"
#include "../inc/Character.hpp"

Character::Character(): _name("void")
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		_materia[i] = NULL;
	}
	_idx = 0;
}
Character::Character(std::string &name) : _name(name)
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		_materia[i] = NULL;
	}
	_idx = 0;
}

Character::Character(Character &rhs)
{
	*this = rhs;
}
Character::~Character()
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		delete _materia;
	}
}

Character &Character::operator=(Character &rhs)
{
	this->_name = rhs.getName();
	for (int i = 0; i < MAX_MAT; i++)
	{
		_materia[i] = rhs.getMateria(i);
	}
	_idx = 0;
	return *this;
}
std::string const &Character::getName() const 
{
	return _name;
}
void Character::equip(AMateria *m) 
{
	_materia[_idx] = m;
	_idx++;
	if (_idx == 4)
		_idx = 0;
}
void Character::unequip(int idx) 
{
	_materia[idx] = NULL;
}
void Character::use(int idx, ICharacter &target) 
{
	_materia[idx]->use(target);
}

AMateria *Character::getMateria(int idx)
{
	return _materia[idx];
}
