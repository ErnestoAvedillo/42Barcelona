/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:40:19 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/20 14:40:47 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	is_format_char(char c)
{
	if (c != CHAR_FRMT_C && c != STR_FRMT_S && \
		c != INT_FRMT_D && c != INT_FRMT_I && \
		c != LONG_FRMT_U && c != ADDR_FRMT_P && \
		c != HEX_FRMT_X && c != HEX_FRMT_X_CAP && c != PERC_FRMT)
		return (0);
	return (1);
}

int	is_numeric(char c)
{
	if (c == INT_FRMT_D || c == INT_FRMT_I || \
		c == LONG_FRMT_U || c == HEX_FRMT_X || \
		c == HEX_FRMT_X_CAP)
		return (1);
	return (0);
}

int	is_integer(char c)
{
	if (c == INT_FRMT_D || c == INT_FRMT_I)
		return (1);
	return (0);
}

int	is_hexa(char c)
{
	if (c == HEX_FRMT_X || c == HEX_FRMT_X_CAP)
		return (1);
	return (0);
}
