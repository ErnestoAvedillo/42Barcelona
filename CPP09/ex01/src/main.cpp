/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:30:26 by marvin            #+#    #+#             */
/*   Updated: 2024/03/01 07:30:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int main(int av, char **ac)
{
	if (av < 2)
		return 0;
	std::stack<int> my_oper;
	std::string str(ac[1]);
    std::stringstream ss(str);
    std::string word;
	int out, aux;
    while (ss >> word) 
	{
		if(word.find_first_of("-+/*") != std::string::npos)
		{
			try
			{
				out = my_oper.top();
				my_oper.pop();
				aux = my_oper.top();
				my_oper.pop();
			}
			catch(const std::exception& e)
			{
				std::cout << "incorrect sintaxis." << std::endl;
				return 1;
			}
			try
			{
				out = operate(aux, out, word[0] );
				my_oper.push(out);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Incorrect syntaxis."<< '\n';
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
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				return (1);
			}
			
		}
	}
	std::cout << "El resultado es : " << out << std::endl;
	if (!my_oper.empty())
		std::cout << "Incorrect operation syntaxis. Stack not empty." << std::endl;
	return 0;
}