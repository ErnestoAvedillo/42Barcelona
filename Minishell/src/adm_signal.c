/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adm_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:26:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/09/03 13:02:18 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

/*****
 * -1 para comando bloqueante - Pone ^C y termina el proceso
 * -2 para comando bloqueante dentro de comillas... - termina el proceso
 * -3 bloqueante dentro de redireccion - Pone >, termina el proceso
 *  else el resto
 * */
void	hndl_ctrl_c(int signal)
{
	(void)signal;
	if (g_out_status == -1)
	{
		printf("^C\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		g_out_status = 130;
	}
	else if (g_out_status == -2)
	{
		printf("\n");
		exit(1);
	}
	else
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_out_status = 1;
	}
}

void	hndl_ctrl_slash(int signal)
{
	(void)signal;
	if (g_out_status == -1)
	{
		ft_printf("^\\Quit: 3\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		g_out_status = 131;
	}
	else
		rl_redisplay();
}

void	adm_signals_readline(void)
{
	if (signal(SIGINT, hndl_ctrl_c) == SIG_ERR)
		exit (1);
	if (signal(SIGQUIT, hndl_ctrl_slash) == SIG_ERR)
		exit (1);
}

void	reset_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
