/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin_fd1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:28:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/21 18:28:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ext_out_file(t_instruct *instr, int start, char *str)
{
	char		*aux;
	int			end;
	int			pos;
	t_fd_struc	*new_fd;

	new_fd = get_fd_out_address(instr);
	pos = 0;
	if (str[start] == '>' && str[start + 1] == '>')
		new_fd->fd_type = 2;
	else
		new_fd->fd_type = 1;
	pos += new_fd->fd_type;
	while (str[start + pos] == ' ')
		pos++;
	end = pos;
	while (str[start + end] && str[start + end] != ' ' \
			&& str[start + end] != '>' && str[start + end] != '<' \
			&& str[start + end] != '|')
		end++;
	new_fd->fd_name = ft_substr(str, start + pos, end - pos);
	aux = ft_strrmstr(str, start, start + end);
	return (aux);
}

char	*ext_err_file(t_instruct *instr, int start, char *str)
{
	char		*aux;
	int			end;
	int			pos;
	t_fd_struc	*new_fd;

	new_fd = get_fd_err_address(instr);
	pos = 0;
	if (str[start] == '>' && str[start + 1] == '>')
		new_fd->fd_type = 2;
	else
		new_fd->fd_type = 1;
	pos += new_fd->fd_type;
	while (str[start + pos] == ' ')
		pos++;
	end = pos;
	while (str[start + end] && str[start + end] != ' ' \
		&& str[start + end] != '>' && str[start + end] != '<' \
		&& str[start + end] != '|')
		end++;
	new_fd->fd_name = ft_substr(str, start + pos, end - pos);
	aux = ft_strrmstr(str, start - 1, start + end);
	return (aux);
}

char	*ext_in_file(t_instruct *instr, int start, char *str)
{
	char		*aux;
	int			end;
	int			pos;
	t_fd_struc	*new_fd;

	new_fd = get_fd_in_address(instr);
	pos = 0;
	if (str[start] == '<' && str[start + 1] == '<')
		new_fd->fd_type = 2;
	else
		new_fd->fd_type = 1;
	pos += new_fd->fd_type;
	while (str[start + pos] == ' ')
		pos++;
	end = pos;
	while (str[start + end] && str[start + end] != ' ' \
			&& str[start + end] != '|' && str[start + end] != '>')
		end++;
	new_fd->fd_name = ft_substr(str, start + pos, end - pos);
	aux = ft_strrmstr(str, start, start + end);
	return (aux);
}
