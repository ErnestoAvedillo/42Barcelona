/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_str_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:37:51 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/16 12:37:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * Description:		Returns he len of an array. Array miust finish with a NULL 
 * element
 *					
 * Arguments:		char **str: array of strings.
 *					
 * Returns:			int: len of the array.
 **/
int	ft_len_str_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
