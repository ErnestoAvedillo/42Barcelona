/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/17 11:32:40 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"
class Fwoosh: public ASpell
{
	private:

	public:
		Fwoosh();
		~Fwoosh();
		virtual ASpell *clone() const;
};

#endif
