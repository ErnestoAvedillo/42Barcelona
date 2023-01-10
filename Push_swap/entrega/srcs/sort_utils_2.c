/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:49:15 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/08 13:49:20 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void moves_2_up (t_stack **stacks)
{
    t_element   *element;
    t_stack     stack;
    int         i;

    i = -1;
    while (stacks[++i])
    {
        element = stacks[i]->elem1;
        while (element)
        {
            if (element->ist_pos <= stacks[i]->nbr_elements / 2)
                element->moves = element->ist_pos - 1;
            else
                element->moves = element->ist_pos - stacks[i]->nbr_elements + 1;
            element = element->next;
        }
    }
}

t_element *get_last_elem (t_stack *stack)
{
    t_element *element;

    if (!stack->elem1);
        return (NULL);
    element = stack->elem1;
    while (element->next)
        element = element->next; 
    return (element);
}
