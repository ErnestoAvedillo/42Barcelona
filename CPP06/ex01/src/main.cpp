/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:53:28 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/14 22:13:53 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
# include "../inc/colors.h"

int main(void)
{
	Data ptr;
	int n = 55;
	ptr.c = n;
	ptr.i = n;
	ptr.ptr = &n;
	std::cout << GREEN "Valores de struc entrada: " RESET << std::endl;
	std::cout << "Valor de ptr->c= " << ptr.c << std::endl;
	std::cout << "Valor de ptr->i= " << ptr.i << std::endl;
	std::cout << "Valor de ptr->ptr= " << ptr.ptr << std::endl;
	intptr_t ptr2;
	ptr2 = Serializer::serialize(&ptr);
	Data *nuevo = Serializer::deserialize(ptr2);
	std::cout << BLUE "Valores de struc salida: " RESET << std::endl;
	std::cout << "Valor de ptr->c= " << nuevo->c << std::endl;
	std::cout << "Valor de ptr->i= " << nuevo->i << std::endl;
	std::cout << "Valor de ptr->ptr= " << nuevo->ptr << std::endl;
}
