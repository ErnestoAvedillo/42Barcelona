/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:55:29 by frmurcia          #+#    #+#             */
/*   Updated: 2023/09/01 18:04:08 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
/*****
 * Chequea si hay 2 errores consecutivos 
 * Si bool many_blocks == true, hay 2 hay que dar error
 * ****/

int	error_found(char *texto, int *i, int j, int *consecutive_errors)
{
	const char	*error_bl[] = {">|", "||", "|", "<<<", "<<", ">>", "<>",
		"<", ">"};
	int			block_length;

	block_length = ft_strlen(error_bl[j]);
	if (ft_strncmp_mod(&texto[*i], error_bl[j], block_length) == 0)
	{
		*i += block_length;
		(*consecutive_errors)++;
		if (*consecutive_errors == 2)
			return (1);
		return (2);
	}
	return (0);
}

bool	check_blocks(char *texto, int *i, int *consecutive_errors)
{
	int		j;
	int		k;

	j = 0;
	while (j < 9)
	{
		k = error_found(texto, i, j, consecutive_errors);
		while (texto[*i] && texto[*i] == ' ')
			(*i)++;
		if (texto[*i] != ' ' && texto[*i] != '<' && texto[*i] != '>'
			&& texto[*i] != '|')
		{
			*consecutive_errors = 0;
			if (texto[*i])
				(*i)++;
		}
		if (k == 1)
		{
			return (true);
		}
		else if (k == 2)
			j = -1;
		j++;
	}
	return (false);
}

bool	many_blocks(char *text)
{
	char	*texto;
	int		consecutive_errors;
	int		i;

	i = 0;
	consecutive_errors = 0;
	texto = ft_strdup(text);
	while (texto[i])
	{
		if (check_blocks(texto, &i, &consecutive_errors))
		{
			free(texto);
			return (true);
		}
		i++;
	}
	free(texto);
	return (false);
}
