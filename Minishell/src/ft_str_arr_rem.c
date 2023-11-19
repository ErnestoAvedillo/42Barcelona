/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_rem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:00:30 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/16 16:00:36 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 *
 * Description:		Adds a string ina an array of strings
 *					
 * Arguments:		charr **arr: The pointer to the array of a string
 * 					char *str:the pointer of the string to be added
 *					
 * Returns:			char** the new pointer to the string.
 **/
char	**ft_str_arr_rem(char **arr, int pos)
{
	int		i;
	char	**out;

	i = ft_len_str_arr(arr);
	out = (char **)malloc(i * sizeof(char *));
	if (!out)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		if (i < pos)
			out[i] = arr[i];
		else if (i == pos)
			free(arr[pos]);
		else
			out[i - 1] = arr[i];
	}
	out[i - 1] = NULL;
	free(arr);
	return (out);
}
