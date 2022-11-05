/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:08:26 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/16 18:24:00 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int print_int_frm(char *str, int val, int pos)
{
	int		lng;
	char	*strval;
	char	*strlen;
	int		cur_pos;
	int		lenfield;
	int		i;

	lng = 0;
	i = 0;
	if((str[pos] == '+' || str[pos] == '-') && val >= 0)
	{
			lng += write (1, &str[pos++], 1);
			i = 1;
	}
	strval = ft_itoa (val);
	cur_pos = pos;
	if(ft_isdigit (str[cur_pos]))
	{
		while(ft_isdigit (str[cur_pos++]));
		strlen =ft_substr (str, pos, cur_pos - pos);
		if(!strlen)
			return (-1);
		lenfield = ft_atoi (strlen) - i;
		free (strlen);
		i = 0;
		while ((int) lenfield > (int) ft_strlen (strval) + i++)
			lng += write (1, "0", 1);
	}
	lng += ft_printf (strval);
	free (strval);
	return (lng);
}

int print_char_frm(char *str, int val, int pos)
{
	int		lng;
	int		cur_pos;
	int		lenfield;
	int		i;
	char	*strlen;

	lng = 0;
	i = 0;
	if((str[pos] == '+' || str[pos] == '-') && val >= 0)
		pos ++;
	cur_pos = pos;
	lenfield = 0;
	if(ft_isdigit(str[cur_pos]))
	{
		while(ft_isdigit(str[cur_pos++]))
		strlen = ft_substr (str, pos, cur_pos - pos);
		if(!strlen)
			return (-1);
		lenfield = ft_atoi(strlen) - i;
		free (strlen);
	}
	lng += write(1,&val,1);
	i = 1;
	while ((int) lenfield > i++)
		lng += write (1, " ", 1);
	return (lng);
}

int	ft_print_extended(char *str, va_list args, int pos)
{
	int		lng;
	int 	end_pos;

	end_pos = pos;
	while(str[end_pos] != '%' && str[end_pos] != 'c' && \
		str[end_pos] != 's' && str[end_pos] != 'd' && \
		str[end_pos] != 'i' && str[end_pos] != 'u' && \
		str[end_pos] != 'p' && str[end_pos] != 'x' && \
		str[end_pos] != 'X')
		end_pos++;
	lng = 0;
	if (str[end_pos] == 'd' || str[end_pos] == 'i')
		lng = print_int_frm(str, va_arg (args, int), pos);
	if (str[end_pos] == 'c')
		lng = print_char_frm(str, va_arg (args, int), pos);
	return (lng);
}
