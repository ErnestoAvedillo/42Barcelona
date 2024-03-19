/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:15:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/18 19:29:31 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class Brickwall:public ATarget
{
	private:

	public:
		Brickwall();
		~Brickwall();
		ATarget *clone() const;
};

#endif
