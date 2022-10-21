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

static int	print_var(char formato, va_list args )
{
	int	longitud;

	longitud = 0;
	if (formato == '%')
		longitud = ft_print_char (formato);
	else if (formato == 'c')
		longitud = ft_print_char (va_arg(args, int));
	else if (formato == 's')
		longitud = printstr (va_arg(args, char *));
	else if (formato == 'd' || formato == 'i')
		longitud = ft_print_int (va_arg(args, int));
	else if (formato == 'u')
		longitud = ft_print_uint (va_arg(args, unsigned int), formato);
	else if (formato == 'p')
		longitud = ft_print_addr (va_arg(args, size_t), formato);
	else if (formato == 'x' || formato == 'X')
		longitud = ft_print_uint (va_arg(args, size_t), formato);
	return (longitud);
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
			val_ret += print_var (str[++i], args);
		else
			val_ret += write (1, &str[i], 1);
		i++;
	}
	va_end (args);
	return (val_ret);
}
