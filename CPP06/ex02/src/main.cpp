/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:21:55 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/16 16:35:02 by eavedill         ###   ########.fr       */
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
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "Class is A" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "Class is B" << std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "Class is C" << std::endl;
	}
	catch(const std::exception& e)
	{}
}

int main (void)
{
	Base *ptr;
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}
