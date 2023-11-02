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
class MateriaSource : public IMateriaSource
{
private:
	std::string _type;

public:
	MateriaSource();
	MateriaSource(std::string&);
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria *createMateria(const std::string &);
};
#endif