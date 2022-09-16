/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:11:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/16 19:58:31 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	i = 0;
	if (dst == src || !n)
		return (dst);
	while (n--)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
