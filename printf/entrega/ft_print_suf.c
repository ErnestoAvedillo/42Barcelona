/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_suf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:27:01 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/21 06:27:06 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

int	ft_printf_suf_str(t_form_data *formato)
{
	if (formato->format == STR_FRMT_S || formato->format == CHAR_FRMT_C)
	{
		if (formato->flag != MINUS_FLAG && formato->flag != POINT_FLAG)
			return (1);
	}
	return (0);
}

int	ft_printf_suf_int(t_form_data *formato)
{
	if (formato->format == INT_FRMT_D || formato->format == INT_FRMT_I)
	{
		if (((formato->flag == NONE_FLAG || formato->flag == SPACE_FLAG \
			|| formato->flag == PLUS_FLAG) && formato->iszero <= 0))
			return (1);
		if (formato->ispoint == 1 && (formato->longfield > formato->prtstrlen) \
			&& formato->flag != MINUS_FLAG)
			return (1);
	}
	return (0);
}

int	ft_printf_suf_lng(t_form_data *formato)
{
	if (formato->format == LONG_FRMT_U)
	{
		if (formato->flag != MINUS_FLAG)
			return (1);
	}
	return (0);
}

int	ft_printf_suf_hex(t_form_data *formato)
{
	if ((formato->format == HEX_FRMT_X \
		|| formato->format == HEX_FRMT_X_CAP))
	{
		if (formato->flag != MINUS_FLAG)
			return (1);
	}
	return (0);
}

int	ft_printf_suf_addr(t_form_data *formato)
{
	if (formato->format == ADDR_FRMT_P)
	{
		if (formato->flag != MINUS_FLAG || formato->ispoint)
			return (1);
	}
	return (0);
}
