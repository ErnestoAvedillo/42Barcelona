/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:38:15 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/26 18:38:19 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_put_val(int c1, int c2)
{	
	ft_put_char((c1 / 10) + '0');
	ft_put_char((c1 % 10) + '0');
	ft_put_char(' ');
	ft_put_char((c2 / 10) + '0');
	ft_put_char((c2 % 10) + '0');
}

void	ft_print_comb2(void);

void	ft_print_comb2(void)
{
	int	val_1;
	int	val_2;
	int	limit_val;

	val_1 = 0;
	val_1 = 0;
	limit_val = 99;
	while (val_1 <= limit_val)
	{
		val_2 = val_1 + 1;
		while (val_2 <= limit_val)
		{
			ft_put_val (val_1, val_2);
			if (!(val_1 == 98 && val_2 == 99))
			{
				ft_put_char(',');
				ft_put_char(' ');
			}
			val_2++;
		}
		val_1++;
	}
}
/*
int main()
{
    ft_print_comb2();


    return 0;
}
*/
