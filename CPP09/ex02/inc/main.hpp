/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:35:32 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 13:06:36 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP
#include "../inc/PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <cmath>
#include <ctime>

int convert (std::string str);

template <typename T>
bool compare(T val1, T val2)
{
	if (val1 < val2)
		return true;
	return false;
}

#endif
