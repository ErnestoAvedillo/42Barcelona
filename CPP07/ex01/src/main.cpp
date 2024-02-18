/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:13:56 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/17 16:43:04 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

void imp_val (int valor1)
{
	std::cout << "el valor es:" << valor1 << std::endl;
}

int main(void)
{
{
	int	intArray[5] = {42, 41, 40, 39, 38};
	std::string	stringArray[5] = {"42", "zpalfi", "cpp07", "hola", "adios"};
	float	floatArray[3] = {42.42, 69.69, 42.69};

	std::cout << "Result of iter the int array:" << std::endl;
	::iter<int>(intArray, 5, ::imp_val_temp);

	std::cout << std::endl << std::endl << "Result of iter the string array" << std::endl;
	::iter<std::string>(stringArray, 5, ::imp_val_temp);

	std::cout<< std::endl << std::endl << "Result of iter the float array" << std::endl;
	::iter<float>(floatArray, 3, ::imp_val_temp);
	std::cout << std::endl;
}
{
	std::string strings[] = {"rergg", "fe;vncn", "3489yr3984hruire", "qfqlbfbql904", "elkb832ijk", "wwmmwwmmbuu:w"};
	std::cout << GREEN "Usando una funcion estandard con strings" RESET << std::endl;
	iter(strings, 6, imp_val_temp);
	int valores[] = {90, -4, 86, 75, 54, 33};
	std::cout << GREEN "Usando una funcion estandard" RESET << std::endl;
	iter(valores, 6, imp_val);
	std::cout << GREEN "Usando una funcion template" RESET << std::endl;
	iter(valores, 6, imp_val_temp);
	std::cout << CYAN "Usando una funcion template con doubles" RESET << std::endl;
	double valdoub[] = {20.35, -4.5, 86.01, 75.55, 54.99, 33.75};
	iter(valdoub, 6, imp_val_temp);
	all_in_one(valores);
	all_in_one(valdoub);
}
}
