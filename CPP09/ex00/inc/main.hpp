/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:50 by marvin            #+#    #+#             */
/*   Updated: 2024/03/10 12:55:15 by eavedill         ###   ########.fr       */
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
#define DATA_CSV "./data.csv"
#include "../inc/BitcoinExchange.hpp"

bool checkdate(int m, int d, int y);
bool checkFormatDate(std::string const &str);
int extractYear(std::string const & str);
int extractMonth(std::string const & str);
int extractDay(std::string const & str);
int count_chr(std::string str, char c);
float getValue(std::string str);

#endif
