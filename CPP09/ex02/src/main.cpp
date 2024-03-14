/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:35:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 13:07:03 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int main( int av, char **ac)
{
	std::vector<int> my_oper;
	std::deque<int> my_oper1;
	int val;
	clock_t t1, t2;
	double time_stamp;

	if (av < 2)
	{
		unsigned int nr = 333;
		srand((unsigned int)time((time_t *)NULL));
		for (unsigned int i = 0; i < nr; i++)
		{
			try
			{
				val = rand()% (nr * 10);
				my_oper.push_back(val);
				my_oper1.push_back(val);
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
		while (ss >> word)
		{
			try
			{
				val = convert(word);
				my_oper.push_back(val);
				my_oper1.push_back(val);
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
	t1 = clock();
	PmergeMe(my_oper.begin(), my_oper.end(), my_oper);
	t2 = clock();
	std::cout << "Vector after the sorting is : ";
	printCont(my_oper.begin(), my_oper.end());
	time_stamp = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << my_oper1.size() << " elements with std::vector : " << time_stamp << " seconds." << std::endl;
	std::cout << "Deque Previous the sorting is : ";
	printCont(my_oper1.begin(), my_oper1.end());
	t1 = clock();
	PmergeMe(my_oper1.begin(), my_oper1.end(), my_oper1);
	t2 = clock();
	std::cout << "Deque after the sorting is : ";
	printCont(my_oper1.begin(), my_oper1.end());
	time_stamp = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << my_oper1.size() << " elements with std::deque : " << time_stamp << " seconds." << std::endl;
	return 0;
}
