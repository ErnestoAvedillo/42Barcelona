/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:24:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/22 17:31:52 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * Description:		Returns the max value of 2 integers.
 *					
 * Arguments:		int, int
 *					
 * Returns:			int: The max vaue of both arguments
 **/
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
