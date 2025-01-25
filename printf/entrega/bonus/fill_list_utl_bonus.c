/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list_utl_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:30:45 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 14:30:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	put_flag(char x, t_form_data *frmt, int addzero)
{
	if (x == PLUS_FLAG)
		frmt->isplus = 1;
	if (x == POINT_FLAG)
		frmt->ispoint = 1;
	if (x == MINUS_FLAG)
		frmt->isminus = 1;
	if (x == SPACE_FLAG)
		frmt->isspace = 1;
	if (x == POUND_FLAG)
		frmt->ispound = 1;
	if (x == ZERO_FLAG && addzero)
		frmt->iszero = 1;
}

void	check_isflag(t_form_data *frmt)
{
	if (frmt->isplus || frmt->ispoint || frmt->isminus || frmt->isspace || \
		frmt->ispound || frmt->iszero)
		frmt->isnone = 0;
}

int	get_flags(char *str, int pos, t_form_data *frmt)
{
	int	curpos;

	curpos = pos;
	while (is_flag(str[curpos]))
	{
		put_flag(str[curpos], frmt, !frmt->isminus);
		curpos++;
	}
	while (!is_format_char(str[curpos]))
	{
		if (str[curpos] == ASTERISC_FLAG)
			frmt->isasterisc = 1;
		if (str[curpos] == POINT_FLAG)
			frmt->ispoint = 1;
		curpos++;
	}
	check_isflag(frmt);
	return (curpos);
}

void	get_len_asterisc(t_form_data *formato, va_list args)
{
	formato->longfield = va_arg (args, int);
	if (formato->longfield < 0)
	{
		formato->longfield *= -1;
		formato->isminus = 1;
	}
}

void	get_zero_asterisc(t_form_data *formato, va_list args)
{
	formato->prtstrlen = va_arg (args, int);
	if (formato->prtstrlen < 0 && is_numeric(formato->format))
		formato->prtstrlen = formato->longfield;
}
