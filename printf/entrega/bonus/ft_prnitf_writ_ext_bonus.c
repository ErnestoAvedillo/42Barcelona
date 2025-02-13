/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnitf_writ_ext_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:37:15 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 14:37:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static int	print_zeros(char *str, t_form_data *formato)
{
	int	out;

	out = 0;
	if (is_numeric(formato->format))
	{
		if ((formato->isplus || formato->ispoint || \
			formato->iszero))
			out = print_extra_zeros (formato, str);
	}
	if (formato->format == PERC_FRMT && (!formato->isminus))
		out = print_extra_zeros (formato, str);
	return (out);
}

static int	print_pre_blanc(char *str, t_form_data *formato)
{
	int	out;

	out = 0;
	if (ft_printf_suf_str (formato))
		out = print_prefix (formato, str, ' ');
	if (ft_printf_suf_int (formato))
		out = print_prefix (formato, str, ' ');
	if (ft_printf_suf_lng (formato))
		out = print_prefix (formato, str, ' ');
	if (ft_printf_suf_hex (formato))
		out = print_prefix (formato, str, ' ');
	if (ft_printf_suf_addr (formato))
		out = print_prefix (formato, str, ' ');
	if (formato->format == PERC_FRMT && !formato->isminus)
		out = print_prefix (formato, str, ' ');
	return (out);
}

int	write_extended(char *str, t_form_data *formato)
{
	int		lenstr;
	int		out;
	char	*substr;

	out = 0;
	lenstr = (int) ft_strlen(str);
	out += print_pre_blanc (str, formato);
	out += print_symbol (formato);
	out += print_zeros(str, formato);
	if (formato->ispoint && formato->prtstrlen >= 0 && \
		lenstr > formato->prtstrlen && formato->format == STR_FRMT_S)
	{
		substr = ft_substr(str, 0, formato->prtstrlen);
		out += ft_print_str (substr);
		free (substr);
	}
	else if (formato->format == CHAR_FRMT_C)
		out += ft_print_char(str[0]);
	else
		out += ft_print_str (str);
	if (formato->isminus)
		out += print_suffix (formato, str, ' ');
	return (out);
}
