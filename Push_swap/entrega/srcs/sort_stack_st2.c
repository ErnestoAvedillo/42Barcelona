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

    i = 0;
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
            if ()
            if (sentido)
                ra(stacks);
            else
                rra(stacks);
        }
    pb(stacks);
    coplete_elements(stacks[0]);
    }
    i++;
    while (--i > 1)
    {
        pa(stacks);
    }
    print_stacks (stacks);
    free_all_stacks(stacks);
    return ;
}
/*    printf("pa\n");
    push (stacks[0],stacks[1]);
    printf("pa\n");
    push (stacks[0],stacks[1]);
    printf("pa\n");
    push (stacks[0],stacks[1]);
    print_stacks (stacks);
    printf("sa\n");
    swap(stacks[0]);
    print_stacks (stacks);
    printf("sb\n");
    swap(stacks[1]);
    print_stacks (stacks);
    printf("ra\n");
    rotate (stacks[0]);
    print_stacks (stacks);
    printf("rb\n");
    rotate (stacks[1]);
    print_stacks (stacks);
    printf("rr\n");
    rotate2 (stacks);
    print_stacks (stacks);
    printf("ss\n");
    swap2 (stacks);
    print_stacks (stacks);
    printf("rra\n");
    revrotate (stacks[0]);
    print_stacks (stacks);
    printf("rrr\n");
    revrotate2 (stacks);
    print_stacks (stacks);
*/

