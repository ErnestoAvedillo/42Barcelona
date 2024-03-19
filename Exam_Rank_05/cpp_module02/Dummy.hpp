/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/17 11:32:50 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class Dummy:public ATarget
{
	private:

	public:
		Dummy();
		~Dummy();
		ATarget *clone() const;
};

#endif
