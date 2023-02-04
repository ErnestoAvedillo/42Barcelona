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

	if (av == 1)
		return (0);
	str = analyze_data(av, ac);
	if (str == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	av = len_array(str);
	stacks = createstacks(av, str);
	free_double_point (str);
	if (!stacks || check_duplicates(stacks))
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
