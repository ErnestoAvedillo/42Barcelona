/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:49:15 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/08 13:49:20 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"push_swap.h"

int get_min_val(t_stack *stack, int cur_min)
{
    int         min;
    int         cur_val;
    t_element   *element;

    min = INT_MAX;
    element = stack->elem1;
    while (element)
    {
        cur_val = element->value;
        if (cur_min < cur_val)
        {
            if (cur_val < min)
                {
                    min = cur_val;
                }
        }
        element = element->next;
    }
    return (min);
}

int calculate_moves(t_element *element, t_stack *stack)
{
    int moves;
    int soll_pos;
    int ist_pos;
    int nbr_elem;
    int frst_elem;

    soll_pos = element->soll_pos;
    ist_pos = element->ist_pos;
    nbr_elem = stack->nbr_elements;
    frst_elem = stack->cur_frst_elem;
    if (soll_pos < ist_pos)
    {
        if ((ist_pos - soll_pos) < (nbr_elem - ist_pos + soll_pos - frst_elem + 1))
            return ( ist_pos - soll_pos);
        return (-nbr_elem + ist_pos - soll_pos + frst_elem - 1);
    }
    else if (soll_pos > ist_pos)
    {
        if ((soll_pos - ist_pos) < (ist_pos - frst_elem + nbr_elem - soll_pos + 1))
            return (ist_pos - soll_pos);
        return (ist_pos - frst_elem + nbr_elem - soll_pos + 1);

    }
    return (0);
}

void put_pos_elem(int valor, int pos, t_stack *stack)
{
    t_element   *element;
    int         cur_pos;

    element = stack->elem1;
    cur_pos = 1;
    while (element)
    {
        if (element->value == valor)
        {
            element->soll_pos = pos ;
            element->ist_pos = cur_pos;
            element->moves = calculate_moves(element, stack);
        }
        cur_pos++;
        element = element->next;
    }
    return;
}

void coplete_elements(t_stack *stack)
{
    int position;
    int min;

    min = INT_MIN;
    position = 1;
    while (position <= stack->nbr_elements)
    {
        min = get_min_val(stack, min);
        put_pos_elem (min, position, stack);
        position++;
    }
}

void calc_all_moves (t_stack *stack)
{
    t_element *element;

    element = stack->elem1;
    while (element)
    {
        calculate_moves(element, stack);
        element = element->next;
    }
    return ;
}

