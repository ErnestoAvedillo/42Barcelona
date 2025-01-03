/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:08:26 by eavedill          #+#    #+#             */
/*   Updated: 2023/05/02 10:23:20 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char rot_13 (unsigned int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c +=13;
		if (c > 'z')
			c -= 'z' - 'a' + 1;
	}
	else if (c >= 'A' && c <= 'Z')
	{
		c +=13;
		if (c > 'Z')
			c -= 'Z' - 'A' + 1;
	}
	return (c);
}

int main (int av, char **ac)
{
	int i = -1;
	char c;

	if (av != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while(ac[1][++i])
	{
		c = rot_13(ac[1][i]);
		write (1, &c, 1);		
	}
	write(1, "\n", 1);
	return (0);
}
