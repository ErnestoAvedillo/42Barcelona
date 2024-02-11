/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:03:09 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/11 13:20:04 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("DefaultSchrub",145,137)
{
	_target = "Home";
	std::cout << "ShrubberyCreationForm " << *this << " created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string my_target) : Form("DefaultSchrub", 145, 137)
{
	_target = my_target;
	std::cout << "ShrubberyCreationForm " << *this << " created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s)
{
	*this = s;
	std::cout << "ShrubberyCreationForm " << *this << " created." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	this->PutName(s.GetName());
	this->AssignGradeExec(s.GetGradeExec());
	this->AssignGradeSign(s.GetGradeSign());
	_target = s.GetTarget();
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	std::string filename;

	if (this->IsExecuted())
	{
		filename = _target + TAIL_FILE_NAME;
		std::ofstream outputFile(filename.c_str());
		if (!outputFile.is_open())
			std::cerr << "Error opening the file." << std::endl;
		else
		{
			outputFile << "      ^" << std::endl;
			outputFile << "     /|\\" << std::endl;
			outputFile << "    / * \\" << std::endl;
			outputFile << "   /|   |\\" << std::endl;
			outputFile << "  /|*   *|\\" << std::endl;
			outputFile << " / *     * \\" << std::endl;
			outputFile << "/___________\\" << std::endl;
			outputFile << "     | |" << std::endl;
			outputFile << "     | |" << std::endl;
			outputFile << "     | |" << std::endl;
			outputFile.close();
			std::cout << GREEN "Form executed." RESET << std::endl;
			b.execForm(this->IsSigned(), this->IsExecuted(), *this);
		}
	}
	else
	{
		std::cout << RED "Form not executed." RESET << std::endl;
	}
}

std::string ShrubberyCreationForm::GetTarget() const
{
	return (_target);
}

std::ostream &operator<<(std::ostream &ost, ShrubberyCreationForm const &b)
{
	ost << "Name: " << b.GetName() << " with sign grade " << b.GetGradeSign() << " ";
	ost << ", exec grade " << b.GetGradeExec() << "and document name " << b.GetTarget();
	if (b.IsSigned())
		ost << GREEN " SIGNED" RESET;
	else
		ost << RED " NOT SIGNED" RESET;
	if (b.IsExecuted())
		ost << GREEN " EXECUTED" RESET;
	else
		ost << RED " NOT EXECUTED" RESET;
	return (ost);
}
