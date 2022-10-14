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
/*
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
}*/
void ft_printf (char const *str, ...)
{
	va_list	args;
	int		d;
//	char	c;
//	char	*s;
	char 	*aux;

	//nargs_str = count_args(str);
	printf("Hola?\n");
	aux = (char *) str;
	va_start(args,str);
		printf("La fase es)>%s< en el puntero >%p<\n",aux, aux );
//		while (	args)
//		{
			d = va_arg(args, int);
			printf("int %d puntero %p -- %s\n", d, &d, str);
			d = va_arg(args, int);
			printf("int %d puntero %p -- %s\n", d, &d, str);
			d = va_arg(args, int);
			printf("int %d puntero %p -- %s\n", d, &d, str);
			d = va_arg(args, int);
			printf("int %d puntero %p -- %s\n", d, &d, str);

/*			printf("entro en wh %p \n", str);
			if (*str == 's')
			{
				s = va_arg(args, char *);
				printf("entro en str %s puntero %p\n", s, str);
			}
			else if (*str == 'c')
			{
				printf("char %c puntero %p\n", c, str);
				c = (char)va_arg(args, int);
			}
			else if (*str == 'd')
			{
				d = va_arg(args, int);
				printf("int %d puntero %p\n", d, str);
			}
			*str++;
*///		}
	va_end (args);
}
