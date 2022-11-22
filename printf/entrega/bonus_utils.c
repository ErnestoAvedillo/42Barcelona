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
	ptr->iszero = -1;
	ptr->longfield = 0;
	ptr->format = NONE_FORMAT;
	ptr->cur_str_pos = 0;
	ptr->prtstrlen = 0;
	ptr->ispoint = 0;
	return (ptr);
}

int	print_symbol(char flag, int val)
{
	int	out;

	out = 0;
	if (flag == '+' && val >= 0)
		out = ft_print_char (flag);
	if (val < 0)
		out = ft_print_char ('-');
	return (out);
}

t_form_data	*get_len_field(char *str, t_form_data *formato)
{
	char	*strlen;
	int		start_pos;
	int		cur_pos;

	start_pos = 0;
	formato->flag = find_flag (str[start_pos]);
	if (formato->flag != NONE_FLAG)
		start_pos++;
	if (ft_strchr(str, POINT_FLAG))
	{
		formato->ispoint = 1;
		if (str[start_pos] == POINT_FLAG)
		{
			cur_pos = ++start_pos;
			while (ft_isdigit(str[start_pos++]))
			strlen = ft_substr(str, cur_pos, start_pos);
			if (!strlen)
			{
				formato->error = 1;
				return (formato);
			}
			formato->prtstrlen = ft_atoi(strlen);
		}
		else if (ft_isdigit(str[start_pos]))
		{
			cur_pos = start_pos;
			while (ft_isdigit(str[start_pos++]))
			strlen = ft_substr(str, cur_pos, start_pos);
			//printf("strlen %s\n",strlen );
			if (!strlen)
			{
				formato->error = 1;
				return (formato);
			}
			formato->longfield = ft_atoi(strlen);
			//printf("valor longfield%d\n",formato->longfield );
			cur_pos = start_pos;
			while (ft_isdigit(str[start_pos++]));
			//printf("cur_pos %d start_pos %d\n",cur_pos, start_pos );
			strlen = ft_substr(str, cur_pos, start_pos);
			//printf("strlen %s\n",strlen );
			if (!strlen)
			{
				formato->error = 1;
				return (formato);
			}
			formato->prtstrlen = ft_atoi(strlen);
			//printf("valor prtstrlen%d\n",formato->prtstrlen );
		}
	}
	else
	{
		strlen = ft_substr(str, start_pos, ft_strlen(str));
		if (!strlen)
		{
			formato->error = 1;
			return (formato);
		}
		formato->longfield = ft_atoi(strlen);
		formato->prtstrlen = formato->longfield;
		free(strlen);
	}
	return (formato);
}

t_form_data	*get_len_zeros(char *str, t_form_data *formato)
{
	char	*zeroslen;
	int		start_pos;

	if(ft_strchr(str, POINT_FLAG))
		start_pos = (int)(str - ft_strchr(str, POINT_FLAG));
	else if (formato->flag == find_flag(formato->flag))
		start_pos = (int)(str - ft_strchr(str, formato->flag));
	zeroslen = ft_substr (str, start_pos + 1, ft_strlen(str));
	if (!zeroslen)
		return (formato);
	formato->longfield = ft_atoi (zeroslen);
	free (zeroslen);
	return (formato);
}

int	print_extra_char(int lenfield, int lenzeros, int lenstr, char c)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (lenzeros < 0)
		lenzeros = 0;
	//printf("lenfield %d  lenzeros, %d lenstr %d \n", lenfield, lenzeros, lenstr );
	while (lenfield - lenzeros > lenstr + i++)
		out += write (1, &c, 1);
	return (out);
}
