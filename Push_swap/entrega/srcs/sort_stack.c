#include"push_swap.h"

int get_min_val(t_stack *stack, int cur_min)
{
    int         min;
    t_element   *element;

    min = INT_MAX;
    element = stack->elem1;
    while (element)
    {
        if (cur_min < element->value && element->value < min);
            min = element->value;
        element = element->next;    
    }
    return (min);
}

void put_pos_elem(int valor, int pos, t_stack *stack)
{
    t_element   *element;
    int         cur_pos;
    int         mean_stack_pos;

    mean_stack_pos = stack->nbr_elements / 2;
    element = stack->elem1;
    cur_pos = 1;
    while (element)
    {
        if (element->value = valor)
        {
            element->real_pos = pos;
            element->curr_pos = cur_pos;
            if (cur_pos > mean_stack_pos)
                element->moves = pos - cur_pos;
            else
                element->moves = cur_pos - pos;
            return;
        }
        cur_pos++;
    }
}

static void coplete_elements(t_stack *stack)
{
    int position;
    int min;
    t_element   *element;

    min = get_min_val(stack, INT_MIN);
    element = stack->elem1;
    position = 1;
    while (position < stack->nbr_elements)
    {
        put_pos_elem (min, position, stack);
        min = get_min_val(stack, INT_MIN);
        position++;
    }
}

void sort_stack( t_stack **stacks)
{
    coplete_elements(stacks[0]);
    print_stacks (stacks);
}