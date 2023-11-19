/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actualize_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:44:52 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/16 15:44:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 *
 * Description:		removes on element of the environment if exists.
 *
 * Arguments:		char **env: Pointer to teh env variable
 *					variable to be removed
 * Returns:			char **: with the new memeoyr position of the env.
 **/
char	**rem_elem_from_env(char **env, char *str)
{
	int		i;
	char	**out;

	out = env;
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], str, 0, ft_strlen(str)) == 0)
		{
			out = ft_str_arr_rem(env, i);
			return (out);
		}
	}
	return (out);
}

/**
 *
 * Description:		Retrieves the current position of the a variable.
 *
 * Arguments:		char **env: Pointer to the env variable
 *					variable to be found
 * Returns:			ini: pos of the variable in the env. 
 * 							Last position if was not found.
 **/
int	get_var_cur_pos(char **env, char *str)
{
	int		i;
	char	**out[2];
	int		cmp;

	i = -1;
	out[0] = ft_split(str, '=');
	while (out[0] && env[++i])
	{
		if (env[i])
		{
			out[1] = ft_split(env[i], '=');
			cmp = ft_strncmp(out[1][0], out[0][0], 0, ft_strlen(out[1][0]));
			free_arrchar(out[1]);
			if (!cmp)
				break ;
		}
	}
	free_arrchar(out[0]);
	return (i);
}

/**
 *
 * Description:		Actualizes the array of the environment variable.
 *
 * Arguments:		char **env: Pointer to the env variable
 *					variable to be added or removed
 *					int k : 0 indicating to remove
 *							1 indicating to add or modify
 *							2 indicating only modify if exists
 * Returns:			NONE.
 **/
char	**actualize_env(char **env, char *str, int k)
{
	int		pos;
	char	**out;
	char	*aux;

	pos = get_var_cur_pos(env, str);
	out = env;
	if (k == 0)
		out = rem_elem_from_env(env, str);
	else if (k != 0)
	{
		aux = ft_strdup(str);
		if (pos < ft_len_str_arr(out))
		{
			free(out[pos]);
			out[pos] = aux;
			return (out);
		}
		else if (k == 1)
			out = ft_str_arr_add(env, aux);
		else
			free(aux);
	}
	if (!out)
		print_err("Error while allocating a new env variable.\n");
	return (out);
}
