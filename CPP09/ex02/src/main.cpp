/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:35:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/03 19:16:41 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int main( int av, char **ac)
{
	if (av < 2)
	{
		std::cout << "please enter a list of integers" << std::endl;
		return 0;
	}
	//PmergeMe my_oper;
	std::vector<int> my_oper;
	std::string str;
	std::string word;
	int i = 0;
	str = "";
	while (av > ++i)
	{
		str += ac[i];
		str += " ";
	}
	std::stringstream ss(str);
	int out;
	while (ss >> word)
	{
		try
		{
			out = convert(word);
			//my_oper.AddVal(out);
			my_oper.push_back(out);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return (1);
		}
	}
	if (my_oper.size() == 1)
	{
		std::cout << "nothing to be done cont length is 1" << std::endl;
		return 0;
	}
	printCont(my_oper.begin(), my_oper.end());
	PmergeMe(my_oper.begin(), my_oper.end(), my_oper);
	printCont(my_oper.begin(), my_oper.end());
	return 0;
}
