/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:56:12 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/05 09:56:17 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void    push (t_stack *stack_a, t_stack *stack_b)
{
    t_element *element_a;
    t_element *element_b;


    element_a = stack_a->elem1;
    stack_a->elem1 = element_a->next;
//    stack_a->cur_frst_elem += 1;
    stack_a->nbr_elements -= 1;
//    coplete_elements (stack_a);
    
    element_b = stack_b->elem1;
    element_a->next = element_b;
    stack_b->elem1 = element_a;
//    stack_b->cur_frst_elem -= 1;
    stack_b->nbr_elements += 1;
//    coplete_elements (stack_b);
    return ;
} 

int    pa(t_stack **stacks, int print_move)
{
    push (stacks[1], stacks[0]);
    restore_ist_pos(stacks);
    if (print_move)
        ft_printf("pa\n");
    return (1);
}

int    pb(t_stack **stacks, int print_move)
{
    push (stacks[0], stacks[1]);
    restore_ist_pos(stacks);
    if (print_move)
        ft_printf("pb\n");
    return (1);
}
