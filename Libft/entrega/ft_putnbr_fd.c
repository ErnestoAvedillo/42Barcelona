/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:12:26 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 16:12:31 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_putmaxchar(int fd)
{	
	char	*maxchar;

	maxchar = "-2147483648";
	write(fd, maxchar, 11);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int		i;
	char	out_char;

	if (nb == -2147483648)
	{
		ft_putmaxchar(fd);
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
		ft_putnbr_fd(i, fd);
	else
	{
		out_char = i + '0';
		write(fd, &out_char, 1);
	}
	out_char = nb % 10 + '0';
	write(fd, &out_char, 1);
}
