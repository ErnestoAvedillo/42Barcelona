/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adm_file_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:56:15 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/04 15:56:33 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	input_file_redir(t_fd_struc *in)
{
	if (!in)
		return (false);
	in->fd = open(in->fd_name, O_RDONLY, 0666);
	if (in->fd == -1)
	{
		print_err("Minishell:%s: No such file or directory\n", in->fd_name);
		return (false);
	}
	dup2(in->fd, STDIN_FILENO);
	close(in->fd);
	return (true);
}

bool	output_file_redir(t_fd_struc *out)
{
	if (!out)
		return (false);
	if (out->fd_type == 1)
		out->fd = open(out->fd_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (out->fd_type == 2)
		out->fd = open(out->fd_name, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (out->fd == -1)
	{
		print_err("Minishell:%s: No such file or directory\n", out->fd_name);
		return (false);
	}
	dup2(out->fd, STDOUT_FILENO);
	close(out->fd);
	return (true);
}

bool	output_error_file_redir(t_fd_struc *err)
{
	if (!err)
		return (false);
	if (err->fd_type == 1)
		err->fd = open(err->fd_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (err->fd_type == 2)
		err->fd = open(err->fd_name, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (err->fd == -1)
	{
		print_err("Minishell:%s: Error opening/creating file.\n", err->fd_name);
		return (false);
	}
	dup2(err->fd, STDERR_FILENO);
	close(err->fd);
	return (true);
}

bool	adm_file_redir(t_instruct *inst)
{
	bool		out;
	t_fd_struc	*redir;

	out = true;
	redir = inst->in;
	while (redir)
	{
		out = input_file_redir(redir);
		redir = redir->next;
	}
	redir = inst->out;
	while (redir)
	{
		out = output_file_redir(redir);
		redir = redir->next;
	}
	redir = inst->err;
	while (redir)
	{
		out = output_error_file_redir(redir);
		redir = redir->next;
	}
	return (out);
}
