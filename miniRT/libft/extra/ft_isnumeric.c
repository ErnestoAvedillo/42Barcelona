/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:11:27 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/03 01:18:01 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
Check if a string is completely numeric
*/
int	ft_isnumeric(char *str)
{
	int		i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[0] == ' ')
		str++;
	if (str[0] == '-' || str[0] == '+')
		str++;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
