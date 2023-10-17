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

bool test_ataque(ClapTrap &clap1, ClapTrap &clap2)
{
	bool yes_he_can = clap1.CanActuate();
	clap1.attack(clap2.GetName());
	if(yes_he_can)
		clap2.takeDamage(clap1.GetDamage());
	return yes_he_can;
}

bool test_repare(ClapTrap &clap1, int amount)
{
	bool yes_he_can = clap1.CanActuate();
	clap1.beRepaired(amount);
	return yes_he_can;
}

void test_war (ClapTrap &clap1, ClapTrap &clap2, int nr_atacks)
{
	for (int i = 0; i < nr_atacks; i++)
	{
		test_ataque(clap1, clap2);
		test_ataque(clap2, clap1);
	}
}

int main(void)
{
	ClapTrap pepito("Pepito");
	ScavTrap zutanito("Scav_Zutanito");
	FragTrap menganito("Frag_menganito");
	ScavTrap anonimo;
	zutanito.SetDamage(2);
	pepito.SetDamage(3);

	test_war(pepito, zutanito, 5);
	test_war(anonimo, zutanito, 10);
	test_war(anonimo, menganito, 10);
	test_repare(zutanito, 10);

	test_ataque(pepito, zutanito);
	test_ataque(zutanito, anonimo);
	zutanito.SetDamage(12);
	test_ataque(anonimo, zutanito);
	test_ataque(zutanito, pepito);
	test_ataque(pepito,anonimo);
	zutanito.beRepaired(5);
	pepito.beRepaired(10);
	anonimo.beRepaired(20);
	zutanito.VewStatus();
	pepito.VewStatus();
	anonimo.VewStatus();
	menganito.highFivesGuys();
	return 0;
}
