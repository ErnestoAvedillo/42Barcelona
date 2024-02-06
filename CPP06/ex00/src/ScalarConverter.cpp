/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:08:19 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/06 13:44:10 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

static bool check_inf(std::string s)
{
	std::string const infstrs[] = INF_TYPE;
	for (size_t i = 0; i < array_size(infstrs); i++)
	{
		if (infstrs[i] == s)
			return true;
	}
	return false;
}

static bool check_min_inf(std::string s)
{
	std::string const infstrs[] = INF_MINUS_TYPE;
	for (size_t i = 0; i < array_size(infstrs); i++)
	{
		if (infstrs[i] == s)
			return true;
	}
	return false;
}

static bool check_nan(std::string s)
{
	std::string const infstrs[] = NAN_TYPE;
	for (size_t i = 0; i < array_size(infstrs); i++)
	{
		if (infstrs[i] == s)
			return true;
	}
	return false;
}

static int get_num_dec(float d)
{
	int i = 1;
	float f = powf(10, i);
	
	while (modff(d * f, &f) != 0)
	{
		i++;
		f = pow(10, i);
	}
	if (i == 0) 
		i++;
	return i;
}

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if(this == &rhs)
		return *this;
	/*nothing to copy*/
	return *this;
}

void	ScalarConverter::convert(std::string to_convert)
{

	this->ToChar(to_convert);
	this->ToInt(to_convert);
	this->ToFloat(to_convert);
	this->ToDouble(to_convert);
}
void	ScalarConverter::ToChar(std::string to_convert)
{
	int i;
	try
	{
		i = std::stoi(to_convert);
		if (i > MAX_CHAR || i < MIN_CHAR)
			std::cout << "Income: " << to_convert << " is not valid to be converted to char." << std::endl;
		else if (i > MAX_CHAR_PRINT || i < MIN_CHAR_PRINT)
			std::cout << "Income: " << to_convert << " is a non displayable charachter." << std::endl;
		else
			std::cout << "Income: " << to_convert << " converted to :" << char(i) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Income: " << to_convert << "is not valid to be converted to char." << std::endl;
	}
}
void	ScalarConverter::ToInt(std::string to_convert)
{
	int i;
	try
	{
		i = std::stoi(to_convert);
		std::cout << "Income: " << to_convert << " converted to :" << i << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Income: " << to_convert << "is not valid to be converted to int." << std::endl;
	}
}

void	ScalarConverter::ToFloat(std::string to_convert)
{
	float f;
	int prec = 0;
	try
	{
		if (check_inf(to_convert))
			f = std::numeric_limits<float>::infinity();
		else if (check_min_inf(to_convert))
			f = -1 * std::numeric_limits<float>::infinity();
		else if (check_nan(to_convert))
			f = std::numeric_limits<float>::quiet_NaN();
		else
		{
			f = std::stof(to_convert);
			prec = get_num_dec(f);
		}
		std::cout << std::fixed << std::setprecision(prec);
		std::cout << "Income: " << to_convert << " converted to :" << f << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Income: " << to_convert << "is not valid to be converted to float." << std::endl;
	}
}
void	ScalarConverter::ToDouble(std::string to_convert)
{
	double d;
	int prec = 0;

	try
	{
		if (check_inf(to_convert))
			d = std::numeric_limits<double>::infinity();
		else if (check_min_inf(to_convert))
			d = -1 * std::numeric_limits<double>::infinity();
		else if (check_nan(to_convert))
			d = std::numeric_limits<double>::quiet_NaN();
		else
		{
			d = std::stod(to_convert);
			prec = get_num_dec(d);
		}
		std::cout << std::fixed << std::setprecision(prec);
		std::cout << "Income: " << to_convert << " converted to :" << d << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Income: " << to_convert << "is not valid to be converted to double." << std::endl;
	}
}