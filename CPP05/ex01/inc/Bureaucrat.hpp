/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:16:47 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/02 10:44:35 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP
# define _BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "../inc/colors.h"
# include "../inc/limit_grades.h"

class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
    private:
        std::string _name;
		int 		_grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string, int);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &);
        Bureaucrat & operator = (const Bureaucrat &);
        int GetGrade() const;
        int IncGrade();
        int DecGrade();
        std::string GetName() const;
        void PutName(const std::string);
        int AssignGrade(const int);
        void GradeTooHighException();
        void GradeTooLowException();
        void signForm(bool, Form &);
        void execForm(bool, bool, Form &);
};
std::ostream &operator<<(std::ostream &, Bureaucrat const &);
#endif
