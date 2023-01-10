/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:20:03 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/05 08:20:11 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sort_stack( t_stack **stacks)
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
            if (sentido)
                rotate(stacks[0]);
            else
                revrotate(stacks[0]);
        }
    push(stacks[0],stacks[1]);
    coplete_elements(stacks[0]);
    print_stacks (stacks);
    }
    i++;
    while (--i > 1)
    {
        push(stacks[1],stacks[0]);
    }
    print_stacks (stacks);
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

