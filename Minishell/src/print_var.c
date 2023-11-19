/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:29:19 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/07 18:01:25 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <errno.h>

void	list_open_file_descriptors(void)
{
	int	max_fd;
	int	fd;

	max_fd = sysconf(_SC_OPEN_MAX);
	fd = 0;
	while (fd < max_fd)
	{
		if (fcntl(fd, F_GETFD) != -1 || errno != EBADF)
		{
			printf("File descriptor %d is open.\n", fd);
		}
		fd ++;
	}
}

void	print_args(char **arg)
{
	int	i;

	i = 0;
	if (arg != NULL)
	{
		while (arg[i])
		{
			printf (" argumento %i, vale-%s-\n", i, arg[i]);
			i++;
		}
	}
	return ;
}

void	print_inst(t_instruct *instructions)
{
	t_instruct	*inst;

	inst = instructions;
	while (inst)
	{
		print_args(inst->arg);
		printf ("comando %s\n", inst->arg[0]);
		if (inst->in)
			printf (" redirección in %i, vale-%s con fd %i-\n", \
				inst->in->fd_type, inst->in->fd_name, inst->in->fd);
		if (inst->out)
			printf (" redirección out %i, vale-%s con fd %i-\n", \
				inst->out->fd_type, inst->out->fd_name, inst->out->fd);
		printf("pipe fd 0 = %i -- pipe fd1 = %i\n", \
			inst->pipefd[0], inst->pipefd[1]);
		inst = inst->next;
	}
	list_open_file_descriptors();
}

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != NULL)
		++i;
	i = ft_len_str_arr(arr) - ft_min(i, 5);
	while (arr[i] != NULL)
	{
		ft_printf("%p -- %s\n", arr[i], arr[i]);
		++i;
	}
}
