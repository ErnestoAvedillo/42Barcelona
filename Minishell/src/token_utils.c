/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:02:21 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:02:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static bool	check_qt_heredoc(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (false);
	}
	return (true);
}

/*
 *   Descriptinon:	Replace all charachtes of the string equal of c1 
 *					and replaces them from c2.
 *   Arguments:		char *str The variable to be splited.
 *   Returns:		Double pointer where to find the array.
 */
void	replace_char_in_str(char *str, unsigned int c1, unsigned int c2)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)c1)
			str[i] = c2;
}

char	*expand_home_dir(char *str)
{
	int		i;
	bool	quot[3];

	check_quotes(str, -1, quot);
	i = 0;
	while (str[i])
	{
		check_quotes (str, i, quot);
		if (str[i] == '~' && !quot[0] && !quot[1])
			str = repl_home_dir(str, i);
		i++;
	}
	return (str);
}

/**
 *
 * Description:		
 *					
 * Arguments:		
 *					
 * Returns:			
 **/
void	expand_redir(t_instruct *inst)
{
	t_fd_struc	*cur_fd;

	cur_fd = inst->out;
	while (cur_fd)
	{
		cur_fd->fd_name = expand_variables(cur_fd->fd_name);
		cur_fd->fd_name = process_quotes(cur_fd->fd_name);
		cur_fd = cur_fd->next;
	}
	cur_fd = inst->in;
	while (cur_fd)
	{
		if (cur_fd->fd_type == 1)
		{
			cur_fd->fd_name = expand_variables(cur_fd->fd_name);
			cur_fd->fd_name = process_quotes(cur_fd->fd_name);
		}
		else
		{
			cur_fd->expand = check_qt_heredoc(cur_fd->fd_name);
			ft_strrmallchr(cur_fd->fd_name, '\'');
			ft_strrmallchr(cur_fd->fd_name, '\"');
		}
		cur_fd = cur_fd->next;
	}
}

/*
*   Descriptinon:	Fill all data for the current instrucion.
*   Arguments:		t_instruct *inst : the variable to fill in.
*					char *str The variable where it is the instruction.
*					int start position where is t\starting the instruction
*					int end where the instruction ends.
*   Returns:		Nothing
*/
char	*fill_instruct2(t_instruct *inst, char *str)
{
	int	i;

	str = check_ext_files(inst, str);
	prepare_for_split(str);
	str = expand_home_dir(str);
	str = expand_variables(str);
	split_args(inst, str);
	i = -1;
	while (inst->arg[++i])
		inst->arg[i] = process_quotes(inst->arg[i]);
	expand_redir(inst);
	return (str);
}
