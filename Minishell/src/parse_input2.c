/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:49:50 by frmurcia          #+#    #+#             */
/*   Updated: 2023/09/01 19:25:40 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

bool	first_pipe(char *text)
{
	if (text[0] == '|')
	{
		if (text[1] && text[1] == '|')
			print_err("Minishell: syntax error near unexpected token `||'\n");
		else
			print_err("Minishell: syntax error near unexpected token `|'\n");
		g_out_status = 258;
		return (true);
	}
	else if (text[0] == '.' && text[1] == '\0')
	{
		print_err("Minishell: .: filename argument required \n");
		print_err(".: usage: . filename [arguments]\n");
		g_out_status = 2;
		return (true);
	}
	return (false);
}

bool	check_two_pipes(char *text)
{
	int		i;
	char	*two_pipes;

	i = 0;
	while (text[i])
	{
		if ((text[i] && text[i - 1] && text[i - 2]) && (text[i] == '|'
				&& text[i - 1] == ' ' && text[i - 2] == '|'))
		{
			two_pipes = (char *)malloc(sizeof(char) * 2);
			two_pipes[0] = '|';
			two_pipes[1] = '\0';
			print_err("Minishell: syntax error near unexpected token: `|'\n");
			free (two_pipes);
			g_out_status = 258;
			return (true);
		}
		else
			i++;
	}
	return (false);
}

int	new_line(void)
{
	print_err("Minishell: syntax error near unexpected token `newline'\n");
	g_out_status = 258;
	return (1);
}
