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

#include  "main.h"


void print_info (void)
{
	std::cout << "Entrada incorrecta." << std::endl;
	std::cout << "Introduzca 3 parámetros." << std::endl;
	std::cout << "1- Nombre del fichero." << std::endl;
	std::cout << "2- String a reemplazar."<< std::endl;
	std::cout << "2- String de reemplazo."<< std::endl;
}

int main(int av, char **ac)
{
	if (av < 4)
	{
		print_info();
		return 0;
	}
	std::ofstream file_to_copy(ac[1]);
	if(!file_to_copy)
	{
		std::cout << "File " << ac[1] << " does not exist." << std::endl;
		return ( EXIT_FAILURE );
	}
	

	return 0;
}
