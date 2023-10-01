/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:27:03 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/26 21:27:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc/main.h"

int main(void)
{
	Harl			my_harl;
	std::cout << BLUE << "Mensaje para Debug:" << RESET << std::endl;
	my_harl.complain("debug");
	std::cout << BLUE << "Mensaje para info:" << RESET << std::endl;
	my_harl.complain("info");
	std::cout << BLUE << "Mensaje para warning:" << RESET << std::endl;
	my_harl.complain("warning");
	std::cout << BLUE << "Mensaje para error:" << RESET << std::endl;
	my_harl.complain("error");
	return 0;
}
