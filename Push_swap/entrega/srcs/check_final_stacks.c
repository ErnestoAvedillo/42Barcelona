/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_final_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:22:02 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/12 18:22:45 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_final_stacks(t_stack **stacks)
{
	t_element	*element1;
	t_element	*element2;

	if (stacks[1]->elem1)
	{
		ft_printf("KO\n");
		return ;
	}
	element1 = stacks[0]->elem1;
	element2 = element1->next;
	while (element2)
	{
		if (element1->value > element2->value)
		{
			ft_printf("KO\n");
			return ;
		}
		element1 = element2;
		element2 = element1->next;
	}
	ft_printf("OK\n");
	return ;
}
