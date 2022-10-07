/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:17:01 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/26 18:30:46 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_print_combn(int n)
{
	char	number[9];
	char	cur_char;
	int		pos;
	int		salida;
	int		counter;

	salida = 0;
	counter = 0;
	pos = 0;
	while (pos <= n - 1)
	{
		number[pos] = pos + '0';
		pos++;
	}
	while (salida == 0)
	{
		counter = 0;
		while (counter < n)
			write(1, &number[counter++], 1);
		if (number[n - 1] != '9')
			number[n - 1]++;
		if (number[n - 1] == '9')
		{
			if (number [n - 2] != '8')
			{
				cur_char = ' ';
				write(1, &cur_char, 1);
				counter = 0;
				while (counter < n)
					write(1, &number[counter++], 1);
			}
			pos = n - 1;
			cur_char = number[pos];
			cur_char--;
			while (cur_char == number[pos - 1])
			{
				cur_char = number[--pos];
				cur_char--;
			}
			cur_char = (9 - n + 1) + '0';
			if (number[0] == cur_char)
				exit(0);
			else
			{
				number[pos - 1]++;
				while (pos < n)
				{
					cur_char = number[pos - 1];
					cur_char++;
					number[pos] = cur_char;
					pos++;
				}
			}
		}
		cur_char = ' ';
		write(1, &cur_char, 1);
	}
}

int main()
{
    int nr_combin =5;//To be between 0 and 9
    ft_print_combn(nr_combin);


    return 0;
}

