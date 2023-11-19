/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:01:36 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:01:39 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

char	*cmd_read(char *str)
{
	char	*line;
	char	*out;

	adm_signals_readline();
	if (isatty(fileno(stdin)))
		out = readline(str);
	else
	{
		line = get_next_line(fileno(stdin));
		out = ft_strtrim(line, "\n");
		free(line);
	}
	return (out);
}
