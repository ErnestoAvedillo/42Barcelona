/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:27:03 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/05 07:20:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

static Form *makeShrabb(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static Form *makeRobot(std::string target)
{
	return (new RobotomyRequestForm (target));
}

static Form *makePresident(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Intern::Intern()
{
	std::cout << "Creating an intern worker." << std::endl;
}

Intern::Intern(Intern &rhs)
{
	std::cout << "Copy method from other intern worker." << std::endl;
	*this = rhs;
}

Intern::~Intern()
{
	std::cout << "Destroying an intern worker." << std::endl;
}

Intern &Intern::operator=(Intern &rhs)
{
	std::cout << "Asignation from other intern worker." << std::endl;
	if (this == &rhs)
		return *this;

	return *this;
}

Form *Intern::makeForm(const std::string my_name,const std::string my_target)
{
	std::string form_names[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	Form *(*form_clases[])(const std::string target) = {&makeShrabb, &makeRobot, &makePresident};
	for (size_t i = 0; i < 3; i++)
	{
		if (my_name == form_names[i])
		{
			std::cout << GREEN "Class " << my_name << " created." RESET << std::endl;
			return (form_clases[i](my_target));
		}
	}
	std::cout << RED "Name of the clase not found." RESET << std::endl;
	return NULL;
}
