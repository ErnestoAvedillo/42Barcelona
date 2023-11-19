/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:01:36 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:01:39 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

/*
 *   Descriptinon:	Checks the syntaxis of the instruction.
 *   Arguments:		char *str The instruction
 *
 *   Returns:		int 1 if true
 * 					int 0 if false.
 */
static int	syntax_error(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!is_char_in_str(str[i], '='))
		{
			print_err("Command not found.\n");
			g_out_status = 127;
			return (g_out_status);
		}
	}
	return (0);
}

/*
 *   Descriptinon:	Removes the value part of the variable to be set.
 *   Arguments:		char *str The assignement str.  
 *   Returns:		char * Str with the name of the variable.
 */
static char	*rm_value(char *str)
{
	char	*out;
	int		i;

	out = ft_strdup(str);
	i = -1;
	while (out[++i])
	{
		if (out[i] == '=')
		{
			out[i] = '\0';
			break ;
		}
	}
	return (out);
}

/*
 *   Descriptinon:	Sets the variable to the designated value.
 *   Arguments:		t_instr *instr The structure where to find  
 * 					instruction and arguments..
 *   Returns:		1 .
 */
int	cmd_setenv(t_instruct *instr)
{
	int		i;
	char	*str[2];
	char	*aux;

	if (syntax_error(instr->arg))
		return (127);
	aux = ft_strdup(instr->arg[0]);
	i = 0;
	while (aux)
	{
		str[1] = ft_strdup(ft_strchr(aux, 0, '=') + 1);
		str[0] = rm_value(aux);
		if (setenv(str[0], str[1], 1) == 0)
			instr->header->env = actualize_env(instr->header->env, aux, 2);
		free(aux);
		i++;
		free(str[0]);
		free(str[1]);
		aux = ft_strdup(instr->arg[i]);
	}
	free(aux);
	return (0);
}
