/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:38:08 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 17:38:11 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"checker.h"

static char	**analyze_data(int av, char **ac)
{
	char	**str;

	str = input_data(ac);
	if (str == NULL)
	{
		return (NULL);
	}
	av = len_array(str);
	if (check_errors(av, str))
	{
		free_double_point (str);
		return (NULL);
	}
	if (av == 0)
	{
		free_double_point (str);
		return (NULL);
	}
	return (str);
}

int	main(int av, char **ac)
{
	t_stack	**stacks;
	char	**str;

	str = analyze_data(av, ac);
	if (str == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}

	av = len_array(str);
	stacks = createstacks(av, str);
	free_double_point(str);
	if (input_moves(stacks, 0) || check_duplicates(stacks) || !stacks)
		ft_printf("Error\n");
	else
		check_stacks_status(stacks, 1, 1);
	free_all_stacks(stacks);
	return (0);
}
