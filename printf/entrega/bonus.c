/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:08:26 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/16 18:24:00 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	is_format_char(char c)
{
	if (c != CHAR_FORMAT_C && c != STR_FORMAT_S && \
		c != INT_FORMAT_D && c != INT_FORMAT_I && \
		c != LONG_FORMAT_U && c != ADDR_FORMAT_P && \
		c != HEX_FORMAT_X && c != HEX_FORMAT_X_CAP && c != PERC_FORMAT)
		return (0);
	return (1);
}

int find_flag (char c)
{
	if (c == PLUS_FLAG)
		return (PLUS_FLAG);
	if (c == MINUS_FLAG)
		return (MINUS_FLAG);
	if (c == SPACE_FLAG)
		return (SPACE_FLAG);
	if (c == POUND_FLAG)
		return (POUND_FLAG);
	if (c == ZERO_FLAG)
		return (ZERO_FLAG);
	return (NONE_FLAG);
}

t_form_data	*fill_list(char *str, int pos)
{
	t_form_data	*format_def;
	int			cur_pos;
	char		*straux;

	format_def = newdata();
	if (!format_def)
		return (NULL);
	cur_pos = pos;
	while (!is_format_char (str[pos++]));
	format_def->format = str[pos];
	format_def->cur_str_pos = pos;
	format_def->flag = find_flag (str[cur_pos]);
	straux = ft_substr (str, cur_pos, pos - cur_pos);
	if (straux)
	{
		if (ft_strchr (straux, POINT_FLAG))
			format_def->ispoint = 1;
	}
	else
		format_def->longfield = -1;
	if (format_def->format == STR_FORMAT_S)
		format_def = get_len_field(straux, format_def);
	else
		format_def = get_len_zeros(straux, format_def);
	format_def->error = 0;
	free (straux);
	return (format_def);
}

int	ft_print_extended(char *str, va_list args, int pos)
{
	int			lng;
	t_form_data	*format_def;

	format_def = fill_list (str, pos);
	if (!format_def)
		return (-1);
	lng = 0;
	if (format_def->format == 'd' || format_def->format == 'i')
		lng = print_int_frm (va_arg (args, int), format_def);
	if (format_def->format == 'c')
		lng = print_char_frm (va_arg (args, int), format_def);
	if (format_def->format == 's')
		lng = print_str_frm (va_arg (args, char *), format_def);
	if (format_def->format == 'p')
		lng = print_addr_frm (va_arg (args, size_t), format_def);
	if (format_def->format == 'u' || format_def->format == 'x' || \
		format_def->format == 'X')
		lng = print_uint_frm (va_arg (args, size_t), format_def);
	free(format_def);
	return (lng);
}
