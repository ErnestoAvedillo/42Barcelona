/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_str_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:47:42 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/16 12:47:45 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * Description:		creates a duplicate of an array ofstrings
 *					
 * Arguments:		char **str. Array to be duplicate
 *					
 * Returns:			char **. Creates a new array using malloc.
 **/
char	**ft_cpy_str_arr(char **str)
{
	int		i;
	char	**aux;

	if (!str)
		return (NULL);
	i = ft_len_str_arr(str);
	aux = (char **)malloc((i + 1) * sizeof(char *));
	if (!aux)
		return (NULL);
	aux[i] = NULL;
	i = -1;
	while (str[++i])
	{
		aux[i] = ft_strdup(str[i]);
	}
	return (aux);
}
