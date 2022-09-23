/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:13:33 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/23 21:59:30 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	size_t	lenstr;

	lenstr = ft_lenste (s);
	if (!s)
		return (s);
	i = 0;
	while (i <= lenstr)
	{
		f (i, s[i]);
		i++;
	}
	return (str);
}
