/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:59:10 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/02 10:50:46 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <exception>
#include "../inc/limit_grades.h"

class Form;
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string _name;
	bool		_signed;
	bool		_executed;
	int			_min_grade_sign;
	int			_min_grade_exec;
public:
	Form();
	Form(std::string, int, int);
	Form(const Form &);
	~Form();
	Form &operator=(const Form &);
	std::string GetName() const;
	int GetGradeSign() const;
	int GetGradeExec() const;
	void AssignGradeSign(const int);
	void AssignGradeExec(const int);
	void GradeTooHighException(int);
	void GradeTooLowException(int);
	bool SignForm(int grade);
	void BeSigned(Bureaucrat &);
	void BeExec(Bureaucrat &);
	bool ExecForm(int);
	bool IsSigned() const;
	bool IsExecuted() const;
};
std::ostream &operator<<(std::ostream &, Form const &);
#endif
