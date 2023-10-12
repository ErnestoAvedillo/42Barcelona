/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:23:08 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/21 22:23:12 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/main.h"

bool is_integer(char *s)
{
	if (s[0] == '\0')
		return false;
	for (int i = 0; s[i] != 0; i++)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

int main (int av, char **ac)
{
	int N;
	int i;
	Zombie *hordeZon;

	if (av < 3)
		return 0;
	if (is_integer(ac[1])) 
        N = std::stoi(ac[1]);
	else
		return 0;
	hordeZon = zombieHorde(N, ac[2]);
	for(i=0; i < N; ++i)
	{
		std::cout << "Recibida la variable mizombie Nr-"<< i << " llamado:  " << hordeZon[i].getname() << std::endl;
		hordeZon[i].announce();

	}
	delete []hordeZon;
	return 0;
}
