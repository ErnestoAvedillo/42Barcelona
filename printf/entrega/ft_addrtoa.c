/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
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
	
	printf("entro2\n");

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

char	*ft_addrtoa(size_t n)
{
	char	*str;
	int		lenstr;
	char	*vect_val;

	vect_val = NULL;
	ft_strlcpy(vect_val,"0123456789abcdef",17);
	lenstr = getchrnr (n);
	str = (char *)malloc ((lenstr + 3) * sizeof (char));
	if (!str)
		return (NULL);
	str[lenstr] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		str[0] = '0';
		str[1] = 'x';
		while (n > 0)
		{	
			str[--lenstr] = vect_val[n % 16];
			printf("%c\n",vect_val[n%16] );
			n = n / 16;
		}
	}
	return (str);
}
