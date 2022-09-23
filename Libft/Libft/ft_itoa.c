/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:10:40 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/23 21:32:26 by eavedill         ###   ########.fr       */
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
	int		isneg;
	int		lenstr;
	int		i;

	isneg = 0;
	if (n < 0)
		isneg = 1;
	lenstr = getchrnr(n);
	str = (char *)calloc (lenstr + isneg + 1, sizeof (char));
	if (isneg)
	{
		i = 1;
		str[0] = '-';
	}
	else
	i = 0;
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
