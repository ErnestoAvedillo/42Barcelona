/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:50 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 09:48:03 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "../inc/colors.h"
#include "../inc/BitcoinExchange.hpp"
#include "../inc/Import.hpp"

#define DATA_CSV "./data.csv"

bool		checkdate(int m, int d, int y);
bool		checkFormatDate(std::string const &str);
int			extractYear(std::string const & str);
int			extractMonth(std::string const & str);
int			extractDay(std::string const & str);
int			count_chr(std::string str, char c);
float		getValue(std::string str);
std::string	all_trim(std::string str);

#endif
