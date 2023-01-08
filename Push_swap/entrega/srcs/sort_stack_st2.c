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

void sort_stack_st2(t_stack **stacks)
{
    int i;
    int max_elem;
    t_element *element;
    int moves_needed;
    int sentido;
    int movim;

    i = 0;
    movim = 0;
    max_elem = stacks[0]->nbr_elements;
    coplete_elements(stacks[0]);
    print_stacks (stacks);
    while (++i < max_elem)
    {
        element = search_item(1, stacks[0]);
        moves_needed = 0;
        sentido = get_sentido(element->moves);
        while (++moves_needed <= ft_abs(element->moves))
        {
            if (sentido)
                movim += ra(stacks);
            else
                movim += rra(stacks);
        }
        movim += pb(stacks);
        coplete_elements(stacks[0]);
    }
    i++;
    while (--i > 1)
    {
        movim += pa(stacks);
    }
    coplete_elements(stacks[0]);
    print_stacks(stacks);
    free_all_stacks(stacks);
    ft_printf("numero de moovimientos = %i\n", movim);
    return;
}
