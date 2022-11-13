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

int	is_flag_char(char c)
{
	if (c == PLUS_FLAG || c == MINUS_FLAG \
		|| c == POINT_FLAG || c == SPACE_FLAG \
		|| c == POUND_FLAG || c == ZERO_FLAG)
		return (1);
	return (0);
}

t_form_data	*fill_list(char *str, int pos)
{
	t_form_data	*format_def;
	int			cur_pos;

	format_def = newdata();
	if (!format_def)
		return (NULL);
	cur_pos = pos;
	if (is_flag_char (str[pos]))
	{
		if (str[pos] != ZERO_FLAG)
			format_def->flag = str[pos++];
		cur_pos = pos;
		if (str[pos] == ZERO_FLAG)
		{
				format_def->iszero = 1;
				cur_pos = ++pos;
		}
	}
	while (!is_format_char (str[pos]))
		pos++;
	format_def->longfield = get_len_field(str, cur_pos);
	format_def->format = str[pos];
	format_def->cur_str_pos = pos;
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
