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
#include<stddef.h>
#include"libft.h"

static size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;
	int		i;

	i = 0;
	start = (size_t)s1 + (size_t) ft_strlen(s1);
	while (set[i])
	{
		start = min (start, (size_t)ft_strchr (s1, set[i]));
		i++;
	}
	i = 0;
	end = (size_t)s1;
	while (set[i])
	{
		end = max (end, (size_t)ft_strrchr (s1, set[i]));
		i++;
	}
	if (!start || !end)
		return (NULL);
	ptr = ft_substr (s1, start - (size_t)s1 + 1, end - start - 1);
	return (ptr);
}
