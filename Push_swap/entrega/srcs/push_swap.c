/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:38:08 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 17:38:11 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

int	main(int av, char **ac)
{
	t_stack	**stacks;
	char	**str;

	str = input_data(ac);
	av = len_array(str);
	if (check_errors(av, str))
	{
		ft_printf("Error\n");
		free_double_point (str);
		return (0);
	}
	if (av == 1)
		return (0);
	stacks = createstacks(av, str);
	free_double_point (str);
	if (check_duplicates(stacks) || !stacks)
	{
		ft_printf("Error\n");
		free_all_stacks(stacks);
		return (0);
	}
	else
		if (!basic_input(stacks))
			sort_stack_st3(stacks);
	free_all_stacks(stacks);
	return (0);
}
