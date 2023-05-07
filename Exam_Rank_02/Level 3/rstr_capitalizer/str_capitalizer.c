/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:08:26 by eavedill          #+#    #+#             */
/*   Updated: 2023/05/02 10:46:05 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char upper (unsigned int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c += 'A' - 'a';
	}
	return (c);
}

char lower (unsigned int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 'a' - 'A';
	}
	return (c);
}

int main (int av, char **ac)
{
	int i;
	int j = 0;
	char c;

	if (av < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while(++j < av)
	{
		i = -1;
		while(ac[j][++i])
		{
			if(ac[j][i - 1] == ' ' || i == 0)
			{
				c= upper(ac[j][i]);
			}
			else
				c = lower(ac[j][i]);
			write (1, &c, 1);		
		}
		write(1, "\n", 1);
	}
	return (0);
}
