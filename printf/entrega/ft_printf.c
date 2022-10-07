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
#include"ft_printf.h"

static int count_args (char const *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ret++;
	}
	return (ret);
}
void ft_printf (char const *str, ...)
{
	va_list args;
	int i;
	int nargs;

	i = 0;
	nargs = count_args(str);
	va_start(args,nargs);
	while (i<=nargs)
	{
		printf ("%d", args);
		i++;
	}
	va_end (args);
}