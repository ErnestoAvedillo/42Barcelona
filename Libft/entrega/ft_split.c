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
		if (s[i] != c && i == 0)
		{
			rep++;
			i = ft_nextendpos (s, i, c);
		}
		else if (s[i] == c)
		{
			if (i > 0)
				rep++;
			i = ft_nextstartpos(s, i, c);
		}
		else
			i++;
	}
	return (rep);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		rep;
	int		i;
	size_t	j;
	size_t	k;

	if (ft_strlen(s) == 0)
		return ((char **)calloc (1, sizeof (size_t)));
	else
		rep = ft_nr_of_str (s, c);
	printf("devuelvo %d\n", rep);
	ptr = (char **)calloc (rep, sizeof (size_t));
	i = 0;
	j = 0;
	k = 0;
	while (i <= rep && rep)
	{
		j = ft_nextstartpos(s, k, c);
		k = ft_nextendpos (s, j, c);
		ptr[i] = ft_substr (s, j, k - j);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
