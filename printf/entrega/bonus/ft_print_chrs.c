/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:05:48 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/15 22:05:52 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

int	print_suffix(t_form_data *frmt, char *str, char c)
{
	int	i;
	int	out;
	int	lenstr;

	i = 0;
	out = 0;
	lenstr = (int) ft_strlen(str);
	if (frmt->format == CHAR_FRMT_C && frmt->ispoint)
		frmt->longfield--;
	lenstr = chk_frmt_hex(frmt, str);
	if (frmt->prtstrlen >= 0)
	{
		if (is_numeric(frmt->format))
			lenstr = ft_max(frmt->prtstrlen, lenstr);
		else
			lenstr = ft_min(frmt->prtstrlen, lenstr);
	}
	if (frmt->longfield >= 0)
		while (frmt->longfield > lenstr + i++)
			out += write (1, &c, 1);
	return (out);
}

int	print_prefix(t_form_data *frmt, char *str, char c)
{
	int	i;
	int	out;
	int	lenstr;

	i = 0;
	out = 0;
	if (frmt->isminus && frmt->isspace)
	{
		out += chk_frmt_prefix_minus (frmt, c);
		return (out);
	}
	if (!frmt->isminus)
	{
		lenstr = chk_frmt_hex(frmt, str);
		lenstr = chk_frmt_prefix (frmt, lenstr);
		if (frmt->longfield >= 0)
			while (frmt->longfield > lenstr + i++)
				out += write (1, &c, 1);
		if (is_integer(frmt->format))
			if (frmt->isspace && frmt->longfield <= lenstr && frmt->signo == 0)
				out += write (1, &c, 1);
	}
	return (out);
}

int	print_extra_zeros(t_form_data *frmt, char *str)
{
	int	i;
	int	val;
	int	out;
	int	lenstr;

	i = 0;
	out = 0;
	lenstr = (int) ft_strlen(str);
	if (frmt->prtstrlen < 0)
		return (0);
	if (is_hexa(frmt->format) && frmt->ispound && !frmt->ispoint && \
		frmt->iszero && ft_strncmp(str, "0", 1))
		lenstr += 2;
	val = frmt->prtstrlen - lenstr;
	if (val > 0)
		while (val > i++)
			out += write (1, "0", 1);
	return (out);
}
//	printf("longfield %d,  prtstrlen %d, signo %d \n", 
//frmt->longfield, frmt->prtstrlen, frmt->signo );

int	print_symbol(t_form_data *frmt, char *str)
{
	int	out;

	out = 0;
	if (frmt->isplus && frmt->signo >= 0)
		out = ft_print_char ('+');
	if (frmt->signo < 0)
		out = ft_print_char ('-');
	if (frmt->ispound)
	{	
		if (ft_strncmp(str, "0", 1))
		{
			if (frmt->format == HEX_FRMT_X)
				out += write (1, "0x", 2);
			else
				out += write (1, "0X", 2);
		}
	}
	return (out);
}
