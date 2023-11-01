
#include "../inc/MateriaSurce.hpp"

MateriaSource::MateriaSource() : _type("vacio") {}
MateriaSource::MateriaSource(std::string &type): _type(type) {}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria const &rhs)
{

}

AMateria *MateriaSource::createMateria(const std::string &str)
{

}