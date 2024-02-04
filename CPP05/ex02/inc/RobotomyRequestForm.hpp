/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:57:46 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/04 16:18:02 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "../inc/Form.hpp"
# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>
# include <cstdlib>

class RobotomyRequestForm : public Form
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(const RobotomyRequestForm &);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &);
	std::string GetTarget() const;
	void execute(Bureaucrat const &) const;
};
std::ostream &operator<<(std::ostream &, RobotomyRequestForm const &);
#endif
