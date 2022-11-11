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

t_form_data *newdata ()
{
	t_form_data *ptr;

	ptr = (t_form_data *) malloc(sizeof(t_form_data));
	if (!ptr) 
		return (NULL);
	ptr->flag = NONE_FLAG;
	ptr->iszero = 0;
	ptr->longfield  = 0;
	ptr->format = NONE_FORMAT;
	ptr->cur_str_pos = 0;
	ptr->print_len = 0;
	return (ptr);
}

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

int	write_extended(char *str, t_form_data *formato)
{
	int	lenstr;
	int	out;
	char *substr;

	out = 0;
	lenstr = (int) ft_strlen(str);
	if (formato->flag == '+' || formato->flag == '.')
	{
		if (formato->format == 'd' || formato->format == 'i')
		{
			out += print_extra_char (formato->longfield, lenstr,'0');
			printf("impresos %d caracteres 1\n",out );
		}
		else if (formato->flag == '+')
		{
			out += print_extra_char (formato->longfield, lenstr,' ');
			printf("impresos %d caracteres \n",out );
		}
	}
	if (formato->flag == '.' && lenstr > formato->longfield)
	{
		substr = ft_substr(str,0, formato->longfield);
		out += ft_printf (substr);
		printf("impresos %d caracteres 2\n",out );
		free (substr);
	}
	else
	{
		out += ft_printf (str);
		printf("impresos %d caracteres 3\n",out );
	}
	if (formato->flag == '-')
	{
			out += print_extra_char (formato->longfield, lenstr,' ');
			printf("impresos %d caracteres 4\n",out );
	}
	return (out);
}
