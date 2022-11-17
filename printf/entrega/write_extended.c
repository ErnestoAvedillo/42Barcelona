/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_extended.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:37:08 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/13 16:37:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_zeros(char *str, t_form_data *formato)
{
	int	out;
	int	lenstr;

	lenstr = (int) ft_strlen(str);
	out = 0;
	if (formato->format == 'd' || formato->format == 'i' || \
		formato->format == 'x')
	{
		if (formato->flag == PLUS_FLAG || formato->flag == POINT_FLAG || \
			formato->iszero)
			out = print_extra_char (formato->iszero, 0, lenstr, '0');
	}
	return (out);
}

static int	print_suf_blanc(char *str, t_form_data *formato)
{
	int	out;
	int	lenstr;

	lenstr = (int) ft_strlen(str);
	out = 0;
	if ((formato->flag == PLUS_FLAG && !formato->iszero) || \
		((formato->format == INT_FORMAT_D || \
			formato->format == INT_FORMAT_I) && \
		((formato->flag == NONE_FLAG || formato->flag == SPACE_FLAG) && \
		!formato->iszero)) || \
		(formato->format == LONG_FORMAT_U && (formato->flag != MINUS_FLAG || \
		formato->flag == POINT_FLAG)) || \
		((formato->format == HEX_FORMAT_X || \
		formato->format == HEX_FORMAT_X_CAP) && \
		(formato->flag == NONE_FLAG || formato->flag == POUND_FLAG) && \
		!formato->iszero) || \
		((formato->format == STR_FORMAT_S || formato->format == CHAR_FORMAT_C) \
		&& (formato->flag != MINUS_FLAG && formato->flag != POINT_FLAG)) || \
		(formato->format == ADDR_FORMAT_P && (formato->flag != MINUS_FLAG || \
		formato->flag == POINT_FLAG)) || \
		(formato->format == PERC_FORMAT && formato->flag != MINUS_FLAG))
		out += print_extra_char (formato->longfield, formato->iszero, lenstr, ' ');
	return (out);
}

int	write_extended(char *str, t_form_data *formato)
{
	int		lenstr;
	int		out;
	char	*substr;

	out = 0;
	lenstr = (int) ft_strlen(str);
	out += print_suf_blanc (str, formato);
	out += print_zeros(str, formato);
	if (formato->flag == '.' && lenstr > formato->longfield)
	{
		substr = ft_substr(str, 0, formato->longfield);
		out += ft_print_str (substr);
		free (substr);
	}
	else
		out += ft_print_str (str);
	if (formato->flag == '-')
		out += print_extra_char (formato->longfield, 0, lenstr, ' ');
	return (out);
}
