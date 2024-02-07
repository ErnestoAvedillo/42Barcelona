/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:13:56 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/07 10:47:26 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

void imp_val (int valor1)
{
	std::cout << "el valor es:" << valor1 << std::endl;
}

int main(void)
{

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