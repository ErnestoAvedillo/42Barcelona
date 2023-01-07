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

void    swap2 (t_stack **stacks)
{
    swap(stacks[0]);
    swap(stacks[1]);
    return ;
}

void push (t_stack *stack_a, t_stack *stack_b)
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

void rotate (t_stack *stack)
{
    t_element   *element;
    t_element   *element_2;

    if (stack->nbr_elements > 1)
    {
        element_2 = stack->elem1;
        stack->elem1 = element_2->next;
        element = element_2;
        while  (element->next)
        {
            element = element->next;
        }
        element->next = element_2;
        element_2->next = NULL; 
//        coplete_elements (stack);
    }
    return ;
}

void    rotate2 (t_stack **stacks)
{
    rotate(stacks[0]);
    rotate(stacks[1]);
    return ;
}

void revrotate (t_stack *stack)
{
    t_element   *element;
    t_element   *element_2;

    if (stack->nbr_elements > 1)
    {
        element = stack->elem1;
        element_2 = element->next;
        while  (element->next)
        {
            element_2 = element;
            element = element->next;
        }
        element_2->next = NULL;
        element->next = stack->elem1;
        stack->elem1 = element;
//      coplete_elements (stack);
    }
    return ;
}

void    revrotate2 (t_stack **stacks)
{
    revrotate(stacks[0]);
    revrotate(stacks[1]);
    return ;
}
