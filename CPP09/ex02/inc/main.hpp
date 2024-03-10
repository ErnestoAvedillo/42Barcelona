/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:35:32 by marvin            #+#    #+#             */
/*   Updated: 2024/03/10 16:05:02 by eavedill         ###   ########.fr       */
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
#include <ratio>
#include <chrono>

int convert (std::string str);

template <typename T>
bool compare(T val1, T val2)
{
	if (val1 < val2)
		return true;
	return false;
}

#endif
