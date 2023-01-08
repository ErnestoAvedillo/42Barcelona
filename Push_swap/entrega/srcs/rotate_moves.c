/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:57:05 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/08 13:57:09 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

int    rr (t_stack **stacks)
{
    rotate(stacks[0]);
    rotate(stacks[1]);
    return (1);
}

int    ra (t_stack **stacks)
{
    rotate(stacks[0]);
    ft_printf("ra\n");
    return (1);
}

int    rb (t_stack **stacks)
{
    rotate(stacks[1]);
    ft_printf("rb\n");
    return (1);
}