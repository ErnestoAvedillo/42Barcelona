#include"push_swap.h"

static t_element *free_elem (t_element *ptr)
{
    t_element    *next_ptr;

    ptr->value = 0;
    ptr->real_pos = 0;
    ptr->curr_pos = 0;
    ptr->moves = 0;
    next_ptr = ptr->next;
    free (ptr);
    return (next_ptr);
}

int free_stack (l_stack *ptr)
{
    t_element   *cur_elem;

    cur_elem = ptr->elem1;
    while (cur_elem)
        cur_elem = free_elem(cur_elem);
    free (ptr);
    return (0);
}
