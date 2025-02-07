/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:20:03 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/05 08:20:11 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void	move_elm_up(t_stack **stacks, int soll_pos)
{
	t_element	*element;
	int			i;
	int			moves_needed;

	element = stacks[0]->elem1;
	while (element->soll_pos != soll_pos)
		element = element->next;
	moves_needed = element->moves;
	i = -1;
	while (++i < ft_abs(moves_needed))
	{
		if (ft_ispositive(moves_needed))
			ra(stacks, 1);
		else
			rra(stacks, 1);
	}
}

void	sort_2_elem(t_stack **stacks)
{
	t_element	*element1;
	t_element	*element2;

	element1 = stacks[0]->elem1;
	element2 = element1->next;
	if (element1->soll_pos > element2->soll_pos)
		sa(stacks, 1);
	return ;
}

void	sort_5_elm_stack(t_stack **stacks)
{
	coplete_elements(stacks[0]);
	restore_ist_pos(stacks);
	moves_2_up(stacks);
	move_elm_up(stacks, 1);
	pb(stacks, 1);
	moves_2_up(stacks);
	move_elm_up(stacks, 2);
	pb(stacks, 1);
	coplete_elements(stacks[0]);
	solve_3_st(stacks);
	pa(stacks, 1);
	pa(stacks, 1);
	return ;
}

void	sort_4_elm_stack(t_stack **stacks)
{
	coplete_elements(stacks[0]);
	restore_ist_pos(stacks);
	moves_2_up(stacks);
	move_elm_up(stacks, 1);
	pb(stacks, 1);
	moves_2_up(stacks);
	move_elm_up(stacks, 2);
	pb(stacks, 1);
	coplete_elements(stacks[0]);
	sort_2_elem(stacks);
	pa(stacks, 1);
	pa(stacks, 1);
	return ;
}
