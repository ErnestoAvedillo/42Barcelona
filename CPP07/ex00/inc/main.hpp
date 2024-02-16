/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:03:06 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/16 17:38:16 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP
# include "../inc/colors.h"
# include <iostream>

template <typename T> 
void swap (T &val1, T &val2)
{
	T aux;
	aux = val1;
	val1= val2;
	val2 = aux;
}

template <typename T> 
T min (T val1, T val2)
{
	if(val1 < val2)
		return val1;
	return val2;
}

template <typename T>
T max(T val1, T val2)
{
	if (val1 > val2)
		return val1;
	return val2;
}

#endif
