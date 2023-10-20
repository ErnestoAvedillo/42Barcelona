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
		this->addIdea("empty");
	_cur_idea = 0;
	std::cout << "Creating " << NR_IDEAS << " empty ideas.." << std::endl;
}

Brain::Brain(std::string my_idea)
{
	for (int i = 0; i < NR_IDEAS; i++)
		this->addIdea("empty");
	_cur_idea = 0;
	std::cout << "Creating " << NR_IDEAS << " ideas named" << my_idea << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destroyed the " << NR_IDEAS << " ideas." << std::endl;
}

void Brain::addIdea(std::string s)
{
	_ideas[_cur_idea] = s;
	_cur_idea++;
	if (_cur_idea >= NR_IDEAS)
		_cur_idea =  0;
}
std::string &Brain::getIdea(int n)
{
	if (n < 0)
		return _ideas[0];
	else if (n >= NR_IDEAS)
		return _ideas[NR_IDEAS -1];
	return _ideas[n];
}

int Brain::getCurIdea()
{
	return _cur_idea;
}

