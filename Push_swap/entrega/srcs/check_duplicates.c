/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:22:02 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/12 18:22:45 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_duplicates(t_stack **stacks)
{
    t_element   *element1;
    t_element   *element2;

    element1 = stacks[0]->elem1;
    element2 = element1->next;
    while (element1)
    {
        element2 = element1->next;
        while (element2)
        {
            if (element1->value == element2->value)
                return (1);
            element2 = element2->next;
        }
        element1 = element1->next;
    }
    return (0);
}