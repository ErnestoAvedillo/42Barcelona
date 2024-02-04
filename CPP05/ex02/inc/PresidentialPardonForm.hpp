/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:57:46 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/04 15:48:04 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "../inc/Form.hpp"
# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>

class PresidentialPardonForm : public Form
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string);
	PresidentialPardonForm(const PresidentialPardonForm &);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &);
	void execute(Bureaucrat const &) const;
	std::string GetTarget() const;
};
std::ostream &operator<<(std::ostream &, PresidentialPardonForm const &);
#endif
