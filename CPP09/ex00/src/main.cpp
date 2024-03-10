/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:33 by marvin            #+#    #+#             */
/*   Updated: 2024/03/10 12:30:58 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int main (int av, char **ac)
{
	if (av < 2)
		return 0;
	std::ifstream fData;
	std::ifstream fIn ;
	std::string line;
	std::string datafile = DATA_CSV;

	BitcoinExchange DataBase(datafile, ',');
	BitcoinExchange input(ac[1], '|');
	float value;
	std::cout << "Datos de entrada de input:" << std::endl;
	std::map<std::string, float>::iterator i = input.getBegin();
	Date la_fecha;
	while (i != input.getEnd())
	{
		try
		{
			la_fecha.putDate(input.getDate(i));
			value = DataBase.find_acc_note(i->first);
			if (input.getVal(i) == std::numeric_limits<float>::quiet_NaN() || input.getVal(i)  > 1000 )
				std::cout << "Fecha: " << i->first << "-->" << "Incorrect ammount " << std::endl;
			else	
				std::cout << "Fecha: " << i->first << "-->" << input.getVal(i) *  value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		i++;
	}
}
