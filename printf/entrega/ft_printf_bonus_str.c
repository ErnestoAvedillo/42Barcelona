/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:35:32 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/22 19:35:37 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
static int	ft_printf_suf_str(t_form_data *formato)
{
	if ((formato->format == STR_FORMAT_S || formato->format == CHAR_FORMAT_C) \
		&& formato->flag != MINUS_FLAG && formato->flag != POINT_FLAG)
		return (1);
	return (0);
}

int	print_str_frm(char *prtstr, t_form_data *formato)
{

	int		lenstr;
	int		out;
	char	*substr;

	out = 0;
	lenstr = (int) ft_strlen(str);
	if (ft_printf_suf_str (formato))
		out += print_extra_char (formato->longfield,0, ft_min(formato->prtstrlen, lenstr), ' ');
if (formato->ispoint && lenstr > formato->prtstrlen)
	{
		substr = ft_substr(str, 0, formato->prtstrlen);
		out += ft_print_str (substr);
		free (substr);
	}
	else
		out += ft_print_str (str);
	if (formato->flag == '-')
		out += print_extra_char (formato->longfield, 0, lenstr, ' ');
	return (out);
}