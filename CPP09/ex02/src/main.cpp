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
	std::vector<int> my_oper;
	std::deque<int> my_oper1;
	if (av < 2)
	{
		unsigned int nr = 30;
		srand((unsigned int)time((time_t *)NULL));
		for (unsigned int i = 0; i < nr; i++)
		{
			try
			{
				my_oper.push_back(rand()% (nr * 10));
				my_oper1.push_back(rand()% (nr * 10));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				break;
			}
		}
	}
	else
	{
	//PmergeMe my_oper;
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
	}
	if (my_oper.size() == 1)
	{
		std::cout << "nothing to be done cont length is 1" << std::endl;
		return 0;
	}
	std::vector<int>::iterator it;
	std::cout << "Vector Previous the sorting is : ";
	printCont(my_oper.begin(), my_oper.end());
	PmergeMe(my_oper.begin(), my_oper.end(), my_oper);
	std::cout << "Vector after the sorting is : ";
	printCont(my_oper.begin(), my_oper.end());
	std::cout << "Deque Previous the sorting is : ";
	printCont(my_oper1.begin(), my_oper1.end());
	PmergeMe(my_oper1.begin(), my_oper1.end(), my_oper1);
	std::cout << "Deque after the sorting is : ";
	printCont(my_oper1.begin(), my_oper1.end());
	return 0;
}
