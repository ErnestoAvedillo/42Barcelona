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
	if (val < 0)
		val *= -1;
	if (val < 10)
		return (1);
	while (val / pot (10, i) > 10)
		i++;
	return (i + 1);
}

static char	*get_max_neg(int n)
{
	char	*str;

	n -= 0;
	str = (char *)calloc (12, sizeof (char));
	ft_strlcpy (str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		lenstr;
	int		i;

	if (n == -2147483648)
		return (get_max_neg (n));
	lenstr = getchrnr(n);
	str = (char *)calloc (lenstr + 2, sizeof (char));
	i = 0;
	if (n < 0)
	{
		i = 1;
		n *= -1;
		str[0] = '-';
	}
	while (lenstr)
	{	
		str[i++] = n / pot(10, lenstr - 1) + 48;
		n = n % pot(10, lenstr - 1);
		lenstr--;
	}
	str[i] = '\0';
	return (str);
}
