/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:13:04 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/23 21:53:28 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_nextstartpos(char const *s, size_t ini, char c)
{
	size_t	i;

	i = ini;
	while (s[i] == c && s[i])
	{
		i++;
	}
	return (i);
}

static size_t	ft_nextendpos(char const *s, size_t ini, char c)
{
	size_t	i;

	i = ini;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

static int	ft_nr_of_str(char const *s, char c)
{
	int	i;
	int	rep;

	rep = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0)
		{
			if (s[i] != c)
				rep++;
		}
		else
		{
			if (s[i - 1] == c && s[i] != c)
				rep++;
		}
		i++;
	}
	return (rep);
}

char	**free_split(char **ptr, int i)
{
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		rep;
	int		i;
	size_t	j;
	size_t	k;

	rep = ft_nr_of_str (s, c);
	ptr = (char **)malloc ((rep + 1) * sizeof (char *));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (i < rep && rep)
	{
		j = ft_nextstartpos(s, k, c);
		k = ft_nextendpos (s, j, c);
		ptr[i] = ft_substr (s, j, k - j);
		if (!ptr[i])
			return (free_split (ptr, i));
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
