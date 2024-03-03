/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:35:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/02 22:44:43 by eavedill         ###   ########.fr       */
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
	PmergeMe my_oper;
	std::string str(ac[1]);
	std::stringstream ss(str);
	std::string word;
	int out;
	while (ss >> word)
	{
		try
		{
			out = convert(word);
			my_oper.AddVal(out);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return (1);
		}
	}
	my_oper.printList();
	my_oper.sort();
	return 0;
}
