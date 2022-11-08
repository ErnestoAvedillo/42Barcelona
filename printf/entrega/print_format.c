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

int define_pos (char flag)
{
	if (flag == '+' || flag == '.')
		return (0);
	return (1);
}

int print_symbol (char flag, int val)
{
	int out = 0;

	if ((flag == '+') && val >= 0)
		out= write (1, &flag, 1);
	if (val < 0)
		out= write (1, "-", 1);
	return (out);
}

int inc_pos (char * str, int pos)
{
	if (str[pos] == '+' || str[pos] == '-' \
		|| str[pos] == '.' || str[pos] == ' ' || str[pos] == '#')
		return (1);
	return (0);
}

int	print_int_frm(char *str, int val, int pos, char formato)
{
	int		lng;
	char	*strval;
	int		lenfield;
	int		addsign;
	int		post;

	post = define_pos (str[pos]);
	lng = print_symbol (str[pos], val);
	addsign = lng;
	pos += inc_pos (str, pos);
	lenfield = 0;
	if (val == -2147483648)
		strval = ft_strdup("2147483648");
	else if (val < 0)
	{
		val *= -1;
		strval = ft_itoa (val);
	}
	else 
		strval = ft_itoa (val);
	if (ft_isdigit (str[pos]))
		lenfield = get_len_field (str, pos) - addsign;
	lng += write_extended(strval, post, lenfield, formato);
	free(strval);
	return (lng);
}

int	print_char_frm(char *str, int val, int pos, char formato)
{
	int		lng;
	int		lenfield;
	int		post;
	char	*strval;

	lng = 0;
	post = define_pos (str[pos]);
	pos = inc_pos (str, pos);
	lenfield = 0;
	if (ft_isdigit (str[pos]))
		lenfield = get_len_field (str, pos);
	strval = (char *) malloc (2 * sizeof(char));
	strval[0] = val;
	strval[1] = '\0';
	if (val == 0)
	{
		lenfield--;
		lng++;
	}
	lng += write_extended(strval, post, lenfield, formato);
	free(strval);
	return (lng);
}

int	print_str_frm(char *str, char *prtstr, int pos, char formato)
{
	int		lng;
	int		cur_pos;
	int		lenfield;
	int		post;

	lng = 0;
	post = define_pos (str[pos]);
	pos = inc_pos (str, pos);
	cur_pos = pos;
	lenfield = 0;
	if (ft_isdigit (str[cur_pos]))
		lenfield = get_len_field (str, cur_pos);
	lng += write_extended(prtstr, post, lenfield, formato);
	return (lng);
}

int	print_addr_frm(char *str, size_t ptr, int pos, char formato)
{
	int		lng;
	char	*strval;
	int		lenfield;
	int		post;

	lng = 0;
	post = define_pos (str[pos]);
	pos = inc_pos (str, pos);
	if (ptr == 0)
		strval = ft_strdup("0x0");
	else
		strval = ft_addrtoa (ptr, 'p');
	if (ft_isdigit (str[pos]))
		lenfield = get_len_field (str, pos);
	lng += write_extended (strval, post, lenfield, formato);
	free (strval);
	return (lng);
}

int	print_uint_frm(char *str, unsigned int val, int pos, char formato)
{
	int		lng;
	char	*strval;
	int		lenfield;
	int		post;

	lng = 0;
	post = define_pos (str[pos]);
	pos = inc_pos (str, pos);
	if (val == 0)
		strval = ft_strdup("0");
	else if (formato == 'u')
		strval = ft_utoa (val);
	else if (formato == 'x' || formato == 'X')
		strval = ft_addrtoa (val, formato);
	if (ft_isdigit (str[pos]))
		lenfield = get_len_field (str, pos);
	lng += write_extended(strval, post, lenfield, formato);
	free (strval);
	return (lng);
}
