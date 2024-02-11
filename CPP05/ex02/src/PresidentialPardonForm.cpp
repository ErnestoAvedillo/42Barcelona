/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:03:09 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/11 13:18:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("DefaultSchrub", 25, 5)
{
	_target = "Home";
	std::cout << "PresidentialPardonForm " << *this << " created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string my_trget) : Form("DefaultSchrub", 25, 5)
{
	_target = my_trget;
	std::cout << "PresidentialPardonForm " << *this << " created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s)
{
	*this = s;
	std::cout << "PresidentialPardonForm " << *this << " created." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &s)
{
	this->PutName(s.GetName());
	this->AssignGradeExec(s.GetGradeExec());
	this->AssignGradeSign(s.GetGradeSign());
	_target = s.GetTarget();
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &b) const
{
	std::string filename;

	if (this->IsExecuted())
	{
		std::cout << RED << b << " has been pardoned by Zaphod Beeblebrox." RESET << std::endl;
	}
	else
	{
		std::cout << RED "No pardon available for you men." RESET << std::endl;
	}
}

std::string PresidentialPardonForm::GetTarget() const
{
	return (_target);
}

std::ostream &operator<<(std::ostream &ost, PresidentialPardonForm const &b)
{
	ost << "Name: " << b.GetName() << " with sign grade " << b.GetGradeSign() << " ";
	ost << ", exec grade " << b.GetGradeExec() << "and document name " << b.GetTarget();
	if (b.IsSigned())
		ost << GREEN " SIGNED" RESET;
	else
		ost << RED " NOT SIGNED" RESET;
	if (b.IsExecuted())
		ost << GREEN " EXECUTED" RESET;
	else
		ost << RED " NOT EXECUTED" RESET;
	return (ost);
}
