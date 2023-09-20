/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 07:52:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/15 07:52:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"

void PhoneBook::add_contact()
{
	curr_contact += 1;
	if (curr_contact == max_contacts)
		curr_contact = 0;
	my_contact[curr_contact].fill_contact();
}

void PhoneBook::search_contact()
{
	int			elcontacto;
	std::string nombre;

	elcontacto = -1;
	std::cout << "indica el contacto que buscas: ";
	std::cin >> nombre;
	elcontacto = -1;
	while (++elcontacto < max_contacts)
	{
		if (nombre == get_name(elcontacto))
			break;
	}
	if (elcontacto == max_contacts)
		std::cout << "contacto noencontrado\n";
	else
		my_contact[elcontacto].print_contact();
}

void PhoneBook::print_all_contacts()
{
	int i;

	i = -1;
	while ( ++i < max_contacts)
	{
		my_contact[i].print_contact();
	}
}

std::string PhoneBook::get_name(int nr)
{
	return (my_contact[nr].get_name());
}