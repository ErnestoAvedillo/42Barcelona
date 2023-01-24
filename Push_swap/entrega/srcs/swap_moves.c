/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:55:51 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/08 13:55:55 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack *stack)
{
	void		*ptr;
	t_element	*element1;
	t_element	*element2;

	if (stack->nbr_elements <= 1)
		return ;
	element1 = stack->elem1;
	element2 = element1->next;
	ptr = element2->next;
	stack->elem1 = element2;
	element2->next = element1;
	element1->next = ptr;
	element2->ist_pos = 1;
	element2->moves = 0;
	element1->ist_pos = 2;
	element1->moves = 1;
	return ;
}

int	ss(t_stack **stacks, int print_move)
{
	swap(stacks[0]);
	swap(stacks[1]);
	if (print_move)
		ft_printf ("ss\n");
	return (1);
}

int	sa(t_stack **stacks, int print_move)
{
	swap(stacks[0]);
	if (print_move)
		ft_printf ("sa\n");
	return (1);
}

int	sb(t_stack **stacks, int print_move)
{
	swap(stacks[1]);
	if (print_move)
		ft_printf ("sb\n");
	return (1);
}
