/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:30:26 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 12:01:25 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int main(int av, char **ac)
{
	if (av != 2)
	{
		std::cout << "Only one argument accepted." << std::endl;
		return 0;
	}
	std::stack<int> my_oper;
	std::string str(ac[1]);
	std::stringstream ss(str);
	std::string word;
	int out, aux;
	while (ss >> word)
	{
		if (word.find_first_of("-+/*") != std::string::npos)
		{
			try
			{
				check_operator(word, my_oper);
				out = my_oper.top();
				my_oper.pop();
				aux = my_oper.top();
				my_oper.pop();
			}
			catch (const std::exception &e)
			{
				std::cout << e.what() << std::endl;
				return 1;
			}
			try
			{
				out = operate(aux, out, word[0]);
				my_oper.push(out);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				return (1);
			}
		}
		else
		{
			try
			{
				out = convert(word);
				my_oper.push(out);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				return (1);
			}
		}
	}
	if (my_oper.size() > 1)
	{
		std::cout << "Intermetiate result: " << out << std::endl;
		std::cout << "Incorrect operation syntaxis. Stack not empty at the end of the operation." << std::endl;
	}
	else
	{
		std::cout << "Final result: " << out << std::endl;
	}
	return 0;
}
