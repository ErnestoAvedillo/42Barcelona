/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:54 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/08 13:45:58 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int print_symbol (char flag, int val)
{
	int out = 0;

	if ((flag == '+') && val >= 0)
		out= write (1, &flag, 1);
	if (val < 0)
		out= write (1, "-", 1);
	return (out);
}

int	print_int_frm(int val, t_form_data *formato)
{
	int		lng;
	char	*strval;

	lng = print_symbol (formato->flag, val);
	if (val == -2147483648)
		strval = ft_strdup("2147483648");
	else if (val < 0)
	{
		val *= -1;
		strval = ft_itoa (val);
	}
	else 
		strval = ft_itoa (val);
	lng = write_extended(strval, formato);
	free(strval);
	return (lng);
}

int	print_char_frm(int val, t_form_data *formato)
{
	int		lng;

	char	*strval;

	lng = 0;
	strval = (char *) malloc (2 * sizeof(char));
	strval[0] = val;
	strval[1] = '\0';
	if (val == 0)
	{
		formato->longfield--;
		lng++;
	}
	lng += write_extended(strval, formato);
	free(strval);
	return (lng);
}

int	print_str_frm(char *prtstr, t_form_data *formato)
{
	int		lng;

	lng = write_extended(prtstr, formato);
	return (lng);
}

int	print_addr_frm( size_t ptr, t_form_data *formato)
{
	int		lng;
	char	*strval;

	lng = 0;
	if (ptr == 0)
		strval = ft_strdup("0x0");
	else
		strval = ft_addrtoa (ptr, 'p');
	lng = write_extended (strval, formato);
	free (strval);
	return (lng);
}

int	print_uint_frm( unsigned int val, t_form_data *formato)
{
	int		lng;
	char	*strval;

	if (val == 0)
		strval = ft_strdup("0");
	else if (formato->format == 'u')
		strval = ft_utoa (val);
	else if (formato->format == 'x' || formato->format == 'X')
		strval = ft_addrtoa (val, formato->format);
	lng = write_extended(strval, formato);
	free (strval);
	return (lng);
}
