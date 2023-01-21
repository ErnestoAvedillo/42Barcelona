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

void analyze_moves (t_stack **stacks, t_element *elema, t_element *elemb)
{
    int tot_elem;
    int moves_a;
    int moves_b;


    tot_elem =  stacks[0]->nbr_elements + stacks[1]->nbr_elements;
    moves_a = elema->moves;
    moves_b = elemb->moves;

    if (ft_abs(stacks[0]->optim_move) + ft_abs(stacks[1]->optim_move) >
        ft_abs(elema->moves) + ft_abs(elemb->moves))
        {
            stacks[0]->optim_move = elema->moves;
            stacks[0]->optim_elem = elema;
            stacks[1]->optim_move = elemb->moves;
            stacks[1]->optim_elem = elemb;
        }
    return ;
}

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
            if (belongs)
            {
                analyze_moves(stacks, elementa, elementb_next);
            }
            elementb =  elementb_next;
            elementb_next = elementb->next;
            if (ft_abs(stacks[0]->optim_move) + ft_abs(stacks[1]->optim_move) <= 1)
            {
                return ;
            }
        }
        elementa = elementa->next;
    }
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
        while (--i > total_moves)
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

void send_frst_2_elem(t_stack **stacks)
{
    t_element   *element1;
    t_element   *element2;
    int         number_of_elem;

    element1 = stacks[0]->elem1;
    element2 = element1->next;
    number_of_elem = stacks[0]->nbr_elements;
    if (element1->soll_pos == number_of_elem)
    {
        ra(stacks);
        pb(stacks);
        pb(stacks);
    }
    else if (element2->soll_pos == number_of_elem )
    {
        pb(stacks);
        ra(stacks);    
        pb(stacks);
    }
    else 
    {
        pb(stacks);
        pb(stacks);
    }
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
   
    i = 1;
    tot_nbr_elem = stacks[0]->nbr_elements;
    //    print_stacks(stacks);
    coplete_elements(stacks[0]);
    //    print_stacks(stacks);
    send_frst_2_elem(stacks);
    restore_ist_pos(stacks);
    while (++i < tot_nbr_elem - 1)
    {
        element = stacks[0]->elem1;
        if (element->soll_pos == tot_nbr_elem && stacks[0]->nbr_elements != 1 )
            ra(stacks);    
        moves_2_up(stacks);
        seek_min_moves(stacks);
        move_to_start(stacks);
        pb(stacks);
    //    print_stacks(stacks);
    //    getchar();
    }
    //print_stacks(stacks);
    //order_2_elem(stacks);
    //    print_stacks(stacks);
    //    getchar();
    moves_2_up(stacks);
    //    print_stacks(stacks);
    //    getchar();
    move_back(stacks);
    //    print_stacks(stacks);
    //    getchar();
    //print_stacks(stacks);
    return;
}
