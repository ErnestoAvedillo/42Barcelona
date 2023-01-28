/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:18:58 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/05 08:19:05 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static t_element	*free_elem(t_element *ptr)
{
	t_element	*next_ptr;

	ptr->value = 0;
	ptr->soll_pos = 0;
	ptr->ist_pos = 0;
	ptr->moves = 0;
	next_ptr = ptr->next;
	free (ptr);
	return (next_ptr);
}

int	free_stack(t_stack *ptr)
{
	t_element	*cur_elem;

	cur_elem = ptr->elem1;
	while (cur_elem)
		cur_elem = free_elem(cur_elem);
	free (ptr);
	return (0);
}

void	free_all_stacks(t_stack **stacks)
{
	t_element	*cur_elem;

	cur_elem = stacks[0]->elem1;
	while (cur_elem)
		cur_elem = free_elem(cur_elem);
	free (stacks[0]);
	cur_elem = stacks[1]->elem1;
	while (cur_elem)
		cur_elem = free_elem(cur_elem);
	free (stacks[1]);
	free (stacks[2]);
	free (stacks);
	return ;
}

void	free_double_point(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
