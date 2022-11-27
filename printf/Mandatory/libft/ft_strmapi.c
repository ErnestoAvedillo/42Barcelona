/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:14:38 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 16:15:28 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	size_t	lenstr;

	lenstr = ft_strlen (s);
	str = (char *)malloc ((lenstr + 1) * sizeof (char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < lenstr)
	{
		str[i] = f (i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
