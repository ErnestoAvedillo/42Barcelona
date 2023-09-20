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

char	chr_to_up(char c)
{
	if(c >= 97 && c <= 123)
		return (c - 32);
	return (c);
}

void	str_to_up(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = chr_to_up(str[i]);
}

int main (int av, char **ac)
{
	int i;

	if (av < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	i = 0;
	while (ac[++i])
	{
		str_to_up(ac[i]);
		std::cout <<ac[i];
		if (!ac[i + 1])
			std::cout <<"\n";
		else
			std::cout << " ";
	}
	return (0);
}
