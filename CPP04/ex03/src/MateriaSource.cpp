
#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() : _type("vacio") 
{
	_cur_mat = 0;
	for (int i = 0; i < MAX_MAT; i++)
	{
		_list_mat[i] = NULL;
	}
}
MateriaSource::MateriaSource(const std::string &type): _type(type) 
{
	_cur_mat = 0;
	for (int i = 0; i < MAX_MAT; i++)
	{
		_list_mat[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		if(_list_mat[i]->get_use() == 0)
			delete _list_mat[i];
		else
			_list_mat[i]->dec_use();
	}
}
MateriaSource::MateriaSource(MateriaSource &rhs)
{
	*this = rhs;
}

MateriaSource &MateriaSource::operator=(MateriaSource &rhs)
{
	_type = rhs.get_Type();
	_cur_mat = rhs.get_Curmat();
	for (int i = 0; i < MAX_MAT; i++)
	{
		_list_mat[i] = rhs.get_Materia(i);
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *rhs)
{
	if(_list_mat[_cur_mat] )
	{
		_list_mat[_cur_mat]->dec_use();
	}
	_list_mat[_cur_mat] = rhs;
	if (rhs)
		_list_mat[_cur_mat]->inc_use();
	_cur_mat++;
	if (_cur_mat == 4)
	{
		_cur_mat = 0;
	}
}

AMateria *MateriaSource::createMateria(const std::string &str)
{
	for (int i = 0; i < MAX_MAT; i++)
	{
		if (_list_mat[i] && str == _list_mat[i]->getType())
			return _list_mat[i]->clone();
	}
	return (0);
}

int MateriaSource::get_Curmat()
{
	return _cur_mat;
}

AMateria *MateriaSource::get_Materia(int i)
{
	return _list_mat[i];
}

std::string MateriaSource::get_Type()
{
	return  _type;
}