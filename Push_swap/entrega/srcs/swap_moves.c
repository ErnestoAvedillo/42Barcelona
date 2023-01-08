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

void    swap (t_stack *stack)
{
    void *ptr;
    t_element *element1;
    t_element *element2;

    element1 = stack->elem1;
    element2 = element1->next;
    ptr = element2->next;
    stack->elem1 =  element2;
    element2->next = element1;
    element1->next = ptr;
    element2->ist_pos = stack->cur_frst_elem;
    element2->moves = calculate_moves (element2, stack);
    element1->ist_pos = stack->cur_frst_elem + 1;
    element1->moves = calculate_moves (element1, stack);
    return ;
}

int    ss (t_stack **stacks)
{
    swap(stacks[0]);
    swap(stacks[1]);
    ft_printf ("ss\n");
    return (1);
}

int sa (t_stack **stacks)
{
    swap(stacks[0]);
    ft_printf ("sa\n");
    return (1);
}

int sb (t_stack **stacks)
{
    swap(stacks[1]);
    ft_printf ("sb\n");
    return (1);
}
