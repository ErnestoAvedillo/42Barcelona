/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:19:05 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/06 11:40:55 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

void print_title(int i, std::string msg, std::string color_text, std::string color_border)
{
	std::cout << color_border << "|";
	std::cout << std::setfill('*') << std::setw(5) << "";
	std::cout << color_text << msg << i << color_border << std::setw(5) << "|";
	std::cout << RESET << std::endl;
}

void tests_char()
{
	ScalarConverter convert;
	std::string s[] = {"-1", "3", "90", "255", "500"};
	print_title(1, "Start char tests", BLUE, BLUE);
	size_t len_arr = array_size(s);
	for (size_t i = 0; i < len_arr; i++)
	{
		print_title(i, TEST_TITLE, GREEN, WHITE);
		convert.ToChar(s[i]);
	}
}

void tests_int()
{
	ScalarConverter convert;
	std::string s[]{
		"0",
		"-15",
		"42",
		"444444444444444444444444444444",
		"-44444444444444444444444444444444444424",
		"",
		"aekljweñ", 
		"--", 
		"++", 
		"-3aa"};
	print_title(2, "Start Int tests", BLUE, BLUE);
	size_t len_arr = array_size(s);
	for (size_t i = 0; i < len_arr; i++)
	{
		print_title(i, TEST_TITLE, GREEN, WHITE);
		convert.ToInt(s[i]);
	}
}

void tests_float()
{
	ScalarConverter convert;
	std::string s[]{
		"0",
		"0.0f",
		"-0.5f",
		"0.5f",
		"42.42",
		"inff",
		"-inff",
		"nan",
		"ñdslfnv"};
	print_title(2, "Start Float tests", BLUE, BLUE);
	size_t len_arr = array_size(s);
	for (size_t i = 0; i < len_arr; i++)
	{
		print_title(i, TEST_TITLE, GREEN, WHITE);
		convert.ToFloat(s[i]);
	}
}

void tests_double()
{
	ScalarConverter convert;
	std::string s[]{
		"0",
		"0.0f",
		"-0.5f",
		"0.5f",
		"42.42",
		"inf",
		"inff",
		"-inf",
		"-inff",
		"nan",
		"ñdslfnv"};
	print_title(2, "Start Double tests", BLUE, BLUE);
	size_t len_arr = array_size(s);
	for (size_t i = 0; i < len_arr; i++)
	{
		print_title(i, TEST_TITLE, GREEN, WHITE);
		convert.ToDouble(s[i]);
	}
}

void tests()
{

	tests_char();
	tests_int();
}

int main(int av, char **ac)
{
	if (av == 2)
	{
		ScalarConverter converter;
		std::string to_convert(ac[1]);
		converter.convert(to_convert);
		return 0;
	}
	TestFunctions test[] = {tests_char, tests_int, tests_float, tests_double};
	for (size_t i = 0; i < array_size(test); i++)
	{
		test[i]();
	}

	return 0;
}
