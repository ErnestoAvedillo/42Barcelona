/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:13:16 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/23 21:54:44 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*   Descriptinon:	Finds the position of a char in a str.
*   Arguments:		char const *s : the string to work with.
*					int start position where.
*					int c :charachter to search.
*   Returns:		A pointer where to find the char.
*/
char	*ft_strchr(const char *s, int start, int c)
{
	int	i;

	i = start;
	while (s[i] && s[i] != (char)c)
		i++;
	if (!s[i] && (c % 256))
		return (NULL);
	else
		return ((char *)(s + i));
}
