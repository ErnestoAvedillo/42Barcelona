/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:15:40 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 10:15:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static char	*get_min_pos(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
			return ((char *)str + i);
		i++;
	}
	return ((char *)str + ft_strlen(str));
}

static char	*get_max_pos(char const *str, char const *set)
{
	size_t	i;

	i = ft_strlen(str);
	while (i)
	{
		if (!ft_strrchr(set, str[i - 1]))
			return ((char *)str + i);
		i--;
	}
	return ((char *)str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ptr;

	start = get_min_pos(s1, set);
	end = get_max_pos(s1, set);
	if (!start || !end)
		return (NULL);
	if (start >= end)
		return (ft_strdup(""));
	ptr = ft_substr (s1, start - s1, end - start);
	return (ptr);
}
