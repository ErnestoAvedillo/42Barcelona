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
		if (formato->flag == PLUS_FLAG || formato->ispoint || \
			formato->iszero >= 0)
			out = print_extra_char (formato->iszero, 0, lenstr, '0');
	}
	return (out);
}
/*
static t_true_table_spcs crea_true_t_spaces (void)
{
	t_true_table_spcs tablaverdad[10];

	tablaverdad[1]={{STR_FRMAT_S;PLUS_FLAG;-1;-2}};
}*/
static int	print_suf_blanc(char *str, t_form_data *formato)
{
	int	out;
	int	lenstr;

	lenstr = (int) ft_strlen(str);
	out = 0;

	/*printf("flag %c zero %d longfield %d format %c cur_str_pos %d printlen %d \n",\
	formato->flag, formato->iszero,formato->longfield,formato->format,formato->cur_str_pos,
	formato->prtstrlen   );*/

	if (ft_printf_suf_str (formato))
		out += print_extra_char (formato->longfield,0, ft_min(formato->prtstrlen, lenstr), ' ');

	if ((formato->flag == PLUS_FLAG && formato->iszero < 0) || \
		((formato->format == INT_FORMAT_D || \
			formato->format == INT_FORMAT_I) && \
		((formato->flag == NONE_FLAG || formato->flag == SPACE_FLAG) && \
		formato->iszero < 0)) || \
		(formato->format == LONG_FORMAT_U && (formato->flag != MINUS_FLAG || \
		formato->ispoint)) || \
		((formato->format == HEX_FORMAT_X || \
		formato->format == HEX_FORMAT_X_CAP) && \
		(formato->flag == NONE_FLAG || formato->flag == POUND_FLAG) && \
		formato->iszero < 0) || \
		(formato->format == ADDR_FORMAT_P && (formato->flag != MINUS_FLAG || \
		formato->ispoint)) || \
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
	if (formato->ispoint && lenstr > formato->prtstrlen)
	{
		substr = ft_substr(str, 0, formato->prtstrlen);
		out += ft_print_str (substr);
		free (substr);
	}
	else
		out += ft_print_str (str);
	if (formato->flag == '-')
		out += print_extra_char (formato->longfield, 0, lenstr, ' ');
	return (out);
}
