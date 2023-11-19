/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin_fd0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:28:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/21 18:28:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_fd_struc	*get_fd_in_address(t_instruct *instr)
{
	t_fd_struc	*new_fd;
	t_fd_struc	*cur_fd;

	new_fd = (t_fd_struc *)malloc(1 * sizeof(t_fd_struc));
	new_fd->next = NULL;
	cur_fd = instr->in;
	if (cur_fd != NULL)
	{
		while (cur_fd->next)
			cur_fd = cur_fd->next;
		cur_fd->next = new_fd;
	}
	else
		instr->in = new_fd;
	return (new_fd);
}

t_fd_struc	*get_fd_out_address(t_instruct *instr)
{
	t_fd_struc	*new_fd;
	t_fd_struc	*cur_fd;

	new_fd = (t_fd_struc *)malloc(1 * sizeof(t_fd_struc));
	new_fd->next = NULL;
	cur_fd = instr->out;
	if (cur_fd != NULL)
	{
		while (cur_fd->next)
			cur_fd = cur_fd->next;
		cur_fd->next = new_fd;
	}
	else
		instr->out = new_fd;
	return (new_fd);
}

t_fd_struc	*get_fd_err_address(t_instruct *instr)
{
	t_fd_struc	*new_fd;
	t_fd_struc	*cur_fd;

	new_fd = (t_fd_struc *)malloc(1 * sizeof(t_fd_struc));
	new_fd->next = NULL;
	cur_fd = instr->err;
	if (cur_fd != NULL)
	{
		while (cur_fd->next)
			cur_fd = cur_fd->next;
		cur_fd->next = new_fd;
	}
	else
		instr->err = new_fd;
	return (new_fd);
}
