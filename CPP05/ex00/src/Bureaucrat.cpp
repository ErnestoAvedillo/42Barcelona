/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("Common")
{
    _grade = 75;
	std::cout << "Creating " << _name << " Beaurocrat.";
	std::cout << " with grade " << _grade << "."<< std::endl;
}
Bureaucrat::Bureaucrat(std::string my_name, int my_grade) : _name(my_name), _grade(my_grade)
{
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
    *this = rhs;
    return (*this);
}

int Bureaucrat::GetGrade()
{
    return (_grade);
}
int Bureaucrat::IncGrade()
{
    try
    {
        if (_grade == 0)
            throw;
        else
            _grade--;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Grade out of range" << e.what() << std::endl;
    }
    return (_grade);
}
int Bureaucrat::DecGrade()
{
    try
    {
        if (_grade == 150)
            throw;
        else
            _grade++;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Grade out of range" << e.what() << std::endl;
    }

}
std::string Bureaucrat::GetName()
{
    return (_name);
}
