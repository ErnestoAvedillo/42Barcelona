/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_frmt_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:33:36 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 14:33:50 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

int	print_int_frm(int val, t_form_data *frmt)
{
	int		lng;
	char	*strval;

	if (val < 0)
		frmt->signo = -1;
	if (val == -2147483648)
		strval = ft_strdup("2147483648");
	else if (val < 0)
	{
		val *= -1;
		strval = ft_itoa (val);
	}
	else if (frmt->ispoint && frmt->prtstrlen == 0 && val == 0)
	{
		strval = ft_strdup("");
		frmt->esvalcero = 0;
	}
	else
		strval = ft_itoa (val);
	if (!strval)
		return (-1);
	chk_frmt_int(frmt, strval);
	lng = write_extended(strval, frmt);
	free(strval);
	return (lng);
}
//	printf("longfield %d prtstrlen %d \n"
	//,frmt->longfield, frmt->prtstrlen );

int	print_char_frm(int val, t_form_data *frmt)
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
		frmt->longfield--;
	lng += write_extended(strval, frmt);
	free(strval);
	return (lng);
}

int	print_str_frm(char *prtstr, t_form_data *frmt)
{
	int		lng;
	char	*str;

	if (prtstr == NULL)
	{
		str = ft_strdup("(null)");
		if (!str)
			return (-1);
		lng = write_extended(str, frmt);
		free (str);
	}
	else
		lng = write_extended(prtstr, frmt);
	return (lng);
}

int	print_addr_frm( size_t ptr, t_form_data *frmt)
{
	int		lng;
	char	*strval;

	lng = 0;
	if (ptr == 0)
	{
		strval = ft_strdup("0x0");
		frmt->esvalcero = 1;
	}
	else
		strval = ft_addrtoa (ptr, frmt->format, frmt->ispound);
	if (!strval)
		return (-1);
	lng = write_extended (strval, frmt);
	free (strval);
	return (lng);
}

int	print_uint_frm( unsigned int val, t_form_data *frmt)
{
	int		lng;
	char	*strval;

	strval = NULL;
	if (val == 0)
		frmt->esvalcero = 1;
	if (frmt->ispoint && frmt->prtstrlen == 0 && val == 0)
		strval = ft_strdup("");
	else if (val == 0)
		strval = ft_strdup("0");
	else if (frmt->format == LONG_FRMT_U)
		strval = ft_utoa (val);
	else if (frmt->format == 'x' || frmt->format == 'X')
		strval = ft_addrtoa (val, frmt->format, 0);
	if (frmt->ispoint && frmt->longfield < (int) ft_strlen(strval))
		frmt->longfield = (int) ft_strlen(strval);
	if (!strval)
		return (-1);
	lng = write_extended(strval, frmt);
	free (strval);
	return (lng);
}
