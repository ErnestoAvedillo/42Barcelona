/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_add.c                                   :+:      :+:    :+:   */
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
char	**ft_str_arr_add(char **arr, char *str)
{
	int		i;
	char	**out;

	i = ft_len_str_arr(arr);
	out = (char **)malloc((i + 2) * sizeof(char *));
	if (!out)
		return (NULL);
	i = -1;
	while (arr[++i])
		out[i] = arr[i];
	out[i] = str;
	out[++i] = NULL;
	free(arr);
	return (out);
}
