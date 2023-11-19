/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:07:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/16 11:07:31 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(char c)
{
	int	val;

	val = write(STDOUT_FILENO, &c, 1);
	return (val);
}

int	ft_print_str(char *str)
{
	int	len;
	int	out;
	int	i;
	int	aux;

	out = 0;
	i = 0;
	if (str == (char *) NULL)
		return (write(STDOUT_FILENO, "(null)", 6));
	else
	{
		len = ft_strlen(str);
		while (i < len)
		{
			aux = write(STDOUT_FILENO, &str[i++], 1);
			if (aux == -1)
				return (aux);
			else
				out += aux;
		}
	}
	return (out);
}

int	ft_print_int(int val)
{
	char	*str;
	int		lng;

	str = ft_itoa (val);
	if (!str)
		return (-1);
	lng = ft_print_str (str);
	free (str);
	return (lng);
}

int	ft_print_uint(unsigned int val, char formato)
{
	char	*str;
	int		lng;

	if (formato == 'u' || val == 0)
		str = ft_utoa (val);
	else
		str = ft_addrtoa ((size_t)val, formato, 0);
	if (!str)
		return (-1);
	lng = ft_print_str (str);
	free (str);
	return (lng);
}

int	ft_print_addr(size_t val, char formato)
{
	char	*str;
	int		lng;

	if (val == 0)
		str = ft_strdup("0x0");
	else
	{
		str = ft_addrtoa (val, formato, 0);
	}
	if (!str)
		return (-1);
	lng = ft_print_str (str);
	free (str);
	return (lng);
}
