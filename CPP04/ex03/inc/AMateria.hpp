/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP
#define __AMATERIA_HPP
#include <iostream>
#include "../inc/colors.h"

class AMateria;
#include "../inc/ICharacter.hpp"
#include "../inc/HandHeader.hpp"
class AMateria
{
    protected:
        std::string     _type;
        unsigned int    _usage;
        ptr      *_owner;
    public:
        AMateria();
        AMateria(std::string const &);
        AMateria(AMateria const &);
        virtual ~AMateria();
        AMateria &operator=(AMateria const &);
        std::string const &getType() const; // Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& );
        void inc_use();
        void dec_use();
        int get_use();
        HandHeader *get_owner();
        void set_owner(HandHeader *);
};
#endif
