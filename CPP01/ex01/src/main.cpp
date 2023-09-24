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

# include "../inc/main.hpp"
# include <stdlib.h>
int main (int av, char **ac)
{
	int N;
	int j;

	if (av < 2)
		return 0;
	
	N = atoi (ac[1]);
	Zombie *hordeZon = zombieHorde(N, "Pepito");
	j = -1;
	while(++j<N)
	{
		std::cout << "Recibida la variable mizombie llamado: " << hordeZon[j].getname() << std::endl;
	}
	delete []hordeZon;
	return 0;
}
