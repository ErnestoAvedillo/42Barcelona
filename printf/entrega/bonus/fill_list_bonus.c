/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:30:11 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 14:30:30 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	getvalue_from_field(char *str, int start_pos)
{
	int		out;
	int		cur_pos;
	int		last_pos;
	char	*strlen;

	cur_pos = start_pos;
	last_pos = start_pos;
	if (str[cur_pos] == POINT_FLAG)
		cur_pos++;
	last_pos = start_pos;
	if (str[cur_pos] == MINUS_FLAG)
	{
		while (str[last_pos] == MINUS_FLAG)
			last_pos++;
		cur_pos = last_pos;
	}
	while (ft_isdigit(str[last_pos]))
		last_pos++;
	strlen = ft_substr(str, cur_pos, last_pos - cur_pos);
	if (!strlen)
		return (-1);
	out = ft_atoi(strlen);
	free (strlen);
	return (out);
}
//	printf("string recibida %s devuelve 
// strlen %s cur_pos %d last_pos %d\n",str, strlen, cur_pos, last_pos );

void	get_len_field(char *str, t_form_data *formato, va_list args)
{
	int	start_pos;
	int	val_length;

	start_pos = 0;
	val_length = 0;
	if (str[start_pos] == POINT_FLAG)
		return ;
	if (str[start_pos] == ASTERISC_FLAG)
		get_len_asterisc(formato, args);
	else
	{
		if (formato->iszero && !formato->ispoint)
			return ;
		val_length = getvalue_from_field (str, start_pos);
		if (val_length == -1)
			formato->error = 1;
		else
			formato->longfield = val_length;
	}
	return ;
}
//	printf("%s longfield devuelve %d\n",str,formato->longfield );

void	get_len_zeros(char *str, t_form_data *formato, va_list args)
{
	int	cur_pos;
	int	val_strlen;

	cur_pos = 0;
	val_strlen = 0;
	if (formato->ispoint)
	{
		while (str[cur_pos] != POINT_FLAG)
			cur_pos++;
		cur_pos++;
	}
	else
		while (!ft_isdigit(str[cur_pos]) && str[cur_pos] != 0)
			cur_pos++;
	if (str[cur_pos] == ASTERISC_FLAG)
		get_zero_asterisc(formato, args);
	else
	{
		val_strlen = getvalue_from_field (str, cur_pos);
		if (val_strlen == -1)
			formato->error = 1;
		else
			formato->prtstrlen = val_strlen;
	}
	return ;
}
//printf("%s cur pos %d getzeros devuelve %d\n",
//str, cur_pos, formato->prtstrlen );

t_form_data	*fill_list(char *str, int pos, va_list args)
{
	t_form_data	*frmt;
	int			cur_pos;
	char		*straux;

	frmt = newdata();
	if (!frmt)
		return (NULL);
	frmt->cur_str_pos = pos;
	cur_pos = pos;
	pos = get_flags (str, pos, frmt);
	frmt->format = str[pos];
	while (is_flag(str[cur_pos]))
		cur_pos++;
	straux = ft_substr (str, cur_pos, pos - cur_pos);
	if (!straux)
	{
		free(frmt);
		return (NULL);
	}
	get_len_field(straux, frmt, args);
	if (frmt->ispoint || frmt->iszero)
		get_len_zeros(straux, frmt, args);
	free (straux);
	return (frmt);
}
