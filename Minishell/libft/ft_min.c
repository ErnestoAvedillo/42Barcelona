/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:37 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/22 17:32:25 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * Description:		Returns the minimum value of 2 lintegers.
 *					
 * Arguments:		int, int
 *					
 * Returns:			int. With the minimum value of both arguments.
 **/
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
