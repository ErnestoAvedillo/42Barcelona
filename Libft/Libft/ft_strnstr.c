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
#include<stddef.h>
#include<stdio.h>

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*first_char;

	i = 0;
	if (!little)
		return ((char *)(big));
	i = 0;
	while (i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			first_char = (char *)(big + i);
			while (big[i] == little[j] && big[i] && little[j])
			{
				i++;
				j++;
			}
			if (!little[j])
				return (first_char);
		}
		i++;
	}
	return (NULL);
}
