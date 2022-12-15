/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:32:45 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/08 13:32:50 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_form_data	*newdata(void)
{
	t_form_data	*ptr;

	ptr = (t_form_data *) malloc(sizeof(t_form_data));
	if (!ptr)
		return (NULL);
	ptr->flag = NONE_FLAG;
	ptr->isplus = -1;
	ptr->iszero = -1;
	ptr->longfield = -1;
	ptr->prtstrlen = -1;
	ptr->format = NONE_FORMAT;
	ptr->cur_str_pos = 0;
	ptr->ispoint = 0;
	return (ptr);
}

int	print_symbol(t_form_data *formato, int val)
{
	int	out;
	int	signprinted;

	out = 0;
	signprinted = 0;
	if (formato->flag == '+' && val >= 0)
	{
		out = ft_print_char (formato->flag);
		signprinted = 1;
	}
	if (val < 0)
	{
		out = ft_print_char ('-');
		signprinted = 1;
	}
	if (signprinted)
	{
		if (formato->longfield > formato->prtstrlen)
			formato->longfield--;
		else
			formato->prtstrlen--;
	}
	return (out);
}

int	getvalue_from_point(char *str, t_form_data *formato)
{
	int		out;
	int		cur_pos;
	char	*strlen;

	cur_pos = formato->cur_str_pos;
	while (ft_isdigit(str[formato->cur_str_pos]))
		formato->cur_str_pos++;
	strlen = ft_substr(str, cur_pos, formato->cur_str_pos);
	if (!strlen)
	{
		formato->error = 1;
		return (-1);
	}
	out = ft_atoi(strlen);
	free (strlen);
	return (out);
}

t_form_data	*conv_field_to_int(char *str, t_form_data *formato)
{
	formato->ispoint = 1;
	if (str[formato->cur_str_pos] == POINT_FLAG)
	{
		formato->cur_str_pos += 1;
		formato->prtstrlen = getvalue_from_point(str, formato);
	}
	else
	{
		formato->longfield = getvalue_from_point(str, formato);
		formato->cur_str_pos += 1;
		formato->prtstrlen = getvalue_from_point(str, formato);
	}
	return (formato);
}

int	print_extra_char(t_form_data *formato, int lenstr, char c)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (formato->prtstrlen >= 0)
	{
		if (formato->format == INT_FORMAT_I || formato->format == INT_FORMAT_D)
			lenstr = ft_max(formato->prtstrlen, lenstr);
		else
			lenstr = ft_min(formato->prtstrlen, lenstr);
	}
	if (formato->longfield >= 0)
		while (formato->longfield > lenstr + i++)
			out += write (1, &c, 1);
	return (out);
}
//printf("lenfield %d,  prtstrlen %d, lenstr %d \n", 
//lenfield, lenzeros, lenstr );

int	print_extra_zeros(t_form_data *formato, int lenstr)
{
	int	i;
	int	val;
	int	out;

	i = 0;
	out = 0;
	if (formato->prtstrlen < 0)
		return (0);
	val = formato->prtstrlen - lenstr;
	if (val > 0)
		while (val > i++)
			out += write (1, "0", 1);
	return (out);
}
//printf("lenfield %d,  prtstrlen %d, lenstr %d \n",
// lenfield, lenzeros, lenstr );
