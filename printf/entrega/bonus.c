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

int	ft_print_extended(char *str, va_list args, int pos)
{
	int			lng;
	t_form_data	*format_def;

	format_def = fill_list (str, pos, args);
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
	if (format_def->format == '%')
		lng = print_str_frm ("%", format_def);
	free(format_def);
	return (lng);
}
