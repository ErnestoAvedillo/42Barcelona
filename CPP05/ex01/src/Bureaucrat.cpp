/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/02 10:45:53 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Common")
{
	this->AssignGrade(MAX_GRADE);
	std::cout << "Creating " << _name << " Beaurocrat.";
	std::cout << " with grade " << _grade << "."<< std::endl;
}
Bureaucrat::Bureaucrat(std::string my_name, int my_grade)
{
	this->PutName(my_name);
	try
	{
		this->AssignGrade(my_grade);
	}
	catch (int err_no)
	{
		if (err_no == ERR_TOO_HIGH)
			this->GradeTooHighException();
		else if (err_no == ERR_TOO_LOW)
			this->GradeTooLowException();
		else
			std::cout << "Non graded error detected" << std::endl;
	}
	std::cout << "Creating " << _name << " Beaurocrat.";
	std::cout << " with grade " << _grade << "."<< std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destroying " << _name << " Beaurocrat.";
	std::cout << " with grade " << _grade << "."<< std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	*this = b;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.GetName();
		this->_grade = rhs.GetGrade();
	}
	return (*this);
}

int Bureaucrat::GetGrade() const
{
	return (_grade);
}

int Bureaucrat::IncGrade()
{
	try
	{
		this->AssignGrade(--_grade);
	}
	catch(int err_no)
	{
		this->GradeTooHighException();
	}
	return (_grade);
}

int Bureaucrat::DecGrade()
{
	try
	{
		this->AssignGrade(++_grade);
	}
	catch (int err_no)
	{
		this->GradeTooLowException();
	}
	return (_grade);
}

void Bureaucrat::PutName(const std::string my_name)
{
	_name = my_name;
}

std::string Bureaucrat::GetName() const
{
	return (_name);
}

int Bureaucrat::AssignGrade(const int grade)
{
	_grade = grade;
	if (grade < MAX_GRADE)
		throw ERR_TOO_HIGH;
	else if (grade > MIN_GRADE)
		throw ERR_TOO_LOW;

	return (_grade);
}

void Bureaucrat::GradeTooLowException()
{
	std::cout << "The Bureaucrat " << *this << " got a grade over the minimum of 150." << std::endl;
	std::cout << "Min value asigned." << std::endl;
	_grade = MIN_GRADE;
}

void Bureaucrat::GradeTooHighException() 
{
	std::cout << "The Bureaucrat " << *this << " got a grade over the maximum of 1." << std::endl;
	std::cout << "Max value asigned." << std::endl;
	_grade = MAX_GRADE;
}

void Bureaucrat::signForm(bool can_sign, Form &f)
{
	if (can_sign)
		std::cout << *this << " signed the " << f << std::endl;
	else
		std::cout << *this << " could'nt sign the " << f << " because has not a proper grade." << std::endl;
}

void Bureaucrat::execForm(bool is_signed, bool can_exec, Form &f)
{
	if (!is_signed)
		std::cout << *this << " tried to sign an unsigned Form :" << f << std::endl;
	else if (can_exec)
		std::cout << *this << " executed the " << f << std::endl;
	else
		std::cout << *this << " could'nt execute the " << f << " because has not a proper grade." << std::endl;
}

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &b)
{
	ost << "Name: " << b.GetName() << " with grade " << b.GetGrade() << " ";
	return ost;
}
