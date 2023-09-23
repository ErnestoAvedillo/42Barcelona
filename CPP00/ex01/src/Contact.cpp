/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 07:52:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/15 07:52:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void Contact::fill_first_name()
{
	std::cout << "Please input first name: ";
	std::cin >> contact[first_name];
	return ;
};
void Contact::fill_last_name()
{
	std::cout << "Please input last name: ";
	std::cin >> contact[last_name];
	return ;
};
void Contact::fill_nickname()
{
	std::cout << "Please input nickname: ";
	std::cin >> contact[nickname];
	return;
};
void Contact::fill_phone_number()
{
	std::cout << "Please input phone number: ";
	std::cin >> contact[phone_number];
	return;
};
void Contact::fill_darkest_secret()
{
	std::cout << "Please input darkest secret: ";
	std::cin >> contact[darkest_secret];
	return;
};

void Contact::fill_contact()
{
	fill_first_name();
	fill_last_name();
	fill_nickname();
	fill_phone_number();
	fill_darkest_secret();
}

void Contact::print_contact()
{
	int i;
	std::string str;

	i = -1;
	while (++i < max_data_contact)
	{
		if (contact[i].size() <= max_print_len)
		{
			std::cout << std::setfill(' ') << std::setw(10) << contact[i] << std::ends;
			std::cout << "|" << std::ends;
		}
		else
		{
			str = contact[i];
			str.resize(max_print_len - 1);
			std::cout << str << ".";
			std::cout << "|" << std::ends;
		}
	}
	std::cout << std::endl;
}

std::string Contact::get_name()
{
	return(contact[first_name]);
}