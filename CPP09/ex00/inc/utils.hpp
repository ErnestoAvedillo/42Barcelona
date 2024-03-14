/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:50 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 09:44:28 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include "../inc/colors.h"

bool		checkdate(int m, int d, int y);
bool		checkFormatDate(std::string const &str);
int			extractYear(std::string const & str);
int			extractMonth(std::string const & str);
int			extractDay(std::string const & str);
int			count_chr(std::string str, char c);
float		getValue(std::string str);
std::string	all_trim(std::string str);

#endif
