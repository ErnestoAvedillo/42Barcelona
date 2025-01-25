/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:00:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

int	cmd_env(t_instruct *instruct)
{
	char	buffer[1024];
	char	*curdir;
	char	**ptr;

	if (instruct->arg[1])
	{
		if (!ft_strncmp(instruct->arg[1], "PWD", 0, 3))
		{
			curdir = getcwd(buffer, sizeof(buffer));
			ft_printf("%s\n", curdir);
		}
		else
		{
			g_out_status = 127;
			ft_printf("Too many arguments env.\n");
		}
		return (1);
	}
	ptr = instruct->header->env;
	while (*ptr != NULL)
	{
		ft_printf("%s\n", *ptr);
		ptr++;
	}
	return (0);
}
