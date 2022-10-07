/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:39:46 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/26 18:39:48 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putmaxchar(void)
{	
	int		cont;
	char	*maxchar;

	maxchar = "-2147483648";
	cont = 0;
	while (maxchar[cont] != '\0')
	{
		write(1, &maxchar[cont], 1);
		cont++;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	char	out_char;

	if (nb == -2147483648)
	{
		ft_putmaxchar();
		return ;
	}
	if (nb < 0)
	{
		out_char = '-';
		write(1, &out_char, 1);
		nb = -nb;
	}
	i = nb / 10;
	if (i > 10)
		ft_putnbr(i);
	else if (i > 0)
	{
		out_char = i + '0';
		write(1, &out_char, 1);
	}
	out_char = nb % 10 + '0';
	write(1, &out_char, 1);
}
/*
int main()
{
    int value =-123456; //To be between 2**32(negative)  and 2**32 (positive) 
    ft_putnbr(value);
    value =-2147483648; //To be between 2**32(negative)  and 2**32 (positive) 
    
    ft_putnbr(value);
	value = 1234;
	ft_putnbr(value);

    return 0;
}
*/
