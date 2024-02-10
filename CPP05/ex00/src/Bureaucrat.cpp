/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/10 16:15:37 by eavedill         ###   ########.fr       */
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
	catch (std::exception &e)
	{
		if (e.what() == std::string(ERR_TOO_HIGH))
			this->GradeTooHighException();
		else if (e.what() == std::string(ERR_TOO_LOW))
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
	catch (std::exception &e)
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
	catch (std::exception &e)
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
		throw std::runtime_error(ERR_TOO_HIGH);
	else if (grade > MIN_GRADE)
		throw std::runtime_error(ERR_TOO_LOW);

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

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &b)
{
	ost << "Name: " << b.GetName() << " with grade " << b.GetGrade() << " ";
	return ost;
}
