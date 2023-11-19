/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:46:18 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/11 22:46:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*replace_command(char *str, char *variable, char *value, int pos)
{
	int		j;
	int		lenstrout;
	char	*out;

	lenstrout = (int)(ft_strlen(str) - ft_strlen(variable) + ft_strlen(value));
	out = (char *) malloc((lenstrout + 1) * sizeof(char));
	j = -1;
	while (++j < lenstrout)
	{
		if (j < pos)
			out[j] = str[j];
		else if (j >= pos + (int)ft_strlen(value))
			out[j] = str[j + (int)(ft_strlen(variable) - ft_strlen(value))];
		else if (value)
			out[j] = value[j - pos];
	}
	out[j] = '\0';
	free(str);
	return (out);
}

char	*replace_env_var(char *str, int pos, int status)
{
	char	*var_val[3];
	char	*aux;

	var_val[0] = get_var_name(str, pos);
	var_val[1] = ft_substr(var_val[0], 1, ft_strlen(var_val[0]) - 1);
	if (str[pos + 1] == '?')
		var_val[2] = ft_itoa(status);
	else if (str[pos + 1] == '0')
		var_val[2] = ft_strdup("minishell");
	else
	{
		aux = getenv(var_val[1]);
		if (!aux)
			var_val[2] = ft_strdup("");
		else
			var_val[2] = ft_strdup(getenv(var_val[1]));
	}
	str = replace_command(str, var_val[0], var_val[2], pos);
	free(var_val[0]);
	free(var_val[1]);
	if (var_val[2])
		free(var_val[2]);
	return (str);
}

char	*repl_home_dir(char *str, int pos)
{
	char	*var_val[2];

	if ((str[pos + 1] == ' ' || str[pos + 1] == '\0' || str[pos + 1] == '/'))
	{
		var_val[0] = ft_strdup("~");
		var_val[1] = ft_strdup(getenv("HOME"));
		if (!var_val[1])
			var_val[1] = ft_strdup("");
		str = replace_command(str, var_val[0], var_val[1], pos);
		free(var_val[0]);
		free(var_val[1]);
	}
	return (str);
}

char	*repl_old_dir(char *str)
{
	char	*var_val[2];

	var_val[0] = ft_strdup("-");
	var_val[1] = ft_strdup(getenv("OLDPWD"));
	if (!var_val[1])
	{
		free(var_val[0]);
		return (NULL);
	}
	str = replace_command(str, var_val[0], var_val[1], 0);
	free(var_val[0]);
	free(var_val[1]);
	return (str);
}
