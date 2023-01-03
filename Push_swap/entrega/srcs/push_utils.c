#include"push_swap.h"

void print_stacks(t_stack **stacks)
{
    t_element   *elem_stk_a;
    t_element   *elem_stk_b;

    elem_stk_a = stacks[0]->elem1;
    elem_stk_b = stacks[1]->elem1;
    ft_printf ("\t\t stack_a \t\t --- \t\t stack_b \t\t\n")
    ft_printf ("value\t real_pos\t curr_pos \t moves\t next \t ---");
    ft_printf ("value\t real_pos\t curr_pos \t moves\t next\n");
    while (elem_stk_a || elem_stk_b)
    {
        if(elem_stk_a)
            ft_printf ("%d\t%d\t%d\t%d\t%p\t ---", elem_stk_a->value; \
                elem_stk_a->real_pos; elem_stk_a->curr_pos; elem_stk_a->moves; \
                elem_stk_a->next);
        if (elem_stk_b)
            ft_printf ("%d\t%d\t%d\t%d\t%p", elem_stk_b->value; \
                elem_stk_b->real_pos; elem_stk_b->curr_pos; elem_stk_b->moves; \
                elem_stk_b->next);
        ft_printf ("\n)")
        elem_stk_a = elem_stk_a->next;
        elem_stk_b = elem_stk_b->next;
    }
}