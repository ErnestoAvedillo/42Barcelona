/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:16:47 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/11 12:34:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP
# define _BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "../inc/colors.h"

# define MAX_GRADE 1
# define MIN_GRADE 150
# define INC_GRADE -1
# define ERR_TOO_HIGH "TOO_HIGH"
# define ERR_TOO_LOW "TOO_LOW"

class Bureaucrat
{
    private:
        const std::string _name;
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
        void AssignGrade(const int);
        void GradeTooHighException();
        void GradeTooLowException();
};
std::ostream &operator<<(std::ostream &, Bureaucrat const &);
#endif
