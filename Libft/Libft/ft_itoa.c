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
#include"libft.h"

static int	pot(int a, int b)
{
	int	i;

	i = 1;
	while (b > 0)
	{
		i = a * i;
		b--;
	}
	return (i);
}

static int	getchrnr(int val)
{
	int	i;

	i = 1;
	while (val / pot (10, i) != 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		lenstr;
	int		i;

	i = 0;
	if (n < 0)
		i = 1;
	lenstr = getchrnr(n);
	str = (char *)calloc (lenstr + i + 1, sizeof (char));
	if (i)
	{
		str[0] = '-';
		n *= -1;
	}
	while (lenstr)
	{
		str[i] = n / pot(10, lenstr - 1) + 48;
		n = n % pot(10, lenstr - 1);
		lenstr--;
		i++;
	}
	str[i] = 0;
	return (str);
}
