/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:11:09 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/15 18:11:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);

	i = 0;
	while(i<n)
	{
		if (*(unsigned char*)(s1 + i) != *(unsigned char*)(s2))
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2));
		i++;
	}
	return(0);
}

