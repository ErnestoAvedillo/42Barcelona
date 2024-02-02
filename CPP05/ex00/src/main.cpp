/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/01 19:12:13 by eavedill         ###   ########.fr       */
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

int main(void)
{
	print_title("Test Nr1.:default creator", GREEN, BLUE);
	Bureaucrat oper1;
	std::cout << "Default Bureaucrat created " << oper1 << std::endl;
	print_title("Test Nr2.:copy creator", GREEN, BLUE);
	Bureaucrat *oper2 = new Bureaucrat(oper1);
	std::cout << "Bureaucrat new created " << *oper2 << std::endl;
	print_title("Test Nr3.:asignation operation", GREEN, BLUE);
	Bureaucrat mid_oper("mid_oper", 75);
	std::cout << "Created: " << mid_oper;
	*oper2 = mid_oper;
	std::cout << "Asigned midoper to oper2: now oper2 is" << *oper2 << std::endl;
	print_title("Test Nr4.:Too high grade creation", RED, BLUE);
	Bureaucrat oper3("Too much grade", 0);
	std::cout << BLUE << oper3 << RESET << std::endl;
	print_title("Test Nr5.:Too low grade creation", RED, BLUE);
	Bureaucrat oper4("Too low grade", 151);
	std::cout << BLUE << oper4 << RESET << std::endl;
	print_title("Test Nr6.: Increment grade over limit", RED, BLUE);
	oper3.IncGrade();
	std::cout << BLUE << oper3 << RESET << std::endl;
	print_title("Test Nr7.: Decrement grade over limit", RED, BLUE);
	oper4.DecGrade();
	std::cout << BLUE << oper4 << RESET << std::endl;
	print_title("Finish tests", YELLOW, BLUE);
	delete oper2;
}
