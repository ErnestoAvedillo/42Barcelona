/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:21:55 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/06 19:56:32 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

Base *generate()
{
	srand((unsigned int)time((time_t *)NULL));
	int c = rand() % 3;
	switch (c)
	{
		case 0:
		{
			std::cout << "Created class A" << std::endl;
			return (new A);
		}
		case 1:
		{
			std::cout << "Created class B" << std::endl;
			return (new B);
		}
		case 2:
		{
			std::cout << "Created class C" << std::endl;
			return (new C);
		}
		default:
			std::cout << "Created class A_" << std::endl;
			return (new A);
		}
}

void identify (Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Class is A" << std::endl;
	if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Class is B" << std::endl;
	if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Class is C" << std::endl;
}

void identify (Base &p)
{
	try
	{
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "Class is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "while tying to " << std::endl;
	}
		try
	{
	if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "Class is B" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "while tying to " << std::endl;
	}
		try
	{
	if (dynamic_cast<C *>(&p) != NULL)
		std::cout << "Class is C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "while tying to " << std::endl;
	}
//	if (dynamic_cast<B *>(&p) != NULL)
//		std::cout << "Class is B" << std::endl;
//	if (dynamic_cast<C *>(&p) != NULL)
//		std::cout << "Class is C" << std::endl;
}

int main (void)
{
	Base *ptr;
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}