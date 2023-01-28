/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:22:02 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/12 18:22:45 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stacks_status(t_stack **stacks, int print)
{
	t_element	*element1;
	t_element	*element2;

	if (stacks[1]->elem1)
	{
		if (print)
			ft_printf("KO\n");
		return (0);
	}
	element1 = stacks[0]->elem1;
	element2 = element1->next;
	while (element2)
	{
		if (element1->value > element2->value)
		{
			if (print)
				ft_printf("KO\n");
			return (0);
		}
		element1 = element2;
		element2 = element1->next;
	}
	if (print)
		ft_printf("OK\n");
	return (1);
}
