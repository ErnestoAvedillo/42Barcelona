/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/09 13:01:10 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/main.h"
#include <iostream>
#include <iomanip>
#include "../inc/ClapTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"
#include "../inc/ScavTrap.hpp"

#define FILL 40

void attacking(ClapTrap &clap1, ClapTrap &clap2)
{
	bool canAttack;

	canAttack = clap1.getEPts() < 1 ? false : true;
	clap1.attack(clap2.getName());
	if (canAttack == true)
		clap2.takeDamage(clap1.getADmg());
}

void war(ClapTrap &one, ClapTrap &two, int times)
{
	for (int i = 0; i < times; i++)
	{
		attacking(one, two);
		attacking(two, one);
	}
}

void test(ClapTrap &one, ClapTrap &two, bool change_dmg)
{
	war(one, two, 1);
	if (change_dmg == true)
		one.setADmg(1);
	attacking(one, two);
	if (change_dmg == true)
		two.setADmg(1);
	attacking(two, one);
	if (change_dmg == true)
		one.setADmg(8);
	attacking(one, two);
	if (change_dmg == true)
		two.setADmg(6);
	std::cout << std::endl;
	one.beRepaired(one.getADmg() * 10);
	two.beRepaired(one.getADmg() * 10);
	std::cout << std::endl;
	attacking(two, one);
	war(one, two, 1);
	if (change_dmg == true)
	{
		one.setADmg(1);
		two.setADmg(1);
	}
	war(one, two, 6);
	std::cout << "\none -> " << one << std::endl;
	std::cout << "two -> " << two << std::endl;
}

void print_next_test(std::string msg)
{
	int fill;
	int odd;

	fill = (FILL - msg.length()) / 2;
	odd = msg.length() % 2;
	std::cout << "\n " << std::setfill('_') << std::setw(FILL - 1) << "" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(fill + odd) << "" << msg << std::setw(fill) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
	std::cout << "|" << std::setfill('_') << std::setw(FILL + 1) << "|\n"
			  << std::endl;
}

void test_clap(void)
{
	ClapTrap clap1("clap1");
	ClapTrap clap2(clap1);

	clap2.setName("clap2");
	std::cout << "\none -> " << clap1 << std::endl;
	std::cout << "two -> " << clap2 << "\n"
			  << std::endl;
	test(clap1, clap2, true);
	std::cout << std::endl;
}

void test_scav(void)
{
	ScavTrap scav1;
	ScavTrap scav2("scav2");

	scav1 = scav2;
	scav1.setName("scav1");
	std::cout << "\none -> " << scav1 << std::endl;
	std::cout << "two -> " << scav2 << "\n"
			  << std::endl;
	test(scav1, scav2, false);
	std::cout << std::endl;
	scav1.guardGate();
	scav2.guardGate();
	std::cout << std::endl;
}

void test_frag(void)
{
	FragTrap frag1("frag1");
	FragTrap frag2;

	frag2 = frag1;
	frag2.setName("frag2");
	std::cout << "\none -> " << frag1 << std::endl;
	std::cout << "two -> " << frag2 << "\n"
			  << std::endl;
	test(frag1, frag2, false);
	std::cout << std::endl;
	frag1.highFivesGuys();
	frag2.highFivesGuys();
	std::cout << std::endl;
}

void test_diamond(void)
{
	DiamondTrap diamond1("diamond1");
	DiamondTrap diamond2("diamond2");

	std::cout << "\none -> " << diamond1 << std::endl;
	std::cout << "two -> " << diamond2 << "\n"
			  << std::endl;
	test(diamond1, diamond2, false);
	std::cout << std::endl;
	diamond1.whoAmI();
	diamond2.whoAmI();
	std::cout << std::endl;
}

int main(void)
{
	print_next_test("ClapTrap test");
	test_clap();

	print_next_test("ScravTrap test");
	test_scav();

	print_next_test("FragTrap test");
	test_frag();

	print_next_test("DiamondTrap test");
	test_diamond();

	return (0);
}