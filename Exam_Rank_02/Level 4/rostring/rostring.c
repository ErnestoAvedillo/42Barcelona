/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:32:55 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/06 18:04:37 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int is_delimit(char c)
{
	if(c == '\t' || c == ' ')
		return (1);
	return (0);
}

int main(int av,  char **ac)
{
	int i;
	int start;
	int end;
	int curpos;

	curpos = 0;
	if(av == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while(is_delimit(ac[1][i]) && ac[1][i])
		i++;
	start = i;
	while(!is_delimit(ac[1][i]) && ac[1][i])
		i++;
	end = i;
	while(is_delimit(ac[1][i]) && ac[1][i])
		i++;
	while(ac[1][i])
	{
		if (is_delimit(ac[1][i]))
		{
			while(is_delimit(ac[1][i])) 
				i++;
			if(ac[1][i])
			{
				write(1, " ", 1);
				curpos++;
			}
		}
		else
		{
			write(1, &ac[1][i], 1);
			curpos++;
			i++;
		}
	}
	if(curpos)
		write(1, " ", 1);

	while(start < end)
		write(1, &ac[1][start++], 1);
	write(1, "\n",1);
	return (0);
}
