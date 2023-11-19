/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:15:53 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 10:16:59 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*   Descriptinon:	Extracts a substring of a string.
*   Arguments:		char const *s : the string to obtain the substr.
*					int start position where.
*					int len :length of hte string to extract.
*   Returns:		A pointer wher to find the string.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*ptr;
	unsigned int		i;

	i = (unsigned int)ft_strlen(s);
	if (start > i || i == 0)
		ptr = (char *)malloc (1 * sizeof(char));
	else if (len + start > i)
		ptr = (char *)malloc ((i - start + 1) * sizeof(char));
	else
		ptr = (char *)malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (start > (unsigned int)i)
		ptr[0] = '\0';
	else
	{
		i = 0;
		while (s[start + i] && i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
