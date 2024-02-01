/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:16:47 by eavedill          #+#    #+#             */
/*   Updated: 2023/05/06 11:17:21 by eavedill         ###   ########.fr       */
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
        int GetGrade();
        int IncGrade();
        int DecGrade();
        std::string GetName();
};
std::ostream &operator<<( std::ostream &, const Bureaucrat & );
#endif