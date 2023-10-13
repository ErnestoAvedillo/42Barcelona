/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 07:52:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/15 07:52:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void print_instructions ()
{
	std::cout << "Options to use:" << std::endl;
	std::cout << "ADD: to add a new contact" << std::endl;
	std::cout << "SEARCH: to search for a contact" << std::endl;
	std::cout << "EXIT: to exit the app." << std::endl;
}

int main(void)
{
	std::string	command;
	PhoneBook	my_book;

	std::cout << "Welcome to my BhoneBook agenda." << std::endl;
	print_instructions();
	while(command != "EXIT")
	{
		std::cout << "\nPlease type your option: ";
		std::cin >> command;
		std::cout << "you typed the command: " << command << std::endl;
		if (command == "ADD")
			my_book.add_contact();
		else if (command == "PRINT")
			my_book.print_all_contacts();
		else if (command == "SEARCH")
			my_book.search_contact();
		else
		{
			std::cout << "\nIncorrect option." << std::endl;
			if(std::cin.eof())
				break;
			print_instructions();
		}

	}
	return 0;
}
