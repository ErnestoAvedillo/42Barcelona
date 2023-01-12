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

int belong_2_interval(t_stack **stacks, t_element *elema, t_element *elemb)
{
    t_element *elemb_next;
    int interv_sup;
    int interv_low;
    elemb_next = elemb->next;
    if (!elemb_next)
        elemb_next = stacks[1]->elem1;
    if (elemb->soll_pos < elemb_next->soll_pos)
    {
        interv_low = 0;
        interv_sup = elemb->soll_pos;
        //printf("1 elem a %i int_low %i - int_high %i\n", elema->soll_pos, interv_low, interv_sup);
        if (elema->soll_pos > interv_low && elema->soll_pos < interv_sup )
            return (1);
        interv_low = elemb_next->soll_pos;
        interv_sup = stacks[0]->nbr_elements + stacks[1]->nbr_elements;
        //printf("2 elem a %i int_low %i - int_high %i\n", elema->soll_pos, interv_low, interv_sup);
        if (elema->soll_pos > interv_low && elema->soll_pos < interv_sup )
            return (1);
    }
    else
    {
        interv_low = elemb_next->soll_pos;
        interv_sup = elemb->soll_pos;
        //printf("3 elem a %i int_low %i - int_high %i\n", elema->soll_pos, interv_low, interv_sup);
        if (elema->soll_pos > interv_low && elema->soll_pos < interv_sup )
            return (1);
    }
    return (0);
}

void seek_min_moves(t_stack **stacks)
{
    t_element   *elementa;
    t_element   *elementb;
    t_element   *elementb_next;
    int         belongs;

    moves_2_up(stacks);
    elementb_next = stacks[1]->elem1;
    elementb = get_last_elem(stacks[1]);
    stacks[1]->optim_move = stacks[1]->nbr_elements;
    stacks[1]->optim_elem = stacks[1]->elem1;
    stacks[0]->optim_move = stacks[0]->nbr_elements;
    stacks[0]->optim_elem = stacks[0]->elem1;
    elementa = stacks[0]->elem1;
    while (elementa)
    {
        elementb_next = stacks[1]->elem1;
        elementb = get_last_elem(stacks[1]);
        while (elementb_next)
        {
            belongs = belong_2_interval(stacks, elementa, elementb);
            //printf("result belongs % i; elem a % i; elem b % i\n", belongs, elementa->soll_pos, elementb_next->soll_pos);
            //getchar();
            if (belongs)
            {
                if (ft_abs(stacks[0]->optim_move) + ft_abs(stacks[1]->optim_move) >
                    ft_abs(elementa->moves) + ft_abs(elementb_next->moves))
                    {
                        stacks[0]->optim_move = elementa->moves;
                        stacks[0]->optim_elem = elementa;
                        stacks[1]->optim_move = elementb_next->moves;
                        stacks[1]->optim_elem = elementb_next;
                    }
            }
            elementb =  elementb_next;
            elementb_next = elementb->next;
            if (ft_abs(stacks[0]->optim_move) + ft_abs(stacks[1]->optim_move) <= 1)
            {
            //    printf("salgo 1\n");
                return ;
            }
        }
        elementa = elementa->next;
       // printf("sig element %#p\n",elementa);
    }
   // printf("salgo 2\n");
    return ;
}

/*
    Returns the moves to be done
    1  --> for rr
    -1 --> for rrr
    2  --> for ra
    3  --> for rb
    -2 --> for rra
    -3 --> for rrb
    4  --> for ra & rrb
    -4  --> for rra & rb
    if there is no moves to be done, returns 0
*/
int still_moves(t_stack **stacks)
{
    //printf(" Amoves %i Bmoves%i\n", stacks[0]->optim_move, stacks[1]->optim_move);
    if (stacks[0]->optim_move > 0 && stacks[1]->optim_move > 0)
        return (1);
    if (stacks[0]->optim_move < 0 && stacks[1]->optim_move < 0)
        return (-1);
    if (stacks[0]->optim_move > 0 && stacks[1]->optim_move == 0)
        return (2);
    if (stacks[0]->optim_move < 0 && stacks[1]->optim_move == 0)
        return (-2);
    if (stacks[0]->optim_move == 0 && stacks[1]->optim_move > 0)
        return (3);
    if (stacks[0]->optim_move == 0 && stacks[1]->optim_move < 0)
        return (-3);
    if (stacks[0]->optim_move > 0 && stacks[1]->optim_move < 0)
        return (4);
    if (stacks[0]->optim_move < 0 && stacks[1]->optim_move > 0)
        return (-4);

    return (0);
}

void    move_to_start (t_stack **stacks)
{
    int movement;

    movement = still_moves(stacks);
   // printf("movim %i\n", movement);
    while (movement == 1)
    {
        rr(stacks);
        stacks[0]->optim_move--;
        stacks[1]->optim_move--;
        movement = still_moves(stacks);
    }
    while (movement == -1)
    {
        rrr(stacks);
        stacks[0]->optim_move++;
        stacks[1]->optim_move++;
        movement = still_moves(stacks);
    }
    while (movement == 2 || movement == 4)
    {
        ra(stacks);
        stacks[0]->optim_move--;
        movement = still_moves(stacks);
    }
    while (movement == -2 || movement == -4)
    {
        rra(stacks);
        stacks[0]->optim_move++;
        movement = still_moves(stacks);
    }
    while (movement == 3)
    {
        rb(stacks);
        stacks[1]->optim_move--;
        movement = still_moves(stacks);
    }
    while (movement == -3)
    {
        rrb(stacks);
        stacks[1]->optim_move++;
        movement = still_moves(stacks);
    }
}

void    move_back(t_stack **stacks)
{
    t_element   *element;
    int         total_moves;
    int         i;

    element = stacks[1]->elem1;
    while (element->soll_pos != 1)
        element = element->next;
    total_moves = element->moves;
    i = 0;
    if (total_moves < 0)
        while (--i >= total_moves - 1)
            rrb(stacks);
    else if (total_moves > 0)
        while (++ i <= total_moves + 1)
            rb(stacks);
    else
        rb(stacks);
    
    element = stacks[1]->elem1;
    while (stacks[1]->elem1)
        pa(stacks);
    return ;
}

void correct_order_b_st(t_stack **stacks)
{
    t_element *element1;
    t_element *element2;
    
    element1 = stacks[1]->elem1;
    element2 = element1->next;
    if (element1->soll_pos < element2->soll_pos)
        sb(stacks);
    return ;
}

void sort_stack_st2(t_stack **stacks)
{
    int         i;
    int         tot_nbr_elem;
    t_element   *element;
   
    i = 0;
    tot_nbr_elem = stacks[0]->nbr_elements;
    coplete_elements(stacks[0]);
    pb(stacks);
    pb(stacks);
    correct_order_b_st(stacks);
    restore_ist_pos(stacks);
    moves_2_up(stacks);
    while (++i < tot_nbr_elem - 2)
    {
        //printf ("1 sigo en el bucle\n");
        seek_min_moves(stacks);
        //printf ("2 sigo en el bucle\n");
        //print_stacks(stacks);
        //printf ("3 sigo en el bucle\n");
        //getchar();
        //printf ("4 sigo en el bucle\n");
        move_to_start(stacks);
    //    element = stacks[0]->elem1;
    //    if (element->soll_pos >= stacks[0]->nbr_elements - 1 );
    //        sa(stacks);    
        //printf ("5 sigo en el bucle\n");
        pb(stacks);
    }
    //printf("he salido del bucle\n");
    moves_2_up(stacks);
    move_back(stacks);
    print_stacks(stacks);
    return;
}
