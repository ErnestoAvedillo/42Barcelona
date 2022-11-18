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
	ptr->print_len = 0;
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

int	get_len_field(char *str)
{
	int		lenfield;
	char	*strlen;
	int		end_pos;
	int		start_pos;

	lenfield = 0;
	end_pos = 0;
	start_pos = -1;
	if (str[0] == POINT_FLAG)
		return (-1);
	if (!ft_isdigit(str[start_pos]))
		while (!ft_isdigit(str[++start_pos]));
	while (ft_isdigit (str[end_pos++]));
	strlen = ft_substr (str, start_pos, end_pos);
	if (!strlen)
		return (-1);
	lenfield = ft_atoi (strlen);
	free (strlen);
	return (lenfield);
}

int	get_len_zeros(char *str, t_form_data formato)
{
	int		lenfield;
	char	*zeroslen;
	int		start_pos;

	lenfield = 0;
	printf("%s\n",ft_strchr(str, POINT_FLAG) );
	if(ft_strchr(str, POINT_FLAG))
		start_pos = (int)(str - ft_strchr(str, POINT_FLAG));
	else if formato->flag == find_flag(formato->flag);
		start_pos = (int)(str - ft_strchr(str, formato->flag));
	zeroslen = ft_substr (str, start_pos + 1, ft_strlen(str));
	if (!zeroslen)
		return (-1);
	lenfield = ft_atoi (zeroslen);
	free (zeroslen);
	return (lenfield);
}

int	print_extra_char(int lenfield, int lenzeros, int lenstr, char c)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (lenzeros < 0)
		lenzeros = 0;
	while (lenfield - lenzeros > lenstr + i++)
		out += write (1, &c, 1);
	return (out);
}
