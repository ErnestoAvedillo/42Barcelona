/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstralnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:16:14 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 23:52:04 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isstralnum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			return (1);
		i++;
	}
	return (0);
}
