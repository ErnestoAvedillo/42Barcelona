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

#include "../inc/Character.hpp"

Character::Character(): _name("void")
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		_materia[i] = NULL;
	}
	_idx = 0;
}Character::Character(std::string name): _name(name)
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
		if (_materia[i] != NULL)
		{
			if (_materia[i]->get_use() == 0)
				delete _materia[i];
			else
				_materia[i]->dec_use();
		}
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
	if (m)
		_materia[_idx]->inc_use();
	_idx++;
	if (_idx == 4)
		_idx = 0;
}
void Character::unequip(int idx) 
{
	_materia[idx] = NULL;
	if (_materia[idx] !=NULL)
		_materia[idx]->dec_use();
}
void Character::use(int idx, ICharacter &target) 
{
	if (idx >= 0 && idx < MAX_MAT && _materia[idx])
		_materia[idx]->use(target);
}

AMateria *Character::getMateria(int idx)
{
	return _materia[idx];
}

void Character::printMaterias()
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		std::cout << "Materia Nº" << i << " in memory pointer " << _materia[i];
		if (_materia[i] !=  NULL)
			std::cout << " with name " << _materia[i]->getType();
		std::cout << "." << std::endl;
	}
}

void Character::printTrash(){}

