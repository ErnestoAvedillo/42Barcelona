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
#include<stddef.h>
#include"libft.h"

static int	ft_strnrchr(char const *s, char c)
{
	int	i;
	int	rep;

	rep = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			rep++;
		i++;
	}
	return (rep);
}

static size_t	ft_nextposchr(char const *s, size_t ini, char c)
{
	size_t	i;

	i = ini;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		rep;
	int		i;
	size_t	j;
	size_t	k;

	rep = ft_strnrchr (s, c);
	ptr = (char **)calloc (rep + 1, sizeof (size_t));
	i = 0;
	j = 0;
	k = ft_nextposchr (s, j, c);
	while (i <= rep)
	{
		ptr[i] = ft_substr (s, j, k - j);
		i++;
		j = k + 1;
		k = ft_nextposchr (s, j, c);
	}
	ptr[i] = 0;
	return (ptr);
}
