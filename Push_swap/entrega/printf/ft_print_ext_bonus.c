/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ext_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:33:00 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 14:33:09 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

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
	if (frmt->format == INT_FRMT_D || frmt->format == INT_FRMT_I)
		lng = print_int_frm (va_arg (args, int), frmt);
	if (frmt->format == CHAR_FRMT_C)
		lng = print_char_frm (va_arg (args, int), frmt);
	if (frmt->format == STR_FRMT_S)
		lng = print_str_frm (va_arg (args, char *), frmt);
	if (frmt->format == ADDR_FRMT_P)
		lng = print_addr_frm (va_arg (args, size_t), frmt);
	if (frmt->format == 'u' || frmt->format == 'x' || frmt->format == 'X')
		lng = print_uint_frm (va_arg (args, size_t), frmt);
	if (frmt->format == PERC_FRMT)
		lng = print_str_frm ("%", frmt);
	free(frmt);
	return (lng);
}
