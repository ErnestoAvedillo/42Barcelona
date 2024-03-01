/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:31:03 by marvin            #+#    #+#             */
/*   Updated: 2024/03/01 07:31:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int operate(int val, int val1, char op)
{
    int out = 0;
    switch (op)
    {
    case '+':
        out = val + val1;
        break;
    case '-':
        out = val - val1;
        break;
    case '*':
        out = val * val1;
        break;
    case '/':
        try
        {
            out = val / val1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            throw std::runtime_error(e.what());
        }
        break;
    default:
        throw std::runtime_error ("operand not supported.");
        break;
    }
    return out;
}