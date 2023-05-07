/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:08:26 by eavedill          #+#    #+#             */
/*   Updated: 2023/05/02 10:30:20 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char convert (unsigned int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c += 'A' - 'a';
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
		if(ac[1][i] == '_')
		{
			c= convert(ac[1][++i]);
		}
		else
			c = ac[1][i];
		write (1, &c, 1);		
	}
	write(1, "\n", 1);
	return (0);
}
