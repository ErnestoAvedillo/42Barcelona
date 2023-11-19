/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:02:21 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:02:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

void	check_quotes(char *str, int pos, bool *quot)
{
	if (pos == -1)
	{
		quot[0] = 0;
		quot[1] = 0;
		quot[2] = 0;
		return ;
	}
	if (!quot[1] && str[pos] == '\'')
		quot[0] = !quot[0];
	else if (!quot[0] && str[pos] == '\"')
		quot[1] = !quot[1];
	if (str[pos] == '\\' && (str[pos + 1] == '\\' || str[pos + 1] == '$'))
		quot[2] = !quot[2];
	else if (pos > 0 && str[pos] != '$' && str[pos - 1] != '\\')
		quot[2] = false;
}

/* Parte de fill_instruct */
char	*process_quotes(char *str)
{
	bool	quot[3];
	int		i;

	check_quotes(str, -1, quot);
	i = 0;
	while (i <= (int)ft_strlen(str))
	{
		check_quotes(str, i, quot);
		if (str[i] == '\\' && !quot[1] && !quot[0])
			ft_strrmchr(str, i);
		else if ((!quot[1] && str[i] == '\'') || (!quot[0] && str[i] == '\"'))
		{
			ft_strrmchr(str, i);
			i--;
		}
		i++;
	}
	return (str);
}

void	prepare_for_split(char *str)
{
	bool	quot[3];
	int		i;

	check_quotes(str, -1, quot);
	i = 0;
	while (str[i])
	{
		check_quotes(str, i, quot);
		if (str[i] == '\t')
			str[i] = ' ';
		if ((quot[0] && str[i] == ' ') || (quot[1] && str[i] == ' '))
			str[i] = (char)0xff;
		i++;
	}
}

/* Parte de fill_instruct */
void	split_args(t_instruct *inst, char *str)
{
	int	j;
	int	i;

	j = -1;
	inst->arg = ft_split(str, ' ');
	while (inst->arg[++j])
	{
		i = -1;
		while (inst->arg[j][++i])
			if (inst->arg[j][i] == (char)0xff)
				inst->arg[j][i] = ' ';
	}
	i = -1;
}

/* Parte de fill_instruct */
char	*expand_variables(char *str)
{
	int		i;
	bool	quot[3];

	check_quotes(str, -1, quot);
	i = -1;
	while (str[++i])
	{
		check_quotes (str, i, quot);
		if ((str[i] == '$' && str[i + 1] == '\'' && !quot[0]) \
			|| (str[i] == '$' && str[i + 1] == '\"' && !quot[1]))
		{
			ft_strrmchr(str, i);
			i--;
		}
		else if (str[i] == '$' && ((str[i + 1] == '\"' && quot[1]) \
				|| str[i + 1] == '\0' || str[i + 1] == (char)0xff \
				|| (str[i + 1] == '\'' && quot[0]) || (str[i + 1] == '/')))
			;
		else if (str[i] == '$' && !quot[0] && !quot[2])
		{
			str = replace_env_var(str, i, g_out_status);
			i--;
		}
	}
	return (str);
}
