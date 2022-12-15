/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:23:58 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/02 11:24:01 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

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

int	getvalue_from_field(char *str, int start_pos)
{
	int		out;
	int		cur_pos;
	int		last_pos;
	char	*strlen;

	cur_pos = start_pos;
	if (str[cur_pos] == POINT_FLAG)
		cur_pos++;
	last_pos = start_pos;
	while (ft_isdigit(str[last_pos]))
		last_pos++;
	strlen = ft_substr(str, cur_pos, last_pos - cur_pos);
	if (!strlen)
		return (-1);

	out = ft_atoi(strlen);
	free (strlen);
	return (out);
}

void	get_len_field(char *str, t_form_data *formato, va_list args)
{
	int		start_pos;

	start_pos = 0;
	if (str[start_pos] == POINT_FLAG)
		return ;
	if (str[start_pos] == ASTERISC_FLAG)
		formato->longfield = va_arg (args, int);
	else
	{
		if (formato->flag == ZERO_FLAG && formato->ispoint == 0)
			return ;
		formato->longfield = getvalue_from_field (str, start_pos);
	}
	return ;
}
//	printf("%s longfield devuelve %d\n",str,formato->longfield );

void	get_len_zeros(char *str, t_form_data *formato, va_list args)
{
	int	cur_pos;	

	cur_pos = -1;
	while (str[cur_pos] != POINT_FLAG && formato->ispoint == 1)
		cur_pos++;
	cur_pos++;
	if (str[cur_pos] == ASTERISC_FLAG)
		formato->prtstrlen = va_arg (args, int);
	else
	{
		formato->prtstrlen = getvalue_from_field (str, cur_pos);
	}
	return ;
}
//printf("%s cur pos %d getzeros devuelve %d\n",
//str, cur_pos, formato->prtstrlen );

t_form_data	*fill_list(char *str, int pos, va_list args)
{
	t_form_data	*format_def;
	int			cur_pos;
	char		*straux;

	format_def = newdata();
	if (!format_def)
		return (NULL);
	cur_pos = pos;
	while (!is_format_char (str[pos]))
		pos++;
	format_def->format = str[pos];
	format_def->cur_str_pos = cur_pos;
	format_def->flag = find_flag (str[cur_pos]);
	if (format_def->flag != NONE_FLAG)
		cur_pos++;
	if (str[cur_pos] == ZERO_FLAG)
		format_def->iszero = 1;
	straux = ft_substr (str, cur_pos, pos - cur_pos);
	if (!straux)
	{
		format_def->error = -1;
		return (NULL);		
	}
	if (ft_strchr (straux, POINT_FLAG))
	{
		format_def->ispoint = 1;
		format_def->iszero = 1;
	}
	else
	{
	}
	get_len_field(straux, format_def, args);
	if (format_def->iszero == 1)
		get_len_zeros(straux, format_def, args);
	else
		format_def->error = 0;
	free (straux);
	return (format_def);
}
/*	printf("str %s substr %s flag %c point %d zero %d longfield %d printlen %d format %c cur_str_pos %d error %d\n",\
	str, straux, format_def->flag, format_def->ispoint, format_def->iszero,format_def->longfield, \
	format_def->prtstrlen, format_def->format,format_def->cur_str_pos, format_def->error );
*/
//printf("str %s straux %s cur por %d pos %d\n",str, straux, cur_pos, pos );
