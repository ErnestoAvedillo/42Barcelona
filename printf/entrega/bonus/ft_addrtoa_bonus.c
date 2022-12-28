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
#include "ft_printf_bonus.h"

static int	getchrnr(size_t val)
{
	int		i;
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

static void	get_format(char *str, char formato)
{
	if (formato == 'x')
		ft_strlcpy (str, "0123456789abcdef", 17);
	else if (formato == 'X')
		ft_strlcpy (str, "0123456789ABCDEF", 17);
	else if (formato == 'p')
		ft_strlcpy (str, "0123456789abcdef", 17);
	return ;
}

static int	is_conf_ex(int formato, int ispound)
{
	if (formato == ADDR_FRMT_P || \
		(formato == HEX_FRMT_X && ispound) || \
		(formato == HEX_FRMT_X_CAP && ispound))
		return (1);
	return (0);
}

char	*ft_addrtoa(size_t n, int formato, int ispound)
{
	char	*str;
	int		lenstr;
	char	vect_val[17];

	get_format (vect_val, formato);
	lenstr = getchrnr (n);
	if (is_conf_ex (formato, ispound))
		lenstr += 2;
	str = (char *)malloc ((lenstr + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str[lenstr] = '\0';
	if (is_conf_ex (formato, ispound))
	{
		str[0] = '0';
		str[1] = 'x';
		if (formato == HEX_FRMT_X_CAP)
			str[1] = 'X';
	}
	while (n > 0)
	{	
		str[--lenstr] = vect_val[n % 16];
		n = n / 16;
	}
	return (str);
}
