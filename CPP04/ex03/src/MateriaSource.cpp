
#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() : _type("vacio") 
{
	_cur_mat = 0;
}
MateriaSource::MateriaSource(const std::string &type): _type(type) 
{
	_cur_mat = 0;
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

void MateriaSource::learnMateria(AMateria *rhs)
{
	if(_list_mat[_cur_mat])
	{
		_list_mat[_cur_mat]->dec_use();
		_list_mat[_cur_mat] = rhs;
	}
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
