/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 06:44:55 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/21 06:45:50 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	is_flag(char c)
{
	if (c == PLUS_FLAG)
		return (1);
	if (c == MINUS_FLAG)
		return (1);
	if (c == SPACE_FLAG)
		return (1);
	if (c == POUND_FLAG)
		return (1);
	if (c == ZERO_FLAG)
		return (1);
	return (0);
}

int	chk_frmt_hex(t_form_data *formato, char *str)
{
	int	lenstr;

	lenstr = (int) ft_strlen(str);
	if (is_hexa(formato->format) && formato->ispound && ft_strncmp(str, "0", 1))
	{
		if (formato->prtstrlen > lenstr)
			lenstr = formato->prtstrlen + 2;
		else
			lenstr += 2;
		if (formato->prtstrlen >= lenstr)
			formato->longfield -= 2;
	}
	return (lenstr);
}

void	chk_frmt_int(t_form_data *frmt, char *str)
{
	if (frmt->isspace && frmt->longfield <= (int) ft_strlen(str) && \
		!frmt->iszero)
		frmt->longfield = (int) ft_strlen(str) + 1;
	if (frmt->ispoint && frmt->longfield < (int) ft_strlen(str))
		frmt->longfield = (int) ft_strlen(str);
	if ((frmt->isplus && frmt->signo >= 0) || frmt->signo < 0 || frmt->isspace)
	{
		if (!frmt->isspace)
		{
			if (frmt->longfield >= frmt->prtstrlen)
				frmt->longfield--;
			else if (frmt->longfield < 0)
				frmt->prtstrlen--;
		}
		else
		{
			if (frmt->longfield > frmt->prtstrlen && \
				(frmt->isplus || frmt->isminus || frmt->signo < 0))
				frmt->longfield--;
			if (frmt->isspace && frmt->iszero && frmt->longfield < 0)
				frmt->prtstrlen--;
		}
	}
}

int	chk_frmt_prefix(t_form_data *frmt, int i)
{
	int	lenstr;

	lenstr = i;
	if (frmt->format == CHAR_FRMT_C && frmt->ispoint)
		frmt->longfield--;
	if (frmt->prtstrlen >= 0)
	{
		if (is_numeric(frmt->format))
			lenstr = ft_max(frmt->prtstrlen, lenstr);
		else
			lenstr = ft_min(frmt->prtstrlen, lenstr);
	}
	return (lenstr);
}

int	chk_frmt_prefix_minus(t_form_data *frmt, char c)
{
	int	out;

	out = 0;
	if (frmt->longfield > frmt->prtstrlen && !is_numeric(frmt->format))
		frmt->longfield--;
	if (!is_integer(frmt->format) || frmt->signo == 0)
		out += write (1, &c, 1);
	return (out);
}
