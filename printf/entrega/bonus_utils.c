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
	ptr->signo = 0;
	return (ptr);
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

int	is_format_char(char c)
{
	if (c != CHAR_FORMAT_C && c != STR_FORMAT_S && \
		c != INT_FORMAT_D && c != INT_FORMAT_I && \
		c != LONG_FORMAT_U && c != ADDR_FORMAT_P && \
		c != HEX_FORMAT_X && c != HEX_FORMAT_X_CAP && c != PERC_FORMAT)
		return (0);
	return (1);
}

int	find_flag(char c)
{
	if (c == PLUS_FLAG)
		return (PLUS_FLAG);
	if (c == MINUS_FLAG)
		return (MINUS_FLAG);
	if (c == SPACE_FLAG)
		return (SPACE_FLAG);
	if (c == POUND_FLAG)
		return (POUND_FLAG);
	return (NONE_FLAG);
}
