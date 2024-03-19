/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/17 11:33:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
class ASpell;
#include "ATarget.hpp"

class ASpell
{
	private:
		std::string _name;
		std::string _effects;

	public:
		ASpell();
		ASpell(ASpell const &);
		ASpell(std::string &, std::string &);
		ASpell(const std::string &, const std::string &);
		ASpell &operator=(ASpell const &);
		virtual ~ASpell();
		std::string const &getName() const;
		std::string const &getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(ATarget const &);
};

#endif
