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

t_form_data *fill_list (char *str, int pos)
{
	t_form_data *format_def;
	int cur_pos;

	format_def = newdata();
	if (!format_def)
		return (NULL);
	cur_pos = pos;
	//printf("paso %c  pos %d\n", str[pos], pos );
	if (str[pos] == PLUS_FLAG || str[pos] == MINUS_FLAG \
		|| str[pos] == POINT_FLAG || str[pos] == SPACE_FLAG \
		|| str[pos] == POUND_FLAG)
	{
		//printf("paso %c  pos %d\n", str[pos], pos );
		format_def->flag = str[pos++];
		cur_pos = pos;
		if 	(format_def->flag == PLUS_FLAG && str[pos] == '0')
		{
				format_def->iszero = 1;
				cur_pos = ++pos;
		}
	}
	//printf("paso %c  pos %d\n", str[pos], pos );
	while (str[pos] != '%' && str[pos] != CHAR_FORMAT_C && \
	str[pos] != STR_FORMAT_S && str[pos] != INT_FORMAT_D && \
	str[pos] != INT_FORMAT_I && str[pos] != LONG_FORMAT_U && \
	str[pos] != ADDR_FORMAT_P && str[pos] != HEX_FORMAT_x && \
	str[pos] != HEX_FORMAT_X)
	{
		pos++;
	}

	format_def->longfield = get_len_field(str, cur_pos);
	format_def->format = str[pos];
	format_def->cur_str_pos = pos;
	return (format_def);
}

int	ft_print_extended(char *str, va_list args, int pos)
{
	int	lng;
	t_form_data	*format_def;

	format_def = fill_list(str,pos);
	if(!format_def)
		return (-1);
/*	printf("flag %c iszero %d longfield %d format %c cur_pos %d\n",\
			format_def->flag, format_def->iszero, format_def->longfield, \
			format_def->format, format_def->cur_str_pos);
	return (10);
*/	lng = 0;
	if (format_def->format == 'd' || format_def->format == 'i')
		lng = print_int_frm (va_arg (args, int), format_def);
	if (format_def->format == 'c')
		lng = print_char_frm (va_arg (args, int), format_def);
	if (format_def->format == 's')
		lng = print_str_frm (va_arg (args, char *), format_def);
	if (format_def->format == 'p')
		lng = print_addr_frm (va_arg (args, size_t), format_def);
	if (format_def->format == 'u' || format_def->format == 'x' || format_def->format == 'X')
		lng = print_uint_frm (va_arg (args, size_t), format_def);
	free(format_def);
	return (lng);
}
