/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:15:03 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 10:07:43 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (ft_strncmp((char *)little, "", 1) == 0)
		return ((char *)(big));
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			k = i;
			while (big[k] == little[j] && big[k] && little[j] && k < len)
			{
				k++;
				j++;
			}
			if (!little[j] && k <= len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
