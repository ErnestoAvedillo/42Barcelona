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



int	print_suffix(t_form_data *formato, int lenstr, char c)
{
	int	i;
	int	out;


	i = 0;
	out = 0;
	if (formato->format == CHAR_FRMT_C && formato->ispoint)
		formato->longfield--;
	if (formato->prtstrlen >= 0)
	{
		if (is_numeric(formato->format))
			lenstr = ft_max(formato->prtstrlen, lenstr);
		else
			lenstr = ft_min(formato->prtstrlen, lenstr);
	}
	if (formato->longfield >= 0)
		while (formato->longfield > lenstr + i++)
			out += write (1, &c, 1);
	return (out);}

int	print_prefix(t_form_data *formato, int lenstr, char c)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (formato->isminus && formato->isspace)
	{
		formato->longfield--;
		out = write (1, &c, 1);
		return (out);
	}
	if (!formato->isminus)
	{
		if (formato->format == CHAR_FRMT_C && formato->ispoint)
			formato->longfield--;
		if (formato->prtstrlen >= 0)
		{
			if (is_numeric(formato->format))
				lenstr = ft_max(formato->prtstrlen, lenstr);
			else
				lenstr = ft_min(formato->prtstrlen, lenstr);
		}
		if (formato->longfield >= 0)
			while (formato->longfield > lenstr + i++)
				out += write (1, &c, 1);
		if (is_integer(formato->format))
			if(formato->isspace && formato->longfield <= formato->prtstrlen && \
				formato->signo == 0)
				out = write (1, &c, 1);
	}
	return (out);
}
//printf("lenfield %d,  prtstrlen %d, lenstr %d \n", 
//lenfield, lenzeros, lenstr );

int	print_extra_zeros(t_form_data *formato, int lenstr)
{
	int	i;
	int	val;
	int	out;

	i = 0;
	out = 0;
//	if (formato->signo < 0 && !formato->ispoint)
//		formato->prtstrlen--;
	if (formato->prtstrlen < 0)
		return (0);
	val = formato->prtstrlen - lenstr;
	if (val > 0)
		while (val > i++)
			out += write (1, "0", 1);
	return (out);
}
//	printf("longfield %d,  prtstrlen %d, signo %d \n", 
//formato->longfield, formato->prtstrlen, formato->signo );

int	print_symbol(t_form_data *formato)
{
	int	out;

	out = 0;
	if (formato->isplus && formato->signo >= 0)
		out = ft_print_char ('+');
	if (formato->signo < 0)
		out = ft_print_char ('-');
	return (out);
}
