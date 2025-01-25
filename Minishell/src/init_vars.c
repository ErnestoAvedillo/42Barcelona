/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:18:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:18:47 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	set_func_list(t_data *data)
{
	data->functions_ptr = (void **) malloc ((EXIT_CMD + 1) * sizeof(void *));
	data->functions_ptr[ECHO_CMD] = cmd_echo;
	data->functions_ptr[CD_CMD] = cmd_cd;
	data->functions_ptr[PWD_CMD] = cmd_pwd;
	data->functions_ptr[EXPORT_CMD] = cmd_export;
	data->functions_ptr[UNSET_CMD] = cmd_unset;
	data->functions_ptr[ENV_CMD] = cmd_env;
	data->functions_ptr[EXIT_CMD] = cmd_exit;
}

t_data	*init_vars(char **env)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof (t_data));
	data->cmd_list = ft_split(COMMANDS, ' ');
	data->oper_list = ft_split(OPERANDS, ' ');
	data->env = ft_cpy_str_arr(env);
	data->command = NULL;
	data->contador = 0;
	data->my_stdin = dup(STDIN_FILENO);
	data->my_stdout = dup(STDOUT_FILENO);
	data->my_stderr = dup(STDERR_FILENO);
	data->exit = false;
	data->pid = 0;
	set_func_list(data);
	return (data);
}

t_instruct	*init_instructions(t_data *data)
{
	t_instruct	*first_inst;

	first_inst = (t_instruct *) malloc (sizeof(t_instruct));
	first_inst->header = data;
	first_inst->prev = NULL;
	first_inst->next = NULL;
	first_inst->pre_oper = NULL;
	first_inst->post_oper = NULL;
	first_inst->arg = NULL;
	first_inst->out = NULL;
	first_inst->in = NULL;
	first_inst->err = NULL;
	return (first_inst);
}

void	save_signals_status(t_data *header)
{
	(void)header;
	if (signal(SIGTERM, SIG_IGN) == SIG_ERR)
		exit (1);
	if (tcgetattr(STDIN_FILENO, &header->term) == -1)
		exit(1);
	header->term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &header->term) == -1)
		exit(1);
}
