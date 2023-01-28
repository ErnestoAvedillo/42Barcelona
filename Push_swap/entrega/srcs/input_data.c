/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:12:05 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/13 16:12:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_empty(char **ac)
{
	int		i;
	int		k;

	i = 0;
	while (ac[++i])
		if (ac[i][0] == '\0')
			return (0);
	i = 0;
	k = 0;
	while (ac[++i])
		k += ft_strlen(ac[i]) + 1;
	return (k);
}

char	**input_data(char **ac)
{
	char	**str_out;
	char	*str_aux;
	int		i;
	int		j;
	int		k;

	k = check_empty(ac);
	if (!k)
		return (NULL);
	str_aux = (char *)malloc ((k + 1) * sizeof(char));
	i = 0;
	k = 0;
	while (ac[++i])
	{
		j = 0;
		while (ac[i][j])
			str_aux[k++] = ac[i][j++];
		str_aux[k++] = ' ';
	}
	str_aux[k] = '\0';
	str_out = ft_split(str_aux, ' ');
	free (str_aux);
	return (str_out);
}

int	len_array(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}
