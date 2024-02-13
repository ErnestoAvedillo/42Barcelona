/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:08:19 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/13 18:29:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

static int count_chr(std::string s, char c)
{
	int out;

	out = 0;
	for (size_t i = 0; i < s.size(); i++)
		if(s[i] == c)
			out++;
	return out;
}

static t_convert init_conv()
{
	t_convert out;
	out.type = 0;
	out.c = 0;
	out.i = 0;
	out.f = 0;
	out.d = 0;
	out.s = "";
	return out;
}

static t_convert check_is_valid(std::string s)
{
	t_convert out;
	std::stringstream ss;
	ss << s;
	out = init_conv();
	if (s.empty())
	{
		out.type = MAX_CONVERTS;
		return out;
	}
	if (s.size() == 1)
	{
		if(s.at(0) >= MIN_CHAR_PRINT && s.at(0) <= MAX_CHAR_PRINT)
		{
			out.type = IS_CHAR;
			out.c = s.at(0);
			return out;
		}
		else if (s.find_first_of("0123456789") == std::string::npos)
			out.type = MAX_CONVERTS;
		else
			out.type = IS_INT;
	}
	if (s.at(s.size() - 1) == 'f')
	{
		s.erase(s.size() - 1);
		ss >> out.f;
		out.type = IS_FLOAT;
	}
	if (s.find_first_not_of("-+0123456789.") != std::string::npos ||
		count_chr(s, '.') > 1 || count_chr(s, '-') > 1 || count_chr(s, '+') > 1)
		out.type = MAX_CONVERTS;
	if ((count_chr(s, '+') == 1 && s.at(0) != '+') || 
		(count_chr(s, '-') == 1 && s.at(0) != '-'))
		out.type = MAX_CONVERTS;
	if (!out.type)
	{
		if(s.find_first_of(".")  < s.size())
		{
			out.type = IS_DOUBLE;
			ss >> out.d;
		}
		else
		{
			out.type = IS_INT;
			ss >> out.i;
		}
	}
	return out;
	//	std::cout << "Resultado find first" << s.find_first_not_of("+-.0123456789") << "!!!" << std::endl;
}
static t_convert check_inf(std::string s)
{
	t_convert out;
	out = init_conv();
	std::string const infstrs[] = INF_TYPE;
	for (size_t i = 0; i < array_size(infstrs); i++)
	{
	//	std::cout << "Valores infinitos " << infstrs[i] << std::endl;
		if (infstrs[i] == s)
		{
			out.type = i + 2;
			if (i == 0)
			{
				out.type = IS_DOUBLE;
				out.f = std::numeric_limits<double>::infinity();
			}
			else if (i == 1)
			{
				out.type = IS_FLOAT;
				out.f = std::numeric_limits<float>::infinity();
			}
		}
	}
	return out;
}

static t_convert check_min_inf(std::string s)
{
	t_convert out;
	out = init_conv();
	std::string const infstrs[] = INF_MINUS_TYPE;
	for (size_t i = 0; i < array_size(infstrs); i++)
	{
	//	std::cout << "Valores infinitos " << infstrs[i] << std::endl;
		if (infstrs[i] == s)
		{
			if (i == 0)
			{
				out.type = IS_DOUBLE;
				out.f = -1 * std::numeric_limits<double>::infinity();
			}
			else if (i == 1)
			{
				out.type = IS_FLOAT;
				out.f = -1 * std::numeric_limits<float>::infinity();
			}
		}
	}
	return out;
}

static t_convert check_nan(std::string s)
{
	t_convert out;
	out = init_conv();
	std::string const infstrs[] = NAN_TYPE;
	for (size_t i = array_size(infstrs) - 1; i > 0; i--)
	{
		std::cout << "Valores infinitos " << infstrs[i] << std::endl;
		if (infstrs[i] == s)
		{
			if (i == 0)
			{
				out.type = IS_FLOAT;
				out.f = std::numeric_limits<float>::quiet_NaN();
			}
			else if (i == 1)
			{
				out.type = IS_DOUBLE;
				out.f = std::numeric_limits<double>::quiet_NaN();
			}
		}
	}
	return out;
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
	t_convert out;

	out = init_conv();
	Check_func check[] = {check_inf, check_min_inf, check_nan, check_is_valid};
	for (size_t i = 0; i < array_size(check); i++)
	{
		out = check[i](to_convert);
		if (out.type)
			break;
	}
	if (out.type == MAX_CONVERTS)
	{
		std::cout << "Income <" << to_convert << "> is an empty or not a valid string." << std::endl;
	}
	out.s = to_convert;
	Conv_funct conv_f[] = {isChar, isInt, isFloat, isDouble};
	for (int i = 1; i < MAX_CONVERTS; i++)
		if (out.type == i)
			conv_f[i - 1](out);
	return ;
}
void ScalarConverter::isChar(t_convert val)
{
	val.i = static_cast<int>(val.c);
	val.f = static_cast<float>(val.c);
	val.d = static_cast<double>(val.c);
	prtOut(val);
}

