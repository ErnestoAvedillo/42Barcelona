/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:10:40 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 11:20:17 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	getchrnr(long val)
{
	int	i;
	int	aux;

	aux = val;
	i = 0;
	if (val == 0)
		return (1);
	if (aux < 0)
	{
		i++;
		aux *= -1;
	}
	while (aux > 0)
	{
		aux = aux / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		lenstr;

	if (n == -2147483648)
		return (ft_strdup ("-2147483648"));
	lenstr = getchrnr (n);
	str = (char *)malloc ((lenstr + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str[lenstr] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		if (n < 0)
			n *= -1;
		str[0] = '-';
		while (n > 0)
		{
			str[--lenstr] = n % 10 + 48;
			n = n / 10;
		}
	}
	return (str);
}
