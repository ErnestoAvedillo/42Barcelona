/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:51:54 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/17 16:51:45 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"
#define MAX_VAL 750

int main(int, char**)
{
	Array<int> pepito;
	try
	{
		std::cout << "Test 1:Esto es una clase con array vacio " << pepito[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << GREEN "Test 2:Esto es una clase con array 18 " RESET << std::endl;

	Array<int> pepote(18);

	pepote[0] = 23;
	std::cout << "Esto es una claser con array con 18 valores " << std::endl;
	std::cout << "Valores de pepote ";
	pepote.print_all_val();
	try
	{
		std::cout << "El valor 23 =  " << pepote[23] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "El valor -3 =  " << pepote[-3] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Prueba de la función getsize " << pepote.GetSize() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << GREEN "Test 2:Esto es una prueba de asignacion del array anterior" RESET << std::endl;
	Array<int> copia_pepote(18);
	try
	{
		std::cout << "Esto es la clase copia_pepote con 18 valores antes de asignación " << std::endl;
		std::cout << "Valores de pepote " ;
		pepote.print_all_val();
		std::cout << "Valores de copia_pepote =  ";
		copia_pepote.print_all_val();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		copia_pepote = pepote;
		std::cout << "Esto es la clase copia_pepote con 18 valores tras la asignación " << std::endl;
		std::cout << "Valores de pepote       = ";
		pepote.print_all_val();
		std::cout << "Valores de copia_pepote = ";
		copia_pepote.print_all_val();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << GREEN "Test 3:Esto es una prueba de asignacion de diferentes dimensiones array anterior" RESET << std::endl;

	Array<int> copia2_pepote(30);
	try
	{
		std::cout << "Esto es la clase copia_pepote con 30 valores antes de asignación " << std::endl;
		std::cout << "Valores de copia2_pepote = ";
		copia2_pepote.print_all_val();
		copia2_pepote = pepote;
		std::cout << "Esto es la clase copia_pepote con 18 valores antes de asignación " << std::endl;
		std::cout << "Valores de copia2_pepote = ";
		copia2_pepote.print_all_val();
		std::cout << "Valores de pepote        = ";
		pepote.print_all_val();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << GREEN "Test 4:Esto es una prueba de constructor de copia" RESET << std::endl;
	Array<int> copia3_pepote(pepote);
	try
	{
		std::cout << "Esto es la clase copia3_pepote " << std::endl;
		std::cout << "Valores de pepote        = ";
		pepote.print_all_val();
		std::cout << "Valores de copia3_pepote = ";
		copia_pepote.print_all_val();
		std::cout << "Cambio un valor de la clase copia3_pepote " << std::endl;
		copia3_pepote[10] = 45;
		std::cout << "Valores de pepote        = ";
		pepote.print_all_val();
		std::cout << "Valores de copia3_pepote = ";
		copia3_pepote.print_all_val();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << GREEN "Test 5:Esto es una prueba con valores double" RESET << std::endl;
	Array<double> doble_pepote(23);
	try
	{
		doble_pepote[20] = 2.358f;
		std::cout << "Esto es la clase doble_pepote " << std::endl;
		std::cout << "Valores de pepote        = ";
		doble_pepote.print_all_val();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << GREEN "Test 6:Constructor de copia de un array vacio" RESET << std::endl;
	Array<int> copia4_pepote(pepito);
	std::cout << "Esto es la clase copia4_pepote " << std::endl;
	std::cout << "Valores de pepote        = ";
	copia4_pepote.print_all_val();

	std::cout << GREEN "Test 7:Asignacion de un array vacio" RESET << std::endl;
	std::cout << "Esto es la clase copia3_pepote antes de la asignación " << std::endl;
	std::cout << "Valores de copia3_pepote        = ";
	copia3_pepote.print_all_val();
	copia3_pepote = pepito;
	std::cout << "Esto es la clase copia3_pepote tras la asignación " << std::endl;
	std::cout << "Valores de copia3_pepote        = ";
	copia3_pepote.print_all_val();
}