void ScalarConverter::isInt(t_convert val)
{
	val.c = static_cast<char>(val.i);
	val.f = static_cast<float>(val.i);
	val.d = static_cast<double>(val.i);
	prtOut(val);
}

void ScalarConverter::isFloat(t_convert val)
{
	val.c = static_cast<char>(val.f);
	val.i = static_cast<int>(val.f);
	val.d = static_cast<double>(val.f);
	prtOut(val);
}
void ScalarConverter::isDouble(t_convert val)
{
	val.c = static_cast<char>(val.d);
	val.i = static_cast<int>(val.d);
	val.f = static_cast<float>(val.d);
	prtOut(val);
}

void ScalarConverter::prtOut(t_convert val)
{
	int prec;

	prec = get_num_dec(val.d);
	/*print--char*/
	std::cout << "Income <" << val.s;
	if (val.c > MAX_CHAR_PRINT || val.c < MIN_CHAR_PRINT)
		std::cout << "> is a non displayable charachter." << std::endl;
	else
		std::cout << "> converted to char :" << val.c << std::endl;
	/*print--int*/
	//std::cout << "Income <" << val.s << "> converted to type int " << val.i << std::endl;
	std::cout << "Income <" << val.s;
	if (val.i > std::numeric_limits<int>::max())
		std::cout << "> is over the 64 bits integer limit." << std::endl;
	else if (val.i < std::numeric_limits<int>::min())
		std::cout << "> is under the 64 bits integer limit." << std::endl;
	else
		std::cout << "> converted to type int " << val.i << std::endl;
	/*print float & double*/
	std::cout << std::fixed << std::setprecision(prec);
	std::cout << "Income <" << val.s << "> converted to type float " << val.f << "f" << std::endl;
	std::cout << "Income <" << val.s << "> converted to type double " << val.d << std::endl;
}
/*
int i;
try
{
	i = static_cast<char>(number);
	}
	catch (const std::exception &e)
	{
		std::cerr << "is not valid to be converted to char." << std::endl;
	}
}

void ScalarConverter::isInt(t_convert number)
{
	int i;
	try
	{
		i = static_cast<int>(number);
	}
	catch (const std::exception &e)
	{
		std::cerr << "is not valid to be converted to int." << std::endl;
	}
}

void ScalarConverter::isFloat(t_convert number)
{
	float f;
	int prec = 0;
	try
	{
		if ((number < std::numeric_limits<float>::max() 
				&& number > std::numeric_limits<float>::min()) )
		{
			f = static_cast<float>(number);
			prec = get_num_dec(f);
			std::cout << std::fixed << std::setprecision(prec);
			std::cout << " converted to :" << f << "f" << std::endl;
		}
		else if (number == std::numeric_limits<double>::infinity()
				|| number == -std::numeric_limits<double>::infinity()
				|| number == std::numeric_limits<double>::quiet_NaN())
		{
			f = static_cast<float>(number);
			std::cout << " converted to :" << f << "f" << std::endl;
		}
		else if (number < std::numeric_limits<double>::min())
			std::cout << " is under the 64 bits float limit." << number << std::numeric_limits<float>::min() << std::endl;
		else
			std::cout << " is over the 64 bits float limit." << number << std::numeric_limits<float>::max() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "is not valid to be converted to float." << std::endl;
	}
}

void ScalarConverter::isDouble(t_convert number)
{
	int prec = 0;
	try
	{
		if ((number < std::numeric_limits<double>::max() 
				&& number > std::numeric_limits<double>::min()))
		{
			prec = get_num_dec(number);
			std::cout << std::fixed << std::setprecision(prec);
			std::cout << " converted to :" << number << std::endl;
		}
		else if (number == std::numeric_limits<double>::infinity() 
				|| number == -std::numeric_limits<double>::infinity()
				|| number == std::numeric_limits<double>::quiet_NaN())
			std::cout << " converted to :" << number << std::endl;
		else if (number < std::numeric_limits<double>::min())
			std::cout << " is under the 64 bits double limit." << number << std::endl;
		else
			std::cout << " is over the 64 bits double limit." << number << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "is not valid to be converted to double." << std::endl;
	}
}
*/
