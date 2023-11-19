/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 08:46:25 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/10 08:46:28 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strrmstr(char *str, int start, int end)
{
	char	*out;
	int		i;
	int		k;

	if (!str || end < start)
		return (str);
	if (start < 0)
		start = 0;
	end = ft_min(end, ft_strlen(str));
	i = -1;
	k = 0;
	out = (char *)malloc((ft_strlen(str) + 1 - start + end) * sizeof(char));
	while (str[++i])
	{
		if (i < start || i >= end)
		{
			out[k] = str[i];
			k++;
		}
	}
	out[k] = '\0';
	return (out);
}
