/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:01:57 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:02:02 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*check_all_chars(char *str)
{
	int		i;
	char	*ptr;
	char	*aux;

	aux = ft_strdup("-/~^!=+*@{}#.$?");
	i = -1;
	while (aux[++i])
	{
		ptr = ft_strchr(str, 0, aux[i]);
		if (ptr != NULL && ptr < str + ft_strlen(str))
		{
			free (aux);
			return (ptr);
		}
	}
	free (aux);
	return (NULL);
}

static int	check_args(char *str)
{
	char	*ptr;

	ptr = check_all_chars(str);
	if (ptr != NULL && ptr < str + ft_strlen(str))
	{
		print_err("unset: %s: not a valid identifier\n", str);
		if (str[0] == '-')
			return (2);
		return (1);
	}
	return (0);
}

int	cmd_unset(t_instruct *instruct)
{
	int		i;
	int		out[2];

	out[0] = 0;
	out[1] = 0;
	i = 0;
	while (instruct->arg[++i])
	{
		out[0] = check_args(instruct->arg[i]);
		if (!out[1] && out[0])
			out[1] = out[0];
		if (!out[0] && unsetenv(instruct->arg[i]) == 0)
			instruct->header->env = \
				actualize_env(instruct->header->env, instruct->arg[i], 0);
	}
	return (out[1]);
}
