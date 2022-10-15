/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:10:40 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 11:20:17 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

static int	getchrnr(size_t val)
{
	int	i;
	size_t	aux;

	aux = val;
	i = 0;
	if (val == 0)
		return (1);
	while (aux > 0)
	{
		aux = aux / 16;
		i++;
	}
	return (i);
}

char	*ft_addrtoa(size_t n, int format)
{
	char	*str;
	int		lenstr;
	char	vect_val[17];

	ft_strlcpy(vect_val,"0123456789abcdef",17);
	lenstr = getchrnr (n);
	if (format)
		lenstr += 3;
	else
		lenstr += 1;
	str = (char *)malloc ((lenstr) * sizeof (char));
	if (!str)
		return (NULL);
	str[lenstr--] = '\0';
	if (format)
	{
		str[0] = '0';
		str[1] = 'x';
	}
	while (n > 0)
	{	
		str[--lenstr] = vect_val[n % 16];
		n = n / 16;
	}
	return (str);
}
