/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:07:12 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/12 12:07:16 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	print_var(va_list args, char c)
{
	char	*aux;
	int		aux1;
	int		n;

	n = 0;
	if (c == 's')
	{
		aux = va_arg(args, char *);
		ft_putstr_fd(aux, STDERR_FILENO);
		n = ft_strlen(aux);
	}
	else if (c == 'c')
	{
		aux1 = va_arg(args, int);
		n = write(STDERR_FILENO, &aux1, 1);
	}
	return (n);
}

int	print_err(char *str, ...)
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
			val_ret = print_var (args, str[i + 1]);
			i++;
		}
		else
			val_ret = write(STDERR_FILENO, &str[i], 1);
		i++;
	}
	va_end (args);
	return (val_ret);
}
