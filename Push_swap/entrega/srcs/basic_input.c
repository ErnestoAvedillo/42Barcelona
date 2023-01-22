#include "push_swap.h"

/*
cases for 3
123
132
213
231
312
321
*/
void solve_3_st(t_stack **stacks)
{
    t_element   *elem1;
    t_element   *elem2;
    t_element   *elem3;

    elem1 = stacks[0]->elem1;
    elem2 = elem1->next;
    elem3 = elem2->next;
    if (elem1->soll_pos == 1 && elem2->soll_pos == 2 && elem3->soll_pos == 3)
        return ;
    else if (elem1->soll_pos == 1 && elem2->soll_pos == 3 && elem3->soll_pos == 2)
    {
        rra(stacks, 1);
        sa(stacks, 1);
    }
    else if (elem1->soll_pos == 2 && elem2->soll_pos == 1 && elem3->soll_pos == 3)
        sa(stacks, 1);
    else if (elem1->soll_pos == 2 && elem2->soll_pos == 3 && elem3->soll_pos == 1)
        rra(stacks, 1);
    else if (elem1->soll_pos == 3 && elem2->soll_pos == 1 && elem3->soll_pos == 2)
        ra(stacks, 1);
    else if (elem1->soll_pos == 3 && elem2->soll_pos == 2 && elem3->soll_pos == 1)
    {
        sa(stacks, 1);
        rra(stacks, 1);
    }
    return ;
}

static void solve_2_st (t_stack **stacks)
{
    t_element   *elem1;
    t_element   *elem2;

    elem1 = stacks[0]->elem1;
    elem2 = elem1->next;
    if (elem1->soll_pos == 2)
        sa(stacks, 1);
    return;
}

int basic_input(t_stack **stacks)
{
    coplete_elements(stacks[0]);
    if (stacks[0]->nbr_elements > 5)
        return (0);
    if (stacks[0]->nbr_elements == 5)
        sort_5_elm_stack(stacks);
    if (stacks[0]->nbr_elements == 4)
        sort_4_elm_stack(stacks);
    if (stacks[0]->nbr_elements == 3)
        solve_3_st(stacks);
    if (stacks[0]->nbr_elements == 2)
        solve_2_st(stacks);
    return (1);
}