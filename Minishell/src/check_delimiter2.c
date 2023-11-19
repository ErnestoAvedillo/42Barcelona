/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_delimiter2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:54:53 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/07 19:54:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	actualize_fdname(t_instruct *instr, char *str)
{
	free(instr->in->fd_name);
	instr->in->fd_name = ft_strjoin("/tmp/tmp", str);
	instr->in->fd = open(instr->in->fd_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	return ;
}
