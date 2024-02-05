/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:03:09 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/05 07:26:17 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("DefaultSchrub", 25, 5)
{
	_target = "Home";
}

PresidentialPardonForm::PresidentialPardonForm(std::string my_trget) : Form("DefaultSchrub", 25, 5)
{
	_target = my_trget;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s)
{
	*this = s;
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
		std::cout << GREEN << b << " executed the Presidential order." RESET << std::endl;
		std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox." RESET << std::endl;
	}
	else
	{
		std::cout << RED "No pardon available for _target men." RESET << std::endl;
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
