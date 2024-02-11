/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/11 12:10:38 by eavedill         ###   ########.fr       */
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
	std::cout << "Bureaucrat new created  oper1 copied to oper2 " << *oper2 << std::endl;
	print_title("Test Nr3.:asignation operation", GREEN, BLUE);
	Bureaucrat mid_oper("mid_oper", 75);
	std::cout << "Created: " << mid_oper;
	*oper2 = mid_oper;
	std::cout << "Asigned midoper to oper2: now oper2 is: " << *oper2 << std::endl;
	print_title("Test Nr4.:Too high grade creation", RED, BLUE);
	Bureaucrat oper3("Too high grade", 0);
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
	print_title("*************************************************************", YELLOW, YELLOW);
	print_title("Tests Form", GREEN, BLUE);
	
	print_title("Test Nr 1:Default creation", GREEN, BLUE);
	Form std_form;
	std::cout << "Created :" << std_form << std::endl;
	
	print_title("Test Nr 2:Asigned creation", GREEN, BLUE);
	Form *spec_form = new Form("Special_Form", 25, 75);
	std::cout << "Created :" << *spec_form << std::endl;
	
	print_title("Test Nr 3:Copy creation", GREEN, BLUE);
	Form copy_form(std_form);
	std::cout << "Created :" << copy_form << std::endl;
	
	print_title("Test Nr 4:Asign form", GREEN, BLUE);
	copy_form = *spec_form;
	std::cout << "Asigned form :" << copy_form << std::endl;
	
	print_title("Test Nr 5: LOW assign form sign error", RED, BLUE);
	Form too_low_form("Too Low Form", 151, 151);
	std::cout << "Asigned form :" << too_low_form << std::endl;

	print_title("Test Nr 6:HIGH assign form sign error", RED, BLUE);
	Form too_high_form("Too High Form", 0, 0);
	std::cout << "Asigned form :" << too_high_form << std::endl;

	print_title("Test Nr 7:Sign with correct grade", RED, BLUE);
	too_low_form.BeSigned(mid_oper);

	print_title("Test Nr 8:Sign with incorrect grade", RED, BLUE);
	too_high_form.BeSigned(mid_oper);

	print_title("Test Nr 9:Exec with correct grade", RED, BLUE);
	too_low_form.BeExec(mid_oper);

	print_title("Test Nr 10:Not signed execution ", RED, BLUE);
	too_high_form.BeExec(mid_oper);

	print_title("Test Nr 11:Exec with incorrect grade", RED, BLUE);
	too_high_form.BeSigned(oper3);
	too_high_form.BeExec(mid_oper);

	print_title("Finish tests", RED, BLUE);
	delete oper2;
	delete spec_form;
}
