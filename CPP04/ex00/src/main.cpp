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
int main(void)
{
	{
		std::cout << RED "*************** Creo Animal ****************" RESET << std::endl;
		const Animal* meta = new Animal();
		std::cout << RED "*************** Creo Perro ****************" RESET << std::endl;
		const Animal* j = new Dog();
		std::cout << RED "*************** Creo Gato ****************" RESET << std::endl;
		const Animal* i = new Cat();
		std::cout << RED "*************** Prueba de asignacion ****************" RESET << std::endl;
		Cat h ("Bengali");
		Cat k; 
		k = h;
		std::string nombre = "Persa";

		std::cout << RED "*************** Prueba de cambio de nombre ****************" RESET << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << RED "*************** Prueba de cambio de nombre ****************" RESET << std::endl;
		std::cout << h.getType() << ">>h " << std::endl;
		std::cout << k.getType() << ">>k " << std::endl;
		std::cout << "Tras cambio " << std::endl;
		k.setType(nombre);
		std::cout << h.getType() << ">>h " << std::endl;
		std::cout << k.getType() << ">>k " << std::endl;
		std::cout << "************** otras pruebas *****************************" << std::endl;

		std::cout << i->getType() << " ";
		i->makeSound(); //will output the cat sound!
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		std::cout << k.getType() << " " << std::endl;
		k.makeSound();
		std::cout << h.getType() << " " << std::endl;
		h.makeSound();
		std::cout << meta->getType() << " " << std::endl;
		meta->makeSound();
		std::cout << "************** delete meta *****************************" << std::endl;
		delete meta;
		std::cout << "************** delete j *****************************" << std::endl;
		delete j;
		std::cout << "************** delete i *****************************" << std::endl;
		delete i;
	}
	{
		std::cout << RED << "*************Prueba Wrong ***********" << RESET << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongDog();
		const WrongAnimal* i = new WrongCat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the Animal sound!
		j->makeSound(); //will output the Animal sound!
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		return 0;
	}
}
