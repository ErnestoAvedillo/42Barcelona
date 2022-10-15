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

static int ft_print_char (char c)
{
	return(write(1, &c, 1));

}

static int ft_print_int (int val)
{
	char *str;
	int lng;

	str = ft_itoa(val);
	lng = ft_printf(str);
	free(str);
	return (lng);
}

int ft_print_uint (unsigned int val)
{
	char *str;
	int lng;

	str = ft_utoa (val);
	lng = ft_printf(str);
	free (str);
	return (lng);
}
int ft_print_addr (size_t val)
{
	char *str;
	int lng;

	str = ft_addrtoa (val);
	lng = ft_printf(str);
	free (str);
	return (lng);
}


static int print_var (char formato, va_list args )
{
	int longitud;

	longitud = 0;
	if (formato == '%')
		longitud = ft_print_char(write (1,&formato,1));
	else if (formato == 'c')
		longitud = ft_print_char(va_arg(args, int));
	else if (formato == 's')
		longitud = ft_printf(va_arg(args, char *));
	else if (formato == 'd' || formato == 'i')
		longitud = ft_print_int(va_arg(args, int));
	else if (formato == 'u')
		longitud = ft_print_uint(va_arg(args, unsigned int));
	else if (formato == 'p')
		longitud = ft_print_addr(va_arg(args, size_t));
	return (longitud);
}

int	ft_printf (char const *str, ...)
{
	va_list	args;
	int 	i;
	int		val_ret;

	va_start(args,str);
	i = 0;
	val_ret = 0;
	while (str[i])
	{
		if(str[i] == '%')
			val_ret += print_var(str[++i], args);
		else
			val_ret += write(1,&str[i],1);
		i++;

	}
/*			d = va_arg(args, int);
			printf("int %d puntero %p -- %s\n", d, &d, str);
			d = va_arg(args, int);
			printf("int %d puntero %p -- %s\n", d, &d, str);
			d = va_arg(args, int);
			printf("int %d puntero %p -- %s\n", d, &d, str);
			d = va_arg(args, int);
			printf("int %d puntero %p -- %s\n", d, &d, str);
*/

//			*str++;
//		}
	va_end (args);
	return(val_ret);
}
