/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:10:29 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/07 17:31:29 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

static int	print_redir_nl(void)
{
	print_err("Minishell: syntax error near unexpected token 'newline'\n");
	g_out_status = 258;
	return (0);
}

static int	print_redir_tok(char c)
{
	print_err("Minishell: syntax error near unexpected token '%c'\n", c);
	g_out_status = 258;
	return (0);
}

int	check_redir(t_data *data)
{
	int		i;
	bool	blank;

	blank = false;
	i = -1;
	while (data->command[++i])
	{
		if (data->command[i] == '>' || data->command[i] == '<')
		{
			if (data->command[i + 1] == '\0')
				return (print_redir_nl());
			while (data->command[++i] == ' ')
				if (!blank)
					blank = !blank;
		}
		if ((data->command[i] == '>' || data->command[i] == '<') && blank)
			return (print_redir_tok(data->command[i]));
	}
	return (1);
}
