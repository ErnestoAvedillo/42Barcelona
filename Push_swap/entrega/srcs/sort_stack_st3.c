/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_st2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:34 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/08 13:47:40 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	move_back(t_stack **stacks)
{
	t_element	*element1;
	t_element	*element2;
	int			total_moves;
	int			i;

	element1 = stacks[1]->elem1;
	element2 = get_last_elem(stacks[1]);
	while (element1->soll_pos < element2->soll_pos)
	{
		element2 = element1;
		element1 = element2->next;
	}
	total_moves = element2->moves;
	i = 0;
	if (total_moves < 0)
		while (--i > total_moves)
			rrb(stacks, 1);
	else if (total_moves > 0)
		while (++ i <= total_moves + 1)
			rb(stacks, 1);
	else
		rb(stacks, 1);
	while (stacks[1]->elem1)
		pa(stacks, 1);
	return ;
}

void	send_frst_2_elem(t_stack **stacks)
{
	t_element	*element1;
	int			number_of_elem;

	element1 = stacks[0]->elem1;
	number_of_elem = stacks[0]->nbr_elements;
	if (element1->soll_pos == number_of_elem)
		ra(stacks, 1);
	pb(stacks, 1);
	element1 = stacks[0]->elem1;
	if (element1->soll_pos == number_of_elem)
		ra(stacks, 1);
	pb(stacks, 1);
	return ;
}

void	order_2_elem(t_stack **stacks)
{
	t_element	*element1;
	t_element	*element2;

	element1 = stacks[0]->elem1;
	element2 = element1->next;
	if (element1->soll_pos > element2->soll_pos)
		sa(stacks, 1);
	return ;
}

void	sort_stack_st3(t_stack **stacks)
{
	int			i;
	int			tot_nbr_elem;
	t_element	*element;

	if (check_stacks_status(stacks, 0, 1))
		return ;
	i = 1;
	tot_nbr_elem = stacks[0]->nbr_elements;
	coplete_elements(stacks[0]);
	send_frst_2_elem(stacks);
	restore_ist_pos(stacks);
	while (++i < tot_nbr_elem - 1)
	{
		element = stacks[0]->elem1;
		if (element->soll_pos == tot_nbr_elem && stacks[0]->nbr_elements != 1)
			ra(stacks, 1);
		moves_2_up(stacks);
		seek_min_moves(stacks);
		move2top(stacks);
		pb(stacks, 1);
	}
	moves_2_up(stacks);
	move_back(stacks);
	return ;
}
