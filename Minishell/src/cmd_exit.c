/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:00:54 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:00:57 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

static bool	check_is_num(t_instruct *inst)
{
	int	i;
	int	dig;

	dig = 0;
	i = 0;
	if (inst->arg[1])
		if (inst->arg[1][i] == '-' || inst->arg[1][i] == '+')
			i++;
	while (inst->arg[1] && inst->arg[1][i])
	{
		dig = ft_isdigit(inst->arg[1][i]);
		if (!dig)
		{
			print_err("exit: %s: numeric argument required\n", inst->arg[1]);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	check_args(t_instruct *inst)
{
	int	i;

	i = ft_len_str_arr(inst->arg);
	if (i > 2)
	{
		print_err("exit: too many arguments\n");
		return (false);
	}
	return (true);
}

int	cmd_exit(t_instruct *inst)
{
	if (!check_is_num(inst))
	{
		inst->header->exit = true;
		return (255);
	}
	if (!check_args(inst))
		return (1);
	else
		inst->header->exit = true;
	if (inst->arg[1])
		g_out_status = ft_atoi(inst->arg[1]) % 256;
	else
		return (0);
	if (g_out_status < 0)
		g_out_status -= 256;
	return (g_out_status);
}
