/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlwr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:11:09 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/03 01:20:34 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
**	Converts all uppercase letters in a string to lowercase.
*/
char	*ft_strlwr(char *str)
{
	int		i;
	char	*new_str;

	i = -1;
	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[++i])
		new_str[i] = ft_tolower(str[i]);
	new_str[i] = '\0';
	return (new_str);
}
