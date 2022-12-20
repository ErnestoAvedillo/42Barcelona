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
		if (!formato->isminus)
			return (1);
	}
	return (0);
}

int	ft_printf_suf_int(t_form_data *formato)
{
	if (is_integer(formato->format))
	{
		if (((formato->isnone || formato->isplus) && \
		 formato->iszero <= 0))
			return (1);
		if (formato->ispoint && (formato->longfield > formato->prtstrlen))
			return (1);
		if (formato->isspace)
			return (1);
	}
	return (0);
}

int	ft_printf_suf_lng(t_form_data *formato)
{
	if (formato->format == LONG_FRMT_U)
	{
		if (!formato->isminus)
			return (1);
	}
	return (0);
}

int	ft_printf_suf_hex(t_form_data *formato)
{
	if (is_hexa(formato->format))
		if (!formato->isminus)
			return (1);
	return (0);
}

int	ft_printf_suf_addr(t_form_data *formato)
{
	if (formato->format == ADDR_FRMT_P)
	{
		if (!formato->isminus || formato->ispoint)
			return (1);
	}
	return (0);
}
