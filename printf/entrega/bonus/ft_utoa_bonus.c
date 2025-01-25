/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:37:40 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 14:37:47 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static int	getchrnr(unsigned int val)
{
	int				i;
	unsigned int	aux;

	aux = val;
	i = 0;
	if (val == 0)
		return (1);
	while (aux > 0)
	{
		aux = aux / 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		lenstr;

	lenstr = getchrnr (n);
	str = (char *)malloc ((lenstr + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str[lenstr] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		while (n > 0)
		{
			str[--lenstr] = n % 10 + 48;
			n = n / 10;
		}
	}
	return (str);
}
