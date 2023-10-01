/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 07:52:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/15 07:52:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOOK_H
 #define __PHONEBOOOK_H
# include "../inc/Contact.hpp"
# define max_contacts 8

class PhoneBook
{
private:
	Contact my_contact[max_contacts];
	int curr_contact;
public:
	PhoneBook() : curr_contact(-1){}
	void add_contact();
	void search_contact();
	void print_all_contacts();
	std::string get_name(int nr);
};

#endif