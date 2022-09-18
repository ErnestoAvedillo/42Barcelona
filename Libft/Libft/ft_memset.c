/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:11:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/18 18:16:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	if (!b)
		return (NULL);
	ptr = b;
	while (len--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (b);
}
