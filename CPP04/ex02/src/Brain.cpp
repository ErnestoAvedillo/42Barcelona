/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() 
{
	for (int i = 0; i < NR_IDEAS; i++)
		this->setIdea(i, "empty");

	std::cout << "Creating " << NR_IDEAS << " empty ideas.." << std::endl;
}

Brain::Brain(std::string my_idea)
{
	for (int i = 0; i < NR_IDEAS; i++)
		this->setIdea(i, "empty");
	std::cout << "Creating " << NR_IDEAS << " ideas named" << my_idea << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destroyed the " << NR_IDEAS << " ideas." << std::endl;
}

void Brain::setIdea(int n, std::string s)
{
	if (n < 0 || n >= NR_IDEAS)
		this->_ideas[n] = s;
}
std::string &Brain::getIdea(int n)
{
	if (n < 0)
		return _ideas[0];
	else if (n >= NR_IDEAS)
		return _ideas[NR_IDEAS -1];
	return _ideas[n];
}
