/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:11:26 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/16 20:38:41 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	if (!dst || !src)
		return (NULL);
	if (dst == src || !n)
		return (dst);
	if (ptr_dst > ptr_src)
	{
		i = len - 1;
		while (i >= 0)
		{
			ptr_dst[i] = ptr_src[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
