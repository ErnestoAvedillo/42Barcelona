/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:57:41 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/24 07:57:43 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
cases for 3
123
132
213
231
312
321
*/
void	solve_3_st(t_stack **stacks)
{
	t_element	*elm1;
	t_element	*elm2;
	t_element	*elm3;

	elm1 = stacks[0]->elem1;
	elm2 = elm1->next;
	elm3 = elm2->next;
	if (elm1->soll_pos == 1 && elm2->soll_pos == 2 && elm3->soll_pos == 3)
		return ;
	else if (elm1->soll_pos == 1 && elm2->soll_pos == 3 && elm3->soll_pos == 2)
	{
		rra(stacks, 1);
		sa(stacks, 1);
	}
	else if (elm1->soll_pos == 2 && elm2->soll_pos == 1 && elm3->soll_pos == 3)
		sa(stacks, 1);
	else if (elm1->soll_pos == 2 && elm2->soll_pos == 3 && elm3->soll_pos == 1)
		rra(stacks, 1);
	else if (elm1->soll_pos == 3 && elm2->soll_pos == 1 && elm3->soll_pos == 2)
		ra(stacks, 1);
	else if (elm1->soll_pos == 3 && elm2->soll_pos == 2 && elm3->soll_pos == 1)
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
}

static void	solve_2_st(t_stack **stacks)
{
	t_element	*elm1;
	t_element	*elm2;

	elm1 = stacks[0]->elem1;
	elm2 = elm1->next;
	if (elm1->soll_pos == 2)
		sa(stacks, 1);
	return ;
}

int	basic_input(t_stack **stacks)
{
	if (check_stacks_status(stacks, 0, 1))
		return (1);
	coplete_elements(stacks[0]);
	if (stacks[0]->nbr_elements > 5)
		return (0);
	if (stacks[0]->nbr_elements == 5)
		sort_5_elm_stack(stacks);
	if (stacks[0]->nbr_elements == 4)
		sort_4_elm_stack(stacks);
	if (stacks[0]->nbr_elements == 3)
		solve_3_st(stacks);
	if (stacks[0]->nbr_elements == 2)
		solve_2_st(stacks);
	return (1);
}
