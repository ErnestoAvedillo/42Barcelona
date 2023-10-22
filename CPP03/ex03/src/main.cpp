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
	DiamondTrap chulito("Diam_chulito");
	DiamondTrap chulito2("Diam_chulito2");
	DiamondTrap anonimo;
	zutanito.SetDamage(2);
	pepito.SetDamage(3);

	test_war(pepito, zutanito, 5);
	test_war(anonimo, zutanito, 10);
	test_war(anonimo, menganito, 10);
	test_repare(zutanito, 10);
	test_repare(menganito, 10);
	test_repare(pepito, 10);
	test_war(menganito, chulito, 20);
	test_war(zutanito, chulito, 20);
	test_war(chulito, anonimo, 10);
	test_war(chulito, pepito, 2);
	test_war(chulito, zutanito, 10);
	test_war(chulito, menganito, 20);
	test_war(chulito2, chulito, 20);
	chulito.whoAmI();
	chulito.highFivesGuys();
	chulito.guardGate();
	zutanito.beRepaired(5);
	pepito.beRepaired(10);
	anonimo.beRepaired(20);
	chulito2.beRepaired(20);
	pepito.ViewStatus();
	zutanito.ViewStatus();
	menganito.ViewStatus();
	chulito.ViewStatus();
	chulito2.ViewStatus();
	menganito.highFivesGuys();
	zutanito.guardGate();
	zutanito.guardGate();
	pepito.ViewStatus();
	zutanito.ViewStatus();
	menganito.ViewStatus();
	chulito.ViewStatus();
	chulito2.ViewStatus();
	chulito.SetName("Diam_zorrito");
	menganito.SetHitPoints(100);
	menganito.SetEnergy(400);
	pepito.ViewStatus();
	zutanito.ViewStatus();
	menganito.ViewStatus();
	chulito.ViewStatus();
	chulito2.ViewStatus();
	return 0;
}
