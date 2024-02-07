/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:13:56 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/07 07:53:58 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int main(void)
{
	std::cout << BLUE "Test1 con int" RESET << std::endl;
	int int1 = 10;
	int int2 = 12;
	std::cout << "valor 1 = " << int1 << "; valor2 = " << int2 << std::endl;
	std::cout << " funcion máximo :" << max(int1, int2);
	std::cout << " funcion mínimo :" << min(int1, int2) << std::endl;
	swap(int1, int2);
	std::cout << "valor 1 = " << int1 << "; valor2 = " << int2 << std::endl;
	std::cout << " funcion máximo :" << max(int1, int2);
	std::cout << " funcion mínimo :" << min(int1, int2) << std::endl;
	std::cout << GREEN "Test2 con char" RESET << std::endl;
	char char1 = 'a';
	char char2 = 'h';
	std::cout << "char 1 = " << char1 << "; char2 = " << char2 << std::endl;
	std::cout << " funcion máximo :" << max(char1, char2);
	std::cout << " funcion mínimo :" << min(char1, char2) << std::endl;
	swap(char1, char2);
	std::cout << "char 1 = " << char1 << "; char2 = " << char2 << std::endl;
	std::cout << " funcion máximo :" << max(char1, char2);
	std::cout << " funcion mínimo :" << min(char1, char2) << std::endl;
	std::cout << MGENTA "Test3 con double" RESET << std::endl;
	double dob1 = 2.34;
	double dob2 = 7.88;
	std::cout << "valor 1 = " << dob1 << "; valor = " << dob2 << std::endl;
	std::cout << " funcion máximo :" << max(dob1, dob2);
	std::cout << " funcion mínimo :" << min(dob1, dob2) << std::endl;
	swap(dob1, dob2);
	std::cout << "valor 1 = " << dob1 << "; valor = " << dob2 << std::endl;
	std::cout << " funcion máximo :" << max(dob1, dob2);
	std::cout << " funcion mínimo :" << min(dob1, dob2) << std::endl;
	std::cout << YELLOW "Test4 con float" RESET << std::endl;
	double flo1 = 0.23554f;
	double flo2 = 89.2344f;
	std::cout << "valor 1 = " << flo1 << "; valor = " << flo2 << std::endl;
	std::cout << " funcion máximo :" << max(flo1, flo2);
	std::cout << " funcion mínimo :" << min(flo1, flo2) << std::endl;
	swap(flo1, flo2);
	std::cout << "valor 1 = " << flo1 << "; valor = " << flo2 << std::endl;
	std::cout << " funcion máximo :" << max(flo1, flo2);
	std::cout << " funcion mínimo :" << min(flo1, flo2) << std::endl;
}