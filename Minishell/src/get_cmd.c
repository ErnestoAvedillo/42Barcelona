/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:04:21 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/24 09:04:29 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

/**
 *
 * Description:		Infinite while function with a readline(cmd_read) 
 * 						to introduce a command
 *					
 * Arguments:		NONE
 *					
 * Returns:			NONE
 **/
void	get_cmd(t_data *data)
{
	t_instruct	*frst_inst;

	while (1)
	{
		data->command = cmd_read("Enter a command Minishell> ");
		if (!data->command)
			break ;
		add_history(data->command);
		if (check_text(data))
		{
			frst_inst = tokenize(data);
			if (!frst_inst)
				print_err("Memory alloc. error\n");
			else if (data->execute)
				adm_redirections(frst_inst);
			free_inst(frst_inst);
			if (data->exit)
				break ;
		}
		else
		{
			free(data->command);
			data->command = NULL;
		}
	}
}
