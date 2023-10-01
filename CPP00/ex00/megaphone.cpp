/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:24:31 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/11 20:24:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int main (int av, char **ac)
{
	if (av < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < av; i++)
	{
		std::string str (ac[i]);
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char) std::toupper(str[j]);
	}
	std::cout <<"\n";
	return (0);
}
