/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:01:13 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:01:15 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 *
 * Description:		Checks that all arguments have the proper written terminology.
 *
 *
 * Arguments:		char *str: agument given to be checked
 *
 * Returns:			Boolean variable. True is sstructure OK. False is structure NOK
 **/
static char	*check_all_chars(char *str)
{
	int		i;
	char	*ptr;
	char	*aux[2];

	if (str[0] == '=' || str[0] == '?' || ft_isdigit(str[0]))
		return (str);
	aux[1] = ft_strchr(str, 0, '=');
	if (!aux[1])
		aux[1] = str + ft_strlen(str) + 1;
	aux[0] = ft_strdup("+.{}-#@!^~");
	i = 0;
	while (aux[0][i])
	{
		ptr = ft_strchr(str, 0, aux[0][i]);
		if (ptr != NULL && ptr < aux[1])
		{
			free (aux[0]);
			return (ptr);
		}
		i++;
	}
	free (aux[0]);
	return (NULL);
}

static int	check_args(char *str)
{
	char	*ptr;

	ptr = check_all_chars(str);
	if (ptr != NULL && ptr < str + ft_strlen(str))
	{
		print_err("export: %s: not a valid identifier\n", str);
		if (str[0] == '-')
			return (2);
		return (1);
	}
	return (0);
}

/**
 *
 * Description:		exports the variable when is given with the value. 
 * 					In this case when no value is given in the variable.
 *
 * Arguments:		t_instruct *instr The structure where to find  
 * 					instruction and arguments..
 * 					char *var, the string where to find the variable to be exported
 *
 * Returns:			NONE
 **/
static char	**exp_no_val(char *var, char **env)
{
	size_t	j;
	char	*value;
	char	**aux;

	aux = env;
	j = ft_strlen(var) + ft_strlen(getenv(var));
	value = (char *)malloc((j + 2) * sizeof(char));
	value[0] = '\0';
	ft_strlcat(value, var, j + 2);
	ft_strlcat(value, "=", j + 2);
	ft_strlcat(value, getenv(var), j + 2);
	if (putenv(value) == 0)
		aux = actualize_env(env, value, 1);
	free(value);
	return (aux);
}

/**
 * Description:		exports the variable when is given with the value.
 * 					In this case when the value is given in the variable.
 *
 * Arguments:		t_instruct *instr The structure where to find
 * 					instruction and arguments..
 * 					char *var, the string where to find the variable to be exported
 *
 * Returns:			NONE
 **/
static char	**exp_val(char *var, char **env)
{
	char	**out;
	char	*value;

	out = env;
	value = ft_strdup(var);
	if (putenv(value) == 0)
		out = actualize_env(env, var, 1);
	return (out);
}

/**
 *
 * Description:		Sets the variable to the designated value.
 *
 * Arguments:		t_instruct *instr The structure where to find  
 * 					instruction and arguments..
 *
 * Returns:			Integer with 1 in case there is not an error. 0 in case of error.
 **/
int	cmd_export(t_instruct *instr)
{
	int	i;
	int	out[2];

	if (!instr->arg || !instr->arg[1])
	{
		print_env_sorted(instr->header->env);
		return (0);
	}
	i = 0;
	out[0] = 0;
	out[1] = 0;
	while (instr->arg[++i])
	{
		out[0] = check_args(instr->arg[i]);
		if (!out[1] && out[0])
			out[1] = out[0];
		if (!out[0] && ft_strchr(instr->arg[i], 0, '=') == NULL )
			instr->header->env = exp_no_val(instr->arg[i], instr->header->env);
		else if (!out[0])
			instr->header->env = exp_val(instr->arg[i], instr->header->env);
	}
	return (out[0]);
}
