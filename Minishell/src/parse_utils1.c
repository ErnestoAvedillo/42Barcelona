/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:34:59 by frmurcia          #+#    #+#             */
/*   Updated: 2023/08/30 17:28:56 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	is_redir(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (true);
	return (false);
}
/*
bool is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (true);
	return (false);
}*/

bool	final_redir(const char *text)
{
	int		length;
	char	last_char;
	char	penul_char;

	length = ft_strlen(text);
	if (length == 0)
		return (false);
	last_char = text[length - 1];
	penul_char = text[length - 2];
	if (last_char == '<' || last_char == '>')
		return (true);
	else if (last_char == '|' && is_redir(penul_char))
		return (true);
	return (false);
}

int	ft_strncmp_mod(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while (s1[counter] != '\0' && s2[counter] != '\0' && counter < n)
	{
		if ((unsigned char)s1[counter] != (unsigned char)s2[counter])
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		counter++;
	}
	if ((s1[counter] != s2[counter]) && counter < n)
		return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
