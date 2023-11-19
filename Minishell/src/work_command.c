/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:02:37 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:02:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

void	back_2_screen(t_instruct *instr)
{
	if (dup2(instr->header->my_stdin, STDIN_FILENO) == -1)
		print_err("error al devolver fd in a teclado\n");
	if (dup2(instr->header->my_stdout, STDOUT_FILENO) == -1)
		print_err("error al devolver fd out a pantalla \n");
	if (dup2(instr->header->my_stderr, STDERR_FILENO) == -1)
		print_err("error al devolver fd error a pantalla \n");
}

static int	exec_ext_cmd(t_instruct *instr)
{
	int	status;

	g_out_status = -1;
	instr->header->pid = fork();
	if (instr->header->pid == -1)
	{
		print_err("minishell: error while forking");
		g_out_status = 1;
		return (1);
	}
	else if (instr->header->pid == 0)
		cmd_exec(instr);
	wait(&status);
	if (g_out_status != 130 && g_out_status != 131)
		g_out_status = WEXITSTATUS(status);
	return (g_out_status);
}

static int	is_build_in_cmd(char *str1, char *str2)
{
	int	i;

	i = ft_strncmp(str1, str2, 0, ft_max(ft_strlen(str1), ft_strlen(str2)));
	return (i);
}

void	work_1_command(t_instruct *instr)
{
	int	i;

	i = -1;
	adm_file_redir(instr);
	if (instr->header->execute && instr->arg[0])
	{
		while (++i <= EXIT_CMD)
		{
			if (instr->arg[0] && !is_build_in_cmd(instr->arg[0], \
				instr->header->cmd_list[i]))
			{
				g_out_status = ((int (*)(t_instruct *)) \
						((void **)instr->header->functions_ptr)[i])(instr);
				back_2_screen(instr);
				return ;
			}
		}
		if (is_char_in_str(instr->arg[0], '='))
			g_out_status = cmd_setenv(instr);
		else
			g_out_status = exec_ext_cmd(instr);
	}
	back_2_screen(instr);
	return ;
}

void	work_command(t_instruct *instr)
{
	int	i;
	int	status;

	redirect(instr);
	i = -1;
	status = 0;
	if (instr->arg[0] == NULL)
		exit(0);
	while (++i <= EXIT_CMD)
	{
		if (instr->arg[0] && !is_build_in_cmd(instr->arg[0], \
				instr->header->cmd_list[i]))
		{
			status = ((int (*)(t_instruct *)) \
					((void **)instr->header->functions_ptr)[i])(instr);
			exit(status);
		}
	}
	if (is_char_in_str(instr->arg[0], '='))
		status = cmd_setenv(instr);
	else
		cmd_exec(instr);
	exit(status);
}
