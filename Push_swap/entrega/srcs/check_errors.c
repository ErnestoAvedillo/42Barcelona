/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:46:13 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 17:46:18 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

	/* tabla de verdad para out of limits.
	strlen	j	comp	result
	=10		0	> 0		true
	>10		0	*		true
	=11		1	>0		true
	>11		1	*		true
	*/
int	chk_out_of_lim(char *str)
{
	int		j;
	char	*mysubstr;
	int		strlen;
	int		compstr;

	j = 0;
	if (str[0] == '-')
		j = 1;
	strlen = ft_strlen(str);
	if ((strlen > 10 && j == 0) || (strlen > 11 && j == 1))
		return (1);
	if (strlen == 10 && j == 0)
		if (ft_strncmp(str, INT_STR_UPPER, strlen) > 0)
			return (1);
	if (strlen == 11 && j == 1)
	{
		mysubstr = ft_substr(str, j, strlen);
		compstr = ft_strncmp(mysubstr, INT_STR_LOWER, strlen);
		free(mysubstr);
		if (compstr > 0)
			return (1);
	}
	return (0);
}

int	check_errors(int av, char **ac)
{
	int	i;
	int	j;
	int	resultcmp;

	if (av == 0)
		return (1);
	i = -1;
	j = -1;
	while (av > ++i)
	{
		j = -1;
		while (ac[i][++j])
		{
			if (j > 0 && ac[i][j] == '-' && ac[i][j - 1] != ' ')
				return (1);
			if (ac[i][j] == '-' && !ft_isdigit(ac[i][j + 1]))
				return (1);
			if (!ft_isdigit(ac[i][j]) && ac[i][j] != '-' && ac[i][j] != ' ')
				return (1);
		}
		if (chk_out_of_lim (ac[i]))
			return (1);
		j = -1;
	}
	return (0);
}
