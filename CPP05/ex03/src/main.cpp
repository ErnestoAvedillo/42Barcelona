/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/04 19:20:35 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/main.h"

void print_title(std::string msg, std::string color_text, std::string color_border)
{
	std::cout << color_border << "|";
	std::cout << std::setfill('*') << std::setw(5) << "";
	std::cout << color_text << msg << color_border << std::setw(5) << "|";
	std::cout << RESET << std::endl;
}

// 145  137  -- 72   45 -- 25 5
int main(void)
{
	print_title("Part 1: Creating operators", GREEN, BLUE);
	Bureaucrat oper150("oper150",150);
	std::cout << GREEN << oper150 << " created." RESET << std::endl;
	Bureaucrat oper140("Oper140", 140);
	Bureaucrat oper130("Oper130", 130);
	Bureaucrat oper50("Oper50", 50);
	Bureaucrat oper30("Oper30", 30);
	Bureaucrat oper20("Oper20", 20);
	Bureaucrat oper1("Oper1", 1);
	print_title("*************************************************************", YELLOW, YELLOW);
	print_title("PArt 2 Creating forms:", GREEN, BLUE);
	Intern my_slave;
	Form *form1 = my_slave.makeForm("ShrubberyCreationForm", "My Home");
	Form *form2 = my_slave.makeForm("RobotomyRequestForm", "Robo Form");
	Form *form3 = my_slave.makeForm("PresidentialPardonForm", "My Presi");
	print_title("Tests Form", GREEN, BLUE);
	print_title("Test Nr 1:Shrubbery Not signed", RED, BLUE);
	form1->BeSigned(oper150);
	print_title("Test Nr 2:Shrubberry signed", GREEN, BLUE);
	form1->BeSigned(oper140);
	print_title("Test Nr 3:Shrubbery Not executed", RED, BLUE);
	form1->BeExec(oper140);
	print_title("Test Nr 4:Shrubbery executed", GREEN, BLUE);
	form1->BeExec(oper130);
	print_title("Test Nr 5:Robotomy not signed", RED, BLUE);
	form2->BeSigned(oper130);
	print_title("Test Nr 6:Robotomy signed", GREEN, BLUE);
	form2->BeSigned(oper50);
	print_title("Test Nr 7:Robotomy not executed", RED, BLUE);
	form2->BeExec(oper50);
	print_title("Test Nr 8:Robotomy executed", GREEN, BLUE);
	form2->BeExec(oper30);
	print_title("Test Nr 9:Pardon not signed", RED, BLUE);
	form3->BeSigned(oper30);
	print_title("Test Nr 10:Pardon signed", GREEN, BLUE);
	form3->BeSigned(oper20);
	print_title("Test Nr 11:Pardon not executed", RED, BLUE);
	form3->BeExec(oper20);
	print_title("Test Nr 11:Pardon executed", GREEN, BLUE);
	form3->BeExec(oper1);
	print_title("Finish tests", RED, BLUE);
}
