/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:03:09 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/04 16:21:36 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("DefaultRobot", 72, 45)
{
	_target = "Home";
}

RobotomyRequestForm::RobotomyRequestForm(std::string my_target) : Form("DefaultRobot", 72, 45)
{
	_target = my_target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s)
{
	*this = s;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &s)
{
	this->PutName(s.GetName());
	this->AssignGradeExec(s.GetGradeExec());
	this->AssignGradeSign(s.GetGradeSign());
	return (*this);
}

std::string RobotomyRequestForm::GetTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	if (this->IsExecuted())
	{
		srand((unsigned int)time((time_t *)NULL));
		int val = rand();
		std::cout << "Impresión del valor val = "<< val << std::endl; 
		if (val % 2 == 1)
		{
			std::cout << RED "BRRRrrrrRRrrrrbrrrrrr" RESET << std::endl;
			b.execForm(this->IsSigned(), this->IsExecuted(), *this);
		}
		else
		{
			std::cout << RED "Form not executed." RESET << std::endl;
		}
	}
	else
	{
		std::cout << RED "Form not executed." RESET << std::endl;
	}
}

std::ostream &operator<<(std::ostream &ost, RobotomyRequestForm const &b)
{
	ost << "Name: " << b.GetName() << " with sign grade " << b.GetGradeSign() << " ";
	ost << ", exec grade " << b.GetGradeExec();
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
