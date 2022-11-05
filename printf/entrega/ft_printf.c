/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:51:19 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/07 09:58:25 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	printstr(char *str)
{
	int	len;

	if (str == NULL)
		return (ft_printf("(null)"));
	else
	{
		len = ft_strlen(str);
		write(1, str, len);
		return (len);
	}
}

static int	print_var(char *str, va_list args, int pos )
{
	int	longitud;

	longitud = 0;
	if (str[pos] == '%')
		longitud = ft_print_char (str[pos]);
	else if (str[pos] == 'c')
		longitud = ft_print_char (va_arg(args, int));
	else if (str[pos] == 's')
		longitud = printstr (va_arg(args, char *));
	else if (str[pos] == 'd' || str[pos] == 'i')
		longitud = ft_print_int (va_arg (args, int));
	else if (str[pos] == 'u')
		longitud = ft_print_uint (va_arg(args, unsigned int), str[pos]);
	else if (str[pos] == 'p')
		longitud = ft_print_addr (va_arg(args, size_t), str[pos]);
	else if (str[pos] == 'x' || str[pos] == 'X')
		longitud = ft_print_uint (va_arg(args, size_t), str[pos]);
	else
		longitud = ft_print_extended (str, args, pos);
	return (longitud);
}

int	pos_increase(char *str, int pos)
{
	int	out;

	out = 1;
	while(str[pos] != '%' && str[pos] != 'c' && \
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

	va_start(args, str);
	i = 0;
	val_ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			val_ret += print_var ((char *)str, args, ++i);
			i += pos_increase ((char *)str, i);
		}
		else
			val_ret += write (1, &str[i++], 1);
	}
	va_end (args);
	return (val_ret);
}

//	int		aux;

/*		else if (str[i] == 92)
		{
			aux = specials ((char *)str, ++i);
			val_ret += aux;
			//i += aux - 2;
			i += pos_increase ((char *)str, i);
		}
*/

/*

int specials (char *str, int pos)
{
	char	*aux;
	int		out;

	out = 0;
	if (ft_isdigit (str[pos + 1]))
	{
		aux = ft_substr (str, pos, 3);
		if (!aux)
			return (-1);
		out += write (1, &out, 4);
		free (aux);
	}
	else if (str[pos + 1] == 'b' || str[pos + 1] == 't' \
		 || str[pos + 1] == 'n' || str[pos + 1] == 'f' \
		 || str[pos + 1] == 'r')
	{
		aux = ft_substr (str, pos, 2);
		if (!aux)
			return (-1);
		out += write (1, &aux, 2);
		free (aux);
	}
	else if (str[pos + 1] == 92)
		out += write (1, &str[pos + 1], 1);
	else
		return (-1);
	return (out);
}

*/
