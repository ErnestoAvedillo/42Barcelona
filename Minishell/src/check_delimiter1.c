/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_delimiter1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:54:53 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/07 19:54:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

char	*get_start_delimit(char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ')
		i++;
	return (str + i);
}

char	*get_end_delimit(char *str)
{
	int		i;
	char	*aux;

	i = 0;
	aux = get_start_delimit(str);
	while (aux[i] && aux[i] != ' ' && aux[i] != '|' && aux[i] != '>')
		i++;
	return ((char *)aux + i);
}

static bool	end_of_heredoc(char *str1, char *str2)
{
	int	i;

	i = ft_max(ft_strlen(str1), ft_strlen(str2));
	if (!ft_strncmp(str1, str2, 0, i))
		return (false);
	return (true);
}

void	fill_heredoc(t_instruct *instr, char **delimit)
{
	char	*out;

	g_out_status = -2;
	adm_signals_readline();
	out = cmd_read(delimit[2]);
	while (out && end_of_heredoc(out, delimit[1]))
	{
		if (instr->in->expand)
			out = expand_variables(out);
		ft_putstr_fd(out, instr->in->fd);
		ft_putstr_fd("\n", instr->in->fd);
		free(out);
		out = cmd_read(delimit[2]);
	}
	exit(0);
}

char	*insert_in_line(char *cmd, char *str, char *ptr)
{
	char	*out;
	char	*aux;

	out = ft_substr(cmd, 0, (size_t)(ptr - cmd));
	out = concat_cmd(out, str);
	aux = ft_strdup(get_end_delimit(ptr));
	out = concat_cmd(out, aux);
	free(cmd);
	return (out);
}
