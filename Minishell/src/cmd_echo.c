/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:59:18 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 19:59:25 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	clean_n(char **str)
{
	int	i;
	int	j;

	if (!str[1])
		return (1);
	i = 1;
	while (str[i] && ft_strncmp(str[i], "-n", 0, 2) == 0)
	{
		j = 2;
		while (str[i][j])
		{
			if (str[i][j] != 'n')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	cmd_echo(t_instruct *instruct)
{
	int		i;
	bool	eol;

	eol = true;
	i = clean_n(instruct->arg);
	if (i > 1)
		eol = false;
	while (instruct->arg[i])
	{
		ft_printf ("%s", instruct->arg[i]);
		if (instruct->arg[i + 1])
			ft_printf(" ");
		i++;
	}
	if (eol)
		ft_printf ("\n");
	return (0);
}
