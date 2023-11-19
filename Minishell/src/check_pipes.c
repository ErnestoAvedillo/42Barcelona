/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:59:18 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 19:59:25 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

int	check_pipes(t_data *data)
{
	int	i;

	if (data->command[0] == '|')
	{
		print_err("Minishell: syntax error near unexpected token '|'\n");
		g_out_status = 258;
		return (0);
	}
	i = -1;
	while (data->command[++i])
	{
		if (data->command[i] == '|' && data->command[i + 1] != '|')
		{
			while (data->command[++i] == ' ')
				;
			if (data->command[i] == '|')
			{
				print_err("Minishell: syntax e rror near \
					unexpected token '|'\n");
				g_out_status = 258;
				return (0);
			}
		}
	}
	return (1);
}
