/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:11:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/16 19:31:33 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	if (!b)
		return (null);
	ptr = b;
	while (len--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (b);
}
