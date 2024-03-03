/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:30:20 by marvin            #+#    #+#             */
/*   Updated: 2024/03/02 14:03:21 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

/// @brief Convert string to integer
/// @param str as std::string
/// @return integer 
int convert (std::string str)
{
    std::stringstream ss;
    int out = 0;
    if (str.find_first_not_of("0123456789") != std::string::npos)
        throw std::runtime_error ("Incorrect syntaxis.");
    ss << str;
    ss >> out;
    return out;
}
