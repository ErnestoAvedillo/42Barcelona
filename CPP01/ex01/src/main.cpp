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
# include <stdlib.h>
int main (int av, char **ac)
{
	int N;
	int i;

	if (av < 2)
		return 0;
	
	N = atoi (ac[1]);
	Zombie *hordeZon = zombieHorde(N, "Pepito");
	for(i=0; i < N; ++i)
	{
		std::cout << "Recibida la variable mizombie llamado: Nr-"<< i << "  " << hordeZon[i].getname() << std::endl;
		hordeZon[i].announce();

	}
	delete []hordeZon;
	return 0;
}
