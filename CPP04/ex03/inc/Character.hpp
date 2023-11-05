/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP
#define __CHARACTER_HPP
#include "../inc/ICharacter.hpp"
#include "../inc/AMateria.hpp"
#define MAX_MAT 4

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria *_materia[MAX_MAT];
		int _idx;

	public:
		Character();
		Character(std::string);
		Character(std::string &);
		Character(Character &);
		~Character();
		Character &operator=(Character &);
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		AMateria *getMateria(int idx);
		void printMaterias();
		void printTrash();
};
#endif
