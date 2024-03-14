/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:46:52 by eavedill          #+#    #+#             */
/*   Updated: 2024/03/14 12:14:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>

int convert(std::string str)
{
	std::stringstream ss;
	int out = 0;
	if (str.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Incorrect syntaxis.");
	ss << str;
	ss >> out;
	if (out >= 10)
		throw std::runtime_error("Values must allways be less than 10.");
	return out;
}

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
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			throw std::runtime_error(e.what());
		}
		break;
	default:
		throw std::runtime_error("operand not supported.");
		break;
	}
	return out;
}

void check_operator(std::string str, std::stack<int> my_oper)
{
	if (str.length() > 1)
		throw std::runtime_error("Incorrect operator.");
	if (my_oper.size() < 2)
		throw std::runtime_error("Incorrect syntaxis. Empty stack.");
}
