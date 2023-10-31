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
			Cat *ptrDog = dynamic_cast <Cat*> (meta[i]);
			ptrDog->prtIdeas();
		}

		std::cout << "*********Printing all 100 Dog ideas ************" << std::endl;
		for (int i = 0; i <= MAX_ANIMALS - 1; i++)
		{
			std::cout << meta[i]->getType() << "." << std::endl;
			meta[i]->makeSound();
		}
		for (int i = 0; i <= MAX_ANIMALS - 1; i++)
		{
			delete meta[i];
		}
		std::cout << "*********test finalyzed************" << std::endl;
	}
}
