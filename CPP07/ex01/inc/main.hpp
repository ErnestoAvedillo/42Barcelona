/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:03:06 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/16 17:41:52 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP
# include "../inc/colors.h"
# include <iostream>

template <typename T, typename F>
void iter(T *arr, size_t n, F ptr)
{
	if (arr != NULL)
	{
		for (size_t i = 0; i < n; i++)
		{
			ptr(arr[i]);
		}
	}
}

template <typename T>
void iter(T *arr, size_t n, void (*ptr)(T &))
{
	if (arr != NULL)
	{
		for (size_t i = 0; i < n; i++)
		{
			ptr(arr[i]);
		}
	}
}

template <typename T>
void imp_val_temp (T valor1)
{
	std::cout << "el valor es:" << valor1 << std::endl;
}

template <typename T, size_t N>
size_t arr_len ( T (&) [N])
{
	return (N);
}

template <typename T, size_t N>
void all_in_one(T (&valores)[N])
{
	std::cout << MGENTA "ahora llamo a la iter y a la funcion imprimir desde un template." RESET << std::endl;
	iter<T>(valores, N, &imp_val_temp);
}

#endif
