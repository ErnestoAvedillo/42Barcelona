/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 07:52:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/15 07:52:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */ 
#ifndef __CONTACT_H
 #define __CONTACT_H
#include <string>
#include <iostream>

enum Contact_data
{
	first_name,
	last_name,
	nickname,
	phone_number,
	darkest_secret,
	max_data_contact
};

class Contact
{
	private:
		const size_t __max_print_len;
		std::string __contact[max_data_contact];

	public:
		Contact () :__max_print_len(10){}
		void fill_first_name();
		void fill_last_name();
		void fill_nickname();
		void fill_phone_number();
		void fill_darkest_secret();
		void fill_contact();
		void print_contact();
		std::string get_name();
};
#endif