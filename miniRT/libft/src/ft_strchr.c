/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:20:04 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/21 00:58:25 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	len;
	char	find;

	find = (char)c;
	str = (char *)s;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (len + 1 > 0)
	{
		if (*str == find)
			return (str);
		str++;
		len--;
	}
	return (NULL);
}
