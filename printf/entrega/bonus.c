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
	int	lng;
	int	end_pos;

	end_pos = pos;
	while (str[end_pos] != '%' && str[end_pos] != 'c' && \
		str[end_pos] != 's' && str[end_pos] != 'd' && \
		str[end_pos] != 'i' && str[end_pos] != 'u' && \
		str[end_pos] != 'p' && str[end_pos] != 'x' && \
		str[end_pos] != 'X')
		end_pos++;
	lng = 0;
	if (str[end_pos] == 'd' || str[end_pos] == 'i')
		lng = print_int_frm (str, va_arg (args, int), pos, str[end_pos]);
	if (str[end_pos] == 'c')
		lng = print_char_frm (str, va_arg (args, int), pos, str[end_pos]);
	if (str[end_pos] == 's')
		lng = print_str_frm (str, va_arg (args, char *), pos, str[end_pos]);
	if (str[end_pos] == 'p')
		lng = print_addr_frm (str, va_arg (args, size_t), pos, str[end_pos]);
	if (str[end_pos] == 'u' || str[end_pos] == 'x' || str[end_pos] == 'X')
		lng = print_uint_frm (str, va_arg (args, size_t), pos, str[end_pos]);
	return (lng);
}
