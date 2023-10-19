/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP
#define __BRAIN_HPP
#include "../inc/colors.h"
#include <iostream>
#define NR_IDEAS 100
class Brain
{
	private:
		std::string	_ideas[NR_IDEAS];

	public:
		Brain();
		Brain(std::string);
		~Brain();
		void setIdea(int, std::string);
		std::string &getIdea(int);
};

#endif
