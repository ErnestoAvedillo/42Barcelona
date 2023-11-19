/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leninstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:45:21 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/26 06:45:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	leninstr(t_instruct *list_instr)
{
	int	out;

	if (!list_instr)
		return (0);
	out = 0;
	while (list_instr)
	{
		out++;
		list_instr = list_instr->next;
	}
	return (out);
}
