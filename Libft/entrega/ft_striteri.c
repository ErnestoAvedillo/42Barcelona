/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:13:33 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 16:15:00 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	lenstr;

	lenstr = ft_strlen (s);
	if (!s)
		return ;
	i = 0;
	while (i <= lenstr - 1 && s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
	return ;
}
