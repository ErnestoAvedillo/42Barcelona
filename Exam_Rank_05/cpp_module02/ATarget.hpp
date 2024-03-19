/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/17 11:33:00 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ATarget;
#include "ASpell.hpp"
class ATarget
{
	private:
		std::string _type;

	public:
		ATarget();
		ATarget(ATarget const &);
		ATarget &operator=(ATarget const &);
		ATarget(std::string &);
		ATarget(const std::string &);
		~ATarget();
		std::string const &getType() const;
		virtual ATarget *clone() const = 0;
		void getHitBySpell(ASpell const &) const;
};

#endif
