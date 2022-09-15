/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:37:00 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/26 18:37:10 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c1, char c2, char c3)
{
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
}

void	ft_put_single_char(char c1, char c2)
{	
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	ft_print_comb(void);

void	ft_print_comb(void)
{
	int	val_1;
	int	val_2;
	int	val_3;

	val_1 = 0;
	while (val_1 <= 9)
	{
		val_2 = val_1 + 1;
		while (val_2 <= 9)
		{
			val_3 = val_2 + 1;
			while (val_3 <= 9)
			{	
				ft_putchar(val_1 + '0', val_2 + '0', val_3 + '0');
				if (!(val_1 == 7 && val_2 == 8 && val_3 == 9))
				{
					ft_put_single_char(',', ' ');
				}
				val_3++;
			}
			val_2++;
		}
		val_1++;
	}
}
/*
int main()
{
    ft_print_comb();


    return 0;
}
*/
