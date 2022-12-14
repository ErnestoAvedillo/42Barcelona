/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utl_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:36:51 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 14:36:58 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

t_form_data	*newdata(void)
{
	t_form_data	*ptr;

	ptr = (t_form_data *) malloc(sizeof(t_form_data));
	if (!ptr)
		return (NULL);
	ptr->isplus = 0;
	ptr->ispoint = 0;
	ptr->iszero = 0;
	ptr->isminus = 0;
	ptr->isspace = 0;
	ptr->ispound = 0;
	ptr->isasterisc = 0;
	ptr->isnone = 1;
	ptr->longfield = -1;
	ptr->prtstrlen = -1;
	ptr->format = NONE_FRMT;
	ptr->cur_str_pos = 0;
	ptr->signo = 0;
	ptr->error = 0;
	ptr->esvalcero = 0;
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
