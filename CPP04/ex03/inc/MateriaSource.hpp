/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP
#define __MATERIASOURCE_HPP
#include <iostream>
#include "../inc/colors.h"
#include "../inc/IMateriaSource.hpp"
#define MAX_MAT 4
class MateriaSource : public IMateriaSource
{
private:
	std::string	_type;
	AMateria	*_list_mat[4];
	int _cur_mat;

public:
	MateriaSource();
	MateriaSource(const std::string&);
	~MateriaSource();
	MateriaSource(MateriaSource &);
	MateriaSource & operator=(MateriaSource &);
	void learnMateria(AMateria*);
	AMateria *createMateria(const std::string &);
	int get_Curmat();
	AMateria *get_Materia(int);
	std::string get_Type();
};
#endif
