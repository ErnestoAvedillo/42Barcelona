#include"push_swap.h"

t_element	*ft_new_element(t_element *content,int value)
{
	t_element	*ptr;

	ptr = (t_element *)malloc (sizeof (t_element));
	if (ptr == NULL)
		return (NULL);
	content->next = ptr ;
	ptr->value = value;
	ptr->next = NULL;
    return (ptr);
}


t_stack *retrieve_data(int av, char **ac)
{
    int     i;
    t_element *cur_ptr;
    t_stack *stack;
    stack = (t_stack *) malloc (sizeof (t_stack));
    if (!stack)
        return (NULL);
    i = 1;
    stack->elem1 = (t_element *) malloc (sizeof (t_element));
    if (!stack->elem1)
        {
            free_stack(stack);
            return (NULL);
        }
    cur_ptr = stack->elem1;
    cur_ptr->value = ft_atoi(ac[i]);
    while (av > ++i)
    {
        cur_ptr = ft_new_element(cur_ptr,ft_atoi(ac[i]));
        if (!cur_ptr)
        {
            free_stack(stack);
            return (NULL);
        }
    }
    stack->nbr_elements = i;
    stack->cur_frst_elem = 1;
    return (stack);
}
t_stack **createstacks(int av, char **ac)
{
    t_stack **stacks;

    stacks = (t_stack **) malloc ( 3 * sizeof (t_stack));
    stacks[0] = retrieve_data(av,ac);
    if (!stacks[0])
        return (NULL);
    stacks[1] = malloc (sizeof (t_stack));
    if (!stacks[1])
    {
        free_stack (stacks[0]);
        stacks[1]->nbr_elements = 0;
        stacks[1]->cur_frst_elem = 0;
        stacks[1]->elem1 = NULL;
        return (NULL);
    }
    stacks [2] = NULL;
    return (stacks);
}
