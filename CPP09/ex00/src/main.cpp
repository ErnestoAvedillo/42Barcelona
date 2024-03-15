/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:33 by marvin            #+#    #+#             */
/*   Updated: 2024/03/15 08:28:09 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int main (int av, char **ac)
{
	if (av < 2)
	{
		std::cerr << "At least one parameter needed. ./btc <Name of the file>" << std::endl;
		return 0;
	}
	std::ifstream fData;
	std::ifstream fIn ;
	std::string line;
	std::string datafile = DATA_CSV;
	try
	{
		BitcoinExchange DataBase(datafile, ',');
		ImportData input(ac[1], '|');
		input.printList(DataBase);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
