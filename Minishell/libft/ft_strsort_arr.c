/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:03:58 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/16 12:04:04 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * Description:		Sorts an array of strings
 *
 * Arguments:		char **str
 * 					int	sense: 1- ascendent
 * 					int	sense: 0- descendant
 *
 * Returns:			char ** : sorted array
 *
 **/
char	**ft_strsort_arr(char **str, int sense)
{
	int		i;
	int		val;
	char	*aux;

	i = 0;
	while (str[++i])
	{
		val = ft_max(ft_strlen(str[i]), ft_strlen(str[i - 1]));
		val = ft_strncmp(str[i], str[i - 1], 0, val);
		if (sense == 0 && val > 0)
		{
			aux = str[i];
			str[i] = str[i - 1];
			str[i - 1] = aux;
			i = 0;
		}
		if (sense == 1 && val < 0)
		{
			aux = str[i];
			str[i] = str[i - 1];
			str[i - 1] = aux;
			i = 0;
		}
	}
	return (str);
}
