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

int	get_len_field(char *str, int first_pos)
{
	int		lenfield;
	char	*strlen;
	int		end_pos;

	lenfield = 0;
	end_pos = first_pos;
	while (ft_isdigit (str[end_pos]))
		end_pos++;
	strlen = ft_substr (str, first_pos, end_pos - first_pos);
	if (!strlen)
		return (-1);
	lenfield = ft_atoi (strlen);
	free (strlen);
	return (lenfield);
}

int	print_extra_char(int lenfield,int lenstr,char c)
{
	int	i;
	int	out;

	i = 0;
	while (lenfield >= lenstr + i++)
		out += write (1, &c, 1);
	return (out);
}

int	min(int v1, int v2)
{
	if (v1 > v2)
		return (v2);
	return (v1);
}

int	write_extended(char *str, int post, int lenfield, char formato)
{
	int	lenstr;
	int	out;
	char *substr;

	out = 0;
	lenstr = (int) ft_strlen(str);
	if (formato == '.')
	{
		printf("entro\n");
		substr = ft_substr(str,0, min (lenfield, lenstr));
		out += ft_printf (substr);
		free (substr);
		return (out);
	}
	if (!post)
	{
		if (formato == 'd' || formato == 'i')
			print_extra_char (lenfield, lenstr,'0');
		else
			print_extra_char (lenfield, lenstr,'@');
	}
	out += ft_printf (str);
	if (post)
			print_extra_char (lenfield, lenstr,'#');
	return (out);
}
