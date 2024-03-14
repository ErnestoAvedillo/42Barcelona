/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:33 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 10:29:53 by eavedill         ###   ########.fr       */
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
	ImportData input(ac[1], '|');
	input.printList(DataBase);
}
