/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:12:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/09 15:24:50 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int is_delimit(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
int main(int av, char **ac)
{
	int start;
	int end;
	int i;

	if(av !=  2)
	{
		write(1, "\n", 1);
		return(0);
	}
	i = 0;
	while(ac[1][i])
		i++;
	end = i;
	while (end)
	{
		while (i && !is_delimit(ac[1][i]))
			i--;
		if (i)
			start = i + 1;
		else
			start = i;
		while(start < end && ac[1][start])
			write(1, &ac[1][start++], 1);
		if (i)
			write(1, " ", 1);
		end = i--;
	}
	write(1, "\n", 1);
	return(0);
}
