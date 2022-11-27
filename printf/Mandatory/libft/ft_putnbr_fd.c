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

void	ft_putnbr_fd(int nb, int fd)
{
	int		i;
	char	out_char;

	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nb < 0)
	{
		out_char = '-';
		ft_putchar_fd(out_char, fd);
		nb = -nb;
	}
	i = nb / 10;
	if (i >= 10)
		ft_putnbr_fd(i, fd);
	else if (i > 0)
	{
		out_char = i + '0';
		ft_putchar_fd(out_char, fd);
	}
	out_char = nb % 10 + '0';
	ft_putchar_fd(out_char, fd);
}
