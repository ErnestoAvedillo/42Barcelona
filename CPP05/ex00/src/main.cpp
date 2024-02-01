/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/01 11:48:11 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/main.h"


int main(void)
{
	std::cout << GREEN "**********Test Nr1.:default creator" RESET << std::endl;
	Bureaucrat oper1;
	std::cout << "Default Bureaucrat created " << oper1 << std::endl;
	std::cout << GREEN "**********Test Nr2.:copy creator" RESET << std::endl;
	Bureaucrat *oper2 = new Bureaucrat(oper1);
	std::cout << "Bureaucrat new created " << *oper2 << std::endl;
	std::cout << GREEN "**********Test Nr3.:asignation operation" RESET << std::endl;
	Bureaucrat mid_oper("mid_oper", 75);
	std::cout << "Created: " << mid_oper;
	*oper2 = mid_oper;
	std::cout << "Asigned midoper to oper2: now oper2 is" << *oper2 << std::endl;
	std::cout << RED "**********Test Nr4.:Too high grade creation" RESET << std::endl;
	Bureaucrat oper3("Too much grade", 0);
	std::cout << BLUE << oper3 << RESET << std::endl;
	std::cout << RED "**********Test Nr5.:Too low grade creation" RESET << std::endl;
	Bureaucrat oper4("Too low grade", 151);
	std::cout << BLUE << oper4 << RESET << std::endl;
	std::cout << RED "**********Test Nr6.: Increment grade over limit" RESET << std::endl;
	oper3.IncGrade();
	std::cout << BLUE << oper3 << RESET << std::endl;
	std::cout << RED "**********Test Nr7.: Decrement grade over limit" RESET << std::endl;
	oper4.DecGrade();
	std::cout << BLUE << oper4 << RESET << std::endl;
	delete oper2;
}
