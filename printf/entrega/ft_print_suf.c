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
	if ((formato->format == STR_FORMAT_S || formato->format == CHAR_FORMAT_C) \
		&& formato->flag != MINUS_FLAG && formato->flag != POINT_FLAG)
		return (1);
	return (0);
}
/*
	if ((formato->flag == PLUS_FLAG && !formato->iszero) || \
		

		((formato->format == INT_FORMAT_D || \
			formato->format == INT_FORMAT_I) && \
		((formato->flag == NONE_FLAG || formato->flag == SPACE_FLAG) && \
		!formato->iszero))

		 || \
		(formato->format == LONG_FORMAT_U && (formato->flag != MINUS_FLAG || \
		formato->flag == POINT_FLAG)) || \
		
		((formato->format == HEX_FORMAT_X || \
		formato->format == HEX_FORMAT_X_CAP) && \
		(formato->flag == NONE_FLAG || formato->flag == POUND_FLAG) && \
		!formato->iszero) || \
		
		
		(formato->format == ADDR_FORMAT_P && (formato->flag != MINUS_FLAG || \
		formato->flag == POINT_FLAG)) || \
		
		(formato->format == PERC_FORMAT && formato->flag != MINUS_FLAG))
*/