/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:33:07 by frmurcia          #+#    #+#             */
/*   Updated: 2023/08/30 17:14:07 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Free quotes y free spaces
 * Crea una copia del input, quita quotes y libera espacios, tabuladores
 * parse_input1.c
 *
 * ***/
char	*free_spaces(char *data)
{
	int		i;
	int		o;
	char	*free_spaces;

	i = 0;
	o = 0;
	free_spaces = malloc(sizeof(char) * (ft_strlen(data) + 1));
	if (free_spaces == NULL)
		return (NULL);
	while (data[i])
	{
		if (data[i] == ' ' || data[i] == '\t')
		{
			while (data[i] == ' ' || data[i] == '\t')
				i++;
		}
		else
		{
			if (o > 0 && (data[i - 1] == ' ' || data[i - 1] == '\t'))
				free_spaces[o++] = ' ';
			free_spaces[o++] = data[i++];
		}
	}
	free_spaces[o] = '\0';
	return (free_spaces);
}

char	*proc_quotes(char *f_spaces, char *p_quot, int i)
{
	int		o;
	char	quot;
	bool	quoted;

	o = 0;
	quoted = false;
	while (f_spaces[i])
	{
		if (is_quote(f_spaces[i]))
		{
			quoted = !quoted;
			if (quoted)
			{
				quot = f_spaces[i];
				p_quot[o++] = 0xff;
			}
			i++;
		}
		else if (!is_quote(f_spaces[i]) && !quoted)
			p_quot[o++] = f_spaces[i++];
		else if (!is_quote(f_spaces[i]) && quoted)
			i++;
	}
	p_quot[o] = '\0';
	return (p_quot);
}

char	*free_quotes(char *data)
{
	char	*f_spaces;
	char	*f_quotes;
	char	*p_quotes;
	int		i;

	i = 0;
	p_quotes = malloc(sizeof(char) * (ft_strlen(f_spaces)) + 1);
	if (!p_quotes)
		return (NULL);
	f_spaces = free_spaces(data);
	f_quotes = proc_quotes(f_spaces, p_quotes, i);
	free(f_spaces);
	return (f_quotes);
}
