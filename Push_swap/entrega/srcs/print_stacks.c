#include "./push_common.h"
void print_stacks(t_stack **stacks)
{
    t_element *elem_stk_a;
    t_element *elem_stk_b;

    elem_stk_a = stacks[0]->elem1;
    elem_stk_b = stacks[1]->elem1;
    ft_printf(" stack_a nbr_elem:%i - first_elem :%i", stacks[0]->nbr_elements, stacks[0]->cur_frst_elem);
    ft_printf("      ---    stack_b nbr_elem:%i - first_elem :%i\n", stacks[1]->nbr_elements, stacks[1]->cur_frst_elem);
    ft_printf(" stack_a moves optim:%i - element optim :%p", stacks[0]->optim_move, stacks[0]->optim_elem);
    ft_printf("      ---    stack_b moves optim:%i - element optim :%p\n", stacks[1]->optim_move, stacks[1]->optim_elem);
    ft_printf("value    soll     ist   moves\t cur add.       next \t         ---");
    ft_printf("value    soll    ist   moves\t cur add.       next\n");
    while (elem_stk_a || elem_stk_b)
    {
        if (elem_stk_a)
        {
            printf("% 5d\t% 5d\t% 5d\t% 5d\t%#13.13p\t%#13.13p\t ---", elem_stk_a->value,
                   elem_stk_a->soll_pos, elem_stk_a->ist_pos, elem_stk_a->moves,
                   elem_stk_a, elem_stk_a->next);
            elem_stk_a = elem_stk_a->next;
        }
        else
            printf("%67s", "---");
        if (elem_stk_b)
        {
            printf("% 5d % 5d\t   % 5d  % 5d\t     %#13.13p   %#13.13p", elem_stk_b->value,
                   elem_stk_b->soll_pos, elem_stk_b->ist_pos, elem_stk_b->moves,
                   elem_stk_b, elem_stk_b->next);
            elem_stk_b = elem_stk_b->next;
        }
        printf("\n");
    }
}
void print_element(t_element *elem)
{
    ft_printf("Valor:% 5d\t; Soll pos:% 5d\t; Ist pos:% 5d\t; Moves:% 5d\t Adress:%#13.13p\n", elem->value,
              elem->soll_pos, elem->ist_pos, elem->moves, elem->next);
}
