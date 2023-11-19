/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:13:04 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/23 21:53:28 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static size_t	ft_nextendpos(char const *s, size_t ini, char c)
{
	size_t	i;
	bool	quote[2];

	i = ini;
	quote[0] = false;
	quote[1] = false;
	if (s[i] == '\"')
		quote[1] = true;
	if (s[i] == '\'')
		quote[0] = true;
	while (s[i])
	{
		if (s[i] == c && !quote[0] && !quote[1])
			return (i);
		i++;
		if (s[i] == '\"')
			quote[1] = !quote[1];
		if (s[i] == '\'')
			quote[0] = !quote[0];
	}
	return (i);
}

static int	ft_nr_words(char const *s, char c)
{
	int		i;
	int		rep;
	bool	quote[2];

	rep = 0;
	i = 0;
	quote[0] = false;
	quote[1] = false;
	while (s && s[i])
	{
		if (i == 0)
		{
			if (s[i] != c)
				rep++;
		}
		else
			if (s[i - 1] == c && s[i] != c && !quote[0] && !quote[1])
				rep++;
		if (s[i] == '\"')
			quote[1] = !quote[1];
		if (s[i] == '\'')
			quote[0] = !quote[0];
		i++;
	}
	return (rep);
}

static char	**free_split(char **ptr, int i)
{
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

char	**ft_split_instr(char const *s, char c)
{
	char	**ptr;
	int		rep;
	int		i;
	size_t	j;
	size_t	k;

	rep = ft_nr_words(s, c);
	ptr = (char **)malloc ((rep + 1) * sizeof (char *));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (i < rep && rep)
	{
		k = ft_nextendpos (s, j, c);
		ptr[i] = ft_substr (s, j, k - j);
		if (!ptr[i])
			return (free_split (ptr, i));
		j = k + 1;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
