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
	t_form_data	*frmt;

	frmt = fill_list (str, pos, args);
	if (!frmt || frmt->error == 1)
	{
		if (frmt->error == 1)
			free (frmt);
		return (-1);
	}
	lng = 0;
	if (frmt->format == 'd' || frmt->format == 'i')
		lng = print_int_frm (va_arg (args, int), frmt);
	if (frmt->format == 'c')
		lng = print_char_frm (va_arg (args, int), frmt);
	if (frmt->format == 's')
		lng = print_str_frm (va_arg (args, char *), frmt);
	if (frmt->format == 'p')
		lng = print_addr_frm (va_arg (args, size_t), frmt);
	if (frmt->format == 'u' || frmt->format == 'x' || frmt->format == 'X')
		lng = print_uint_frm (va_arg (args, size_t), frmt);
	if (frmt->format == '%')
		lng = print_str_frm ("%", frmt);
	free(frmt);
	return (lng);
}
