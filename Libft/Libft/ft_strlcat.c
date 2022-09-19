/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:13:57 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/15 18:14:02 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include"libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t lendst;


	lendst = ft_strlen(dst);
	if (!src || !size)
		return (lendst);
	i = 0;
	while (i < size-1 && src[i])
	{
		*(char*)(dst + lendst + i) = *(char*)(src + i);
		i++;
	}
	*(char*)(dst + lendst + i) = '\0';
	while(src[i])
		i++;
	return (lendst + i);
}