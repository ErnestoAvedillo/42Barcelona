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
		int _cur_idea;
	public:
		Brain();
		Brain(std::string);
		Brain(const Brain&);
		Brain &operator=(const Brain&);
		~Brain();
		std::string getIdea(int) const;
		void addIdea(std::string);
		int getCurIdea();
		void prtAllIdeas();
};

#endif
