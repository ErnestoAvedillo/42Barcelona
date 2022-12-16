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

int	print_extra_char(t_form_data *formato, int lenstr, char c)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (formato->prtstrlen >= 0)
	{
		if (formato->format == INT_FORMAT_I || formato->format == INT_FORMAT_D)
			lenstr = ft_max(formato->prtstrlen, lenstr);
		else
			lenstr = ft_min(formato->prtstrlen, lenstr);
	}
	if (formato->longfield >= 0)
		while (formato->longfield > lenstr + i++)
			out += write (1, &c, 1);
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
	if (formato->prtstrlen < 0)
		return (0);
	val = formato->prtstrlen - lenstr;
	if (val > 0)
		while (val > i++)
			out += write (1, "0", 1);
	return (out);
}
//printf("lenfield %d,  prtstrlen %d, lenstr %d \n",
// lenfield, lenzeros, lenstr );

int	print_symbol(t_form_data *formato, int val)
{
	int	out;
	int	signprinted;

	out = 0;
	signprinted = 0;
	if (formato->flag == '+' && val >= 0)
	{
		out = ft_print_char (formato->flag);
		signprinted = 1;
	}
	if (val < 0)
	{
		out = ft_print_char ('-');
		signprinted = 1;
	}
	if (signprinted)
	{
		if (formato->longfield > formato->prtstrlen)
			formato->longfield--;
		else
			formato->prtstrlen--;
	}
	return (out);
}
