/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:35:32 by marvin            #+#    #+#             */
/*   Updated: 2024/03/03 18:03:28 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP
#include "../inc/PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <sstream>
#include <cmath>

int convert (std::string str);

template <typename T>
bool compare(T val1, T val2)
{
	if (val1 < val2)
		return true;
	return false;
}

#endif
