/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:10:29 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/07 17:31:29 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;	

static void	ft_rm_btw_quotes_1(char *str)
{
	int		i;
	bool	isquote;

	i = -1;
	isquote = false;
	while (str[++i])
	{
		if (str[i] == '\"')
			isquote = !isquote;
		while (str[i] && isquote)
		{
			ft_strrmchr(str, i);
			if (str[i] == '\"')
				isquote = !isquote;
		}
	}
}

static void	ft_rm_btw_quotes_2(char *str)
{
	int		i;
	bool	isquote;

	i = -1;
	isquote = false;
	while (str[++i])
	{
		if (str[i] == '\'')
			isquote = !isquote;
		while (str[i] && isquote)
		{
			ft_strrmchr(str, i);
			if (str[i] == '\'')
				isquote = !isquote;
		}
	}
}

int	check_syntax(t_data *data)
{
	char	**out;
	int		i;
	char	*aux;

	aux = ft_strdup(data->command);
	ft_strrmallchr(aux, ' ');
	ft_rm_btw_quotes_1(aux);
	ft_rm_btw_quotes_2(aux);
	out = ft_split(SNTX_258_ERR, ' ');
	i = -1;
	while (out[++i])
	{
		if (ft_strnstr(aux, out[i], ft_strlen(aux)))
		{
			print_err("Minishell: syntax error near unexpected token %s\n", \
				out[i] + ft_strlen(out[i]) - 1);
			g_out_status = 258;
			free_arrchar(out);
			free (aux);
			return (0);
		}
	}
	free (aux);
	free_arrchar(out);
	return (1);
}
