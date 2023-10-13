/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:27:03 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/26 21:27:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn't be asking for more!";
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain(std::string level )
{
	int	i = 0;
	std::string name[] = {"debug","info","warning","error"};

	void (Harl::*my_table_fun[]) () = {
		&Harl::debug, \
		&Harl::info, \
		&Harl::warning, \
		&Harl::error};
	for (i = 0; i < 4; i++)
	{
		if(name[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			(this->*my_table_fun[0])();
		case 1:
			(this->*my_table_fun[1])();
		case 2:
			(this->*my_table_fun[2])();
		case 3:
		{
			(this->*my_table_fun[3])();
			break;
		}
		default:
			std::cout << "Message does not match" << std::endl;
	}

}
