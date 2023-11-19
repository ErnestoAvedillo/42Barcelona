/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:49:26 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/24 09:49:29 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 *
 * Description:		Replace all charachtes beteween quotes.
 *
 * Arguments:		char *str The string where to replace the spaces between 
 * 					quotes.
 *
 * Returns:			NONE
 **/
void	replace_char_btw_quotes(char *str, unsigned int c1, unsigned int c2)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (j == 0 && (str[i] == '\'' || str[i] == '\"'))
		{
			j = 1;
			if (str[i] == '\"')
				j = 2;
			str[i] = ' ';
		}
		while (j != 0)
		{
			i++;
			str[i] = replace_char(str[i], c1, c2);
			if ((j == 1 && str[i] == '\'') || (j == 2 && str[i] == '\"'))
			{
				str[i] = ' ';
				j = 0;
			}
		}
	}
}

/**
 *
 * Description:		Looks for the position of a char c excluding 
 * 					those which are between quotes.
 *					
 * Arguments:		char* where to look at
 *					char charachter to look for.
 * Returns:			int: >= 0 with the position of the charachterin the str
 * 							-1 if there is none.
 **/
int	check_is_redir(char *str, char c)
{
	int		pos;
	bool	quot[2];

	pos = -1;
	quot[1] = false;
	quot[0] = false;
	while (str[++pos])
	{
		if (str[pos] == '\'')
			quot[0] = !quot[0];
		if (str[pos] == '\"')
			quot[1] = !quot[1];
		if (str[pos] == c && !quot[0] && !quot[1])
			return (pos);
	}
	return (-1);
}

static char	*extract_all_out_err_fd(t_instruct *instr, char *str)
{
	char	*out[2];
	int		pos;

	out[0] = ft_strdup(str);
	pos = check_is_redir(out[0], '>');
	while (pos >= 0 && pos < (int)ft_strlen(out[0]))
	{
		if ((pos > 1 && out[0][pos - 1] == '2' && out[0][pos - 2] == ' ') || \
				(pos > 0 && out[0][pos - 1] == '2'))
			out[1] = ext_err_file(instr, (int)pos, out[0]);
		else
			out[1] = ext_out_file(instr, (int)pos, out[0]);
		free(out[0]);
		out[0] = out[1];
		pos = check_is_redir(out[0], '>');
	}
	free(str);
	return (out[0]);
}

static char	*extract_all_in_fd(t_instruct *instr, char *str)
{
	char	*out[2];
	int		pos;

	out[0] = ft_strdup(str);
	pos = check_is_redir(out[0], '<');
	while (pos >= 0 && pos < (int)ft_strlen(out[0]))
	{
		out[1] = ext_in_file(instr, (int)pos, out[0]);
		free(out[0]);
		out[0] = out[1];
		pos = check_is_redir(out[0], '<');
	}
	free(str);
	return (out[0]);
}

char	*check_ext_files(t_instruct *instr, char *str)
{
	char	*out;

	if (!str)
		return (str);
	out = extract_all_out_err_fd(instr, str);
	out = extract_all_in_fd(instr, out);
	return (out);
}
