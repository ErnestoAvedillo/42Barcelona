/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:57:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/08 13:57:36 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void	revrotate(t_stack *stack)
{
	t_element	*element;
	t_element	*element_2;

	if (stack->nbr_elements > 1)
	{
		element = stack->elem1;
		element_2 = element->next;
		while (element->next)
		{
			element_2 = element;
			element = element->next;
		}
		element_2->next = NULL;
		element->next = stack->elem1;
		stack->elem1 = element;
	}
	return ;
}

int	rrr(t_stack **stacks, int print_move)
{
	revrotate(stacks[0]);
	revrotate(stacks[1]);
	restore_ist_pos(stacks);
	if (print_move)
		ft_printf("rrr\n");
	return (1);
}

int	rra(t_stack **stacks, int print_move)
{
	revrotate(stacks[0]);
	restore_ist_pos(stacks);
	if (print_move)
		ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **stacks, int print_move)
{
	revrotate(stacks[1]);
	restore_ist_pos(stacks);
	if (print_move)
		ft_printf("rrb\n");
	return (1);
}
