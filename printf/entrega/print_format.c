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

int	print_int_frm(int val, t_form_data *formato)
{
	int		lng;
	char	*strval;

	if (val < 0)
		formato->signo = -1;
	if (val == -2147483648)
		strval = ft_strdup("2147483648");
	else if (val < 0)
	{
		val *= -1;
		strval = ft_itoa (val);
	}
	else if (formato->ispoint && formato->prtstrlen == 0 && val == 0)
		strval = ft_strdup("");
	else
		strval = ft_itoa (val);
	if (!strval)
		return (-1);
	if (formato->isspace && formato->longfield <= (int) ft_strlen(strval))
		formato->longfield = (int) ft_strlen(strval) + 1;
	if (formato->ispoint && formato->longfield < (int) ft_strlen(strval))
		formato->longfield = (int) ft_strlen(strval);
	if ((formato->isplus && formato->signo >= 0) || formato->signo < 0)
	{
		if (!formato->isplus && !formato->isminus && !formato->isspace && !formato->ispoint)
			formato->prtstrlen--;
		formato->longfield--;
	}
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
	if (!strval)
		return (-1);
	strval[0] = val;
	strval[1] = '\0';
	if (val == 0)
		formato->longfield--;
	lng += write_extended(strval, formato);
	free(strval);
	return (lng);
}

int	print_str_frm(char *prtstr, t_form_data *formato)
{
	int		lng;

	if (prtstr == NULL)
	{
		prtstr = ft_strdup("(null)");
		if (!prtstr)
			return (-1);
	}
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
		strval = ft_addrtoa (ptr, formato->format, formato->ispound);
	if (!strval)
			return (-1);
	lng = write_extended (strval, formato);
	free (strval);
	return (lng);
}

int	print_uint_frm( unsigned int val, t_form_data *formato)
{
	int		lng;
	char	*strval;

	strval = NULL;
	if (formato->ispoint && formato->prtstrlen == 0 && val == 0)
		strval = ft_strdup("");
	else if (val == 0)
		strval = ft_strdup("0");
	else if (formato->format == LONG_FRMT_U)
		strval = ft_utoa (val);
	else if (formato->format == 'x' || formato->format == 'X')
		strval = ft_addrtoa (val, formato->format, formato->ispound);
	if (formato->ispoint && formato->longfield < (int) ft_strlen(strval))
		formato->longfield = (int) ft_strlen(strval);
	if (!strval)
			return (-1);
	lng = write_extended(strval, formato);
	free (strval);
	return (lng);
}