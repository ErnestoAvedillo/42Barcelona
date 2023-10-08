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

int main( void ) 
{
	ClapTrap pepito("Pepito");
	ClapTrap manolito("Manolito");
	ClapTrap anonimo;

	pepito.attack("manolito");
	manolito.takeDamage(1);
	manolito.beRepaired(1);
	pepito.attack("manolito");
	manolito.takeDamage(12);
	pepito.attack("manolito");
	manolito.takeDamage(2);
	return 0;
}