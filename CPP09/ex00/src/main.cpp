/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:33 by marvin            #+#    #+#             */
/*   Updated: 2024/03/01 07:31:33 by marvin           ###   ########.fr       */
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


	BtcData DataBase(DATA_CSV,',');
	BtcData input(ac[1], '|');
	float value;
	std::cout << "Datos de entrada de input:" << std::endl;
	std::vector<t_btc>::iterator l = input.getEnd();
	for (std::vector<t_btc>::iterator i = input.getBegin(); i < l; i ++)
		try
		{
			value = DataBase.find_acc_note(input.getDate(i - input.getBegin()));
			if (input.getVal(i- input.getBegin()) == std::numeric_limits<float>::quiet_NaN() || input.getVal(i- input.getBegin())  > 1000 )
				std::cout << "Fecha: " << input.getDate(i - input.getBegin()).getDate() << "-->" << "Incorrect ammount " << std::endl;
			else	
				std::cout << "Fecha: " << input.getDate(i - input.getBegin()).getDate() << "-->" << input.getVal(i- input.getBegin()) *  value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

/*	while (std::getline(fData, line))
	{
		std::cout << "paso " << line << std::endl;
	}
	fIn.open(ac[1], std::ios::in);
	if (!fIn)
		std::cout << "File " << ac[1] <<" couldn't be opened" << std::endl;
	while (std::getline(fIn, line))
	{
		std::cout << line << std::endl;
	}*/
}
