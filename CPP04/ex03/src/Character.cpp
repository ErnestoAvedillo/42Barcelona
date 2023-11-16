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
	_handler = new HandHeader();
}

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		_materia[i] = NULL;
	}
	_handler = new HandHeader ();
}

Character::Character(std::string &name) : _name(name)
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		_materia[i] = NULL;
	}
	_handler = new HandHeader ();
}

Character::Character(Character &rhs)
{
	_name = rhs.getName();
	for (int i = 0; i < MAX_MAT; i++)
		_materia[i] = NULL;
	_handler = new HandHeader ();
	*this = rhs;
}
Character::~Character()
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		if (_materia[i] != NULL)
		{
			_materia[i]->dec_use();
		}
	}
	delete _handler;
}

Character &Character::operator=(Character &rhs)
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		if (_materia[i] != NULL)
		{
			if(_materia[i]->get_use() > 0)
				_materia[i]->dec_use();
			if (_materia[i]->get_use() > 0)
				_handler->rm_mat(_materia[i]);
			else if (_materia[i]->get_owner() == NULL)
				_materia[i]->set_owner(static_cast<void *>(_handler));
			else
				_handler->rm_mat(_materia[i]);
		}
		_materia[i] = rhs.getMateria(i);
		if (_materia[i] != NULL)
		{
			_materia[i]->inc_use();
			_handler->add_mat(_materia[i]);
		}
	}
	return *this;
}

std::string const &Character::getName() const 
{
	return _name;
}

void Character::setName(std::string const &MyName) 
{
	_name = MyName;
}

void Character::equip(AMateria *m) 
{
	if (m == NULL)
		return;
	for (int i = 0; i < MAX_MAT; i++)
		if (_materia[i]== m)
		{
			std::cout << "Materia " << m << " not added. Is already in Character." << std::endl;
			return;
		}
	_handler->add_mat(m);
	for (int i = 0; i < MAX_MAT; i++)
	{
		if (_materia[i]== NULL)
		{
			_materia[i] = m;
			_materia[i]->inc_use();
			std::cout << "Materia " << m << " added in Character." << std::endl;
			return;
		}
	}
	std::cout << "Character full no Materia added." << std::endl;
}
void Character::unequip(int idx) 
{
	if (_materia[idx] !=NULL)
	{
		_materia[idx]->dec_use();
		if (_materia[idx]->get_use() > 0)
			_handler->rm_mat(_materia[idx]);
		else if (_materia[idx]->get_owner() == NULL)
			_materia[idx]->set_owner(static_cast<void*>(_handler));
		else
			_handler->rm_mat(_materia[idx]);
		_materia[idx] = NULL;
	}

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
	std::cout << BLUE "Materials in " << _name << RESET << std::endl;

	for (int i = 0; i < MAX_MAT; i++)
	{
		std::cout << "Materia Nº" << i << " in memory pointer " << _materia[i];
		if (_materia[i] !=  NULL)
			std::cout << " with name " << _materia[i]->getType() << " used " << _materia[i]->get_use() ;
		std::cout << "." << std::endl;
	}
}

void Character::printHandler()
{
	std::cout << BLUE "Materials in handler " << _name << " pointer " << _handler << RESET << std::endl;
	MatHandler *tmp;
	AMateria *MatTemp;
	tmp = _handler->get_first();
	while (tmp != NULL)
	{
		MatTemp = tmp->get_mat();
		std::cout << " En handler " << tmp <<" Material " <<  MatTemp->getType(); 
		std::cout << " puntero " << MatTemp << " used " << MatTemp->get_use();
		std::cout << std::endl;
		tmp = tmp->get_next();
	}
	
}

