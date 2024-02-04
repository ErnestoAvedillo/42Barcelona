/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:00:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/04 16:24:51 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Form.hpp"

Form::Form()
{
	_name = "Standard";
	_min_grade_exec = 50;
	_min_grade_sign = 100;
}

Form::Form(std::string my_name, int sign_grade, int exec_grade)
{
	_name = my_name;
	_signed = false;
	_executed = false;
	_min_grade_exec = 0;
	_min_grade_sign = 0;
	try
	{
		this->AssignGradeSign(sign_grade);
	}
	catch (int err_no)
	{
		if (err_no > GROUP_ERROR_HIGH && err_no < GROUP_ERROR_LOW)
			this->GradeTooHighException(err_no);
		else if (err_no > GROUP_ERROR_LOW)
			this->GradeTooLowException(err_no);
	}
	
	try
	{
		this->AssignGradeExec(exec_grade);
	}
	catch (int err_no)
	{
		if (err_no > GROUP_ERROR_HIGH && err_no < GROUP_ERROR_LOW)
			this->GradeTooHighException(err_no);
		else if (err_no > GROUP_ERROR_LOW)
			this->GradeTooLowException(err_no);
	}
}

Form::Form(const Form &rhs)
{
	*this = rhs;
}

Form::~Form()
{
	std::cout << "Destroying " << _name << " Form.";
	std::cout << " with minimum sign grade " << _min_grade_sign << " ,";
	std::cout << " and  minimum execution grade " << _min_grade_exec << "." << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	_name = rhs.GetName();
	_min_grade_exec = rhs.GetGradeExec();
	_min_grade_sign = rhs.GetGradeSign();
	return (*this);
}

std::string Form::GetName() const
{
	return (_name);
}

int Form::GetGradeSign() const
{
	return (_min_grade_sign);
}

int Form::GetGradeExec() const
{
	return (_min_grade_exec);
}

void Form::AssignGradeSign(const int grade)
{
	_min_grade_sign= grade;
	if (grade < MAX_GRADE)
		throw SIGN_TOO_HIGH;
	else if (grade > MIN_GRADE)
		throw SIGN_TOO_LOW;
}

void Form::AssignGradeExec(const int grade)
{
	_min_grade_exec = grade;
	if (grade < MAX_GRADE)
		throw EXEC_TOO_HIGH;
	else if (grade > MIN_GRADE)
		throw EXEC_TOO_LOW;
}

void Form::GradeTooLowException(int type)
{
	if (type == SIGN_TOO_LOW)
	{
		std::cout << RED "ERROR!!." RESET;
		std::cout << "The Form " << *this << " got a sign grade over the minimum of 150." << std::endl;
		std::cout << "Min value asigned." << std::endl;
		_min_grade_sign = MIN_GRADE;
	}
	else if (type == EXEC_TOO_LOW)
	{
		std::cout << RED "ERROR!!." RESET;
		std::cout << "The Form " << *this << " got a exec grade over the minimum of 150." << std::endl;
		std::cout << "Min value asigned." << std::endl;
		_min_grade_exec = MIN_GRADE;
	}
	else if (type == EXEC_ERROR_NOT_SIGNED)
	{
		std::cout << RED "ERROR!!." RESET;
		std::cout << "Document not signed. Please sign it before it's execution." << std::endl;
	}
	else if (type == SIGN_ERROR_TRY)
	{
		std::cout << RED "ERROR!!." RESET;
		std::cout << "The Form " << *this << " has been tried to be signed by burocrat of lower level than required." << std::endl;
		std::cout << RED "Form not signed." RESET << std::endl;
	}
	else if (type == EXEC_ERROR_TRY)
	{
		std::cout << RED "ERROR!!." RESET;
		std::cout << "The Form " << *this << " has been tried to be executed by burocrat of lower level than required." << std::endl;
		std::cout << RED "Form not executed." RESET << std::endl;
	}
}

void Form::GradeTooHighException(int type)
{
	if (type == SIGN_TOO_HIGH)
	{
		std::cout << RED "ERROR!!." RESET;
		std::cout << "The Form " << *this << " got a sign grade over the  maximum of 1." << std::endl;
		std::cout << "Max value asigned." << std::endl;
		_min_grade_sign = MAX_GRADE;
	}
	else if (type == EXEC_TOO_HIGH)
	{
		std::cout << RED "ERROR!!." RESET;
		std::cout << "The Form " << *this << " got a exec grade over the  maximum of 1." << std::endl;
		std::cout << "Max value asigned." << std::endl;
		_min_grade_exec = MAX_GRADE;
	}
}

bool Form::SignForm(int grade)
{
	if(_min_grade_sign < grade)
		throw SIGN_ERROR_TRY;
	std::cout << "Form: " << *this << GREEN " HAS BEEN SIGNED." RESET << std::endl;
	return (true);
}

void Form::BeSigned(Bureaucrat &b) 
{
	try
	{
		this->_signed = this->SignForm(b.GetGrade());
	}
	catch(int type)
	{
		this->GradeTooLowException(type);
	}
	b.signForm(_signed, *this);
}

bool Form::ExecForm(int grade) const
{
	if (!_signed)
	{
		throw EXEC_ERROR_NOT_SIGNED;
		return (false);
	}
	else if (_min_grade_exec < grade)
		throw EXEC_ERROR_TRY;
	std::cout << "Form: " << *this << GREEN " HAS BEEN EXECUTED." RESET << std::endl;
	return (true);
}

void Form::BeExec(Bureaucrat &b)
{
	try
	{
		this->_executed = this->ExecForm(b.GetGrade());
		this->execute(b);
	}
	catch (int type)
	{
		this->GradeTooLowException(type);
	}
}

bool Form::IsSigned() const
{
	return (_signed);
}

bool Form::IsExecuted() const
{
	return (_executed);
}

void Form::PutName(std::string n)
{
	_name = n;
}

std::ostream &operator<<(std::ostream &ost, Form const &b)
{
	ost << "Name: " << b.GetName() << " with sign grade " << b.GetGradeSign() << " ";
	ost << "and exec grade " << b.GetGradeExec();
	if (b.IsSigned())
		ost << GREEN " SIGNED" RESET;
	else
		ost << RED " NOT SIGNED" RESET;
	if (b.IsExecuted())
		ost << GREEN " EXECUTED" RESET;
	else
		ost << RED " NOT EXECUTED" RESET;

	return ost;
}
