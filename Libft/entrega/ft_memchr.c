/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:10:59 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/23 21:39:52 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include<stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)(c))
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
