/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adm_redirections1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:37:37 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/26 06:37:39 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	redirect_first(t_instruct *cur_inst)
{
	close(cur_inst->pipefd[0]);
	input_file_redir(cur_inst->in);
	if (!output_file_redir(cur_inst->out))
		dup2(cur_inst->pipefd[1], STDOUT_FILENO);
	close(cur_inst->pipefd[1]);
}

void	redirect_middle(t_instruct *cur_inst, t_instruct *instr_pre)
{
	if (!input_file_redir(cur_inst->in))
		dup2(instr_pre->pipefd[0], STDIN_FILENO);
	close(cur_inst->pipefd[0]);
	close(instr_pre->pipefd[0]);
	if (!output_file_redir(cur_inst->out))
		dup2(cur_inst->pipefd[1], STDOUT_FILENO);
	close(cur_inst->pipefd[1]);
	close(cur_inst->pipefd[1]);
}

void	redirect_last(t_instruct *cur_inst, t_instruct *instr_pre)
{
	if (!input_file_redir(cur_inst->in))
		dup2(instr_pre->pipefd[0], STDIN_FILENO);
	close(instr_pre->pipefd[0]);
	output_file_redir(cur_inst->out);
	close(instr_pre->pipefd[0]);
}

void	redirect(t_instruct *cur_inst)
{
	t_instruct	*instr_pre;

	instr_pre = cur_inst->prev;
	output_error_file_redir(cur_inst->err);
	if ((cur_inst->prev == NULL) && (cur_inst->next != NULL))
		redirect_first (cur_inst);
	else if ((cur_inst->prev != NULL) && (cur_inst->next != NULL))
		redirect_middle (cur_inst, instr_pre);
	else if ((cur_inst->prev != NULL) && (cur_inst->next == NULL))
		redirect_last (cur_inst, instr_pre);
}
