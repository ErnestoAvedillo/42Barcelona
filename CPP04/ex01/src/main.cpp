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
		std::cout << "*********Create Animal class array************" << std::endl;

		Animal *meta[MAX_ANIMALS];

		std::cout << "*********Assign Dog class to animal class ptr************" << std::endl;

		for (int i = 0; i <= MAX_ANIMALS / 2 - 1; i++)
		{
			meta[i] = new Dog("Dog");
		}

		std::cout << "*********Assign Cat class to animal class ptr************" << std::endl;

		for (int i = MAX_ANIMALS / 2; i <= MAX_ANIMALS - 1; i++)
		{
			meta[i] = new Cat("Cat");
		}

		std::cout << "*********Printing all 100 Dog ideas ************" << std::endl;

		for (int i = 0; i <= MAX_ANIMALS / 2 - 1; i++)
		{
			Dog *ptrDog = dynamic_cast <Dog*> (meta[i]);
			ptrDog->prtIdeas();
		}

		std::cout << "*********Printing all 100 Cat ideas ************" << std::endl;
		for (int i = MAX_ANIMALS / 2; i <= MAX_ANIMALS - 1; i++)
		{
			Cat *ptrCat = dynamic_cast <Cat*> (meta[i]);
			ptrCat->prtIdeas();
		}

		std::cout << "*********Printing sounds of animals ************" << std::endl;
		for (int i = 0; i <= MAX_ANIMALS - 1; i++)
		{
			std::cout << meta[i]->getType() << "." << std::endl;
			meta[i]->makeSound();
		}

		std::cout << "*********Test Dog constructor with class of animals ************" << std::endl;
		Dog dog1("mi perrito faldero");
		dog1.prtIdeas();
		dog1.makeSound();
		Dog dog2(dog1);
		dog2.prtIdeas();
		dog2.makeSound();

		std::cout << "*********Test Cat constructor with class of animals ************" << std::endl;
		Cat cat1("mi gatito faldero");
		cat1.prtIdeas();
		cat1.makeSound();
		Cat cat2(cat1);
		cat2.prtIdeas();
		cat2.makeSound();

		std::cout << "*********Deleting all animals ************" << std::endl;
		for (int i = 0; i <= MAX_ANIMALS - 1; i++)
		{
			delete meta[i];
		}
		std::cout << "*********test finalyzed************" << std::endl;
	}
}
