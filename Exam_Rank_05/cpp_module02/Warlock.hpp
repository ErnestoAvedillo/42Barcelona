/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/21 21:17:18 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		SpellBook _spellBook;

		Warlock();
		Warlock(Warlock const &);
		Warlock &operator=(Warlock const &);

	public:
		Warlock(std::string &, std::string &);
		Warlock(std::string const &, std::string const &);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &);
		void introduce() const;
		void learnSpell(ASpell *) ;
		void forgetSpell(std::string const ) ;
		void launchSpell(std::string const , ATarget const &) ;
};

#endif
