/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:57:46 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/04 15:48:06 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "../inc/Form.hpp"
# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>

# define TAIL_FILE_NAME "_shrubbery.txt"

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
	void execute(Bureaucrat const &) const;
	std::string GetTarget() const;
};
std::ostream &operator<<(std::ostream &, ShrubberyCreationForm const &);
#endif
