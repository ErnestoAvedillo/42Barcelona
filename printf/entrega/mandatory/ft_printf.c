/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:51:19 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/25 17:13:22 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_var(char *str, va_list args, int pos )
{
	int	longitud;

	longitud = 0;
	if (str[pos] == '%')
		longitud = ft_print_char (str[pos]);
	else if (str[pos] == 'c')
		longitud = ft_print_char (va_arg(args, int));
	else if (str[pos] == 's')
		longitud = ft_print_str (va_arg(args, char *));
	else if (str[pos] == 'd' || str[pos] == 'i')
		longitud = ft_print_int (va_arg (args, int));
	else if (str[pos] == 'u')
		longitud = ft_print_uint (va_arg(args, unsigned int), str[pos]);
	else if (str[pos] == 'p')
		longitud = ft_print_addr (va_arg(args, size_t), str[pos]);
	else if (str[pos] == 'x' || str[pos] == 'X')
		longitud = ft_print_uint (va_arg(args, size_t), str[pos]);
	return (longitud);
}

static int	pos_increase(char *str, int pos)
{
	int	out;

	out = 1;
	while (str[pos] != '%' && str[pos] != 'c' && \
		str[pos] != 's' && str[pos] != 'd' && \
		str[pos] != 'i' && str[pos] != 'u' && \
		str[pos] != 'p' && str[pos] != 'x' && \
		str[pos] != 'X')
	{
		pos++;
		out++;
	}
	return (out);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		val_ret;
	int		aux;

	va_start(args, str);
	i = 0;
	val_ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			aux = print_var ((char *)str, args, ++i);
			i += pos_increase ((char *)str, i);
		}
		else
			aux = ft_print_char (str[i++]);
		if (aux == -1)
			return (aux);
		else
			val_ret += aux;
	}
	va_end (args);
	return (val_ret);
}
