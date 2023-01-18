#include "push_swap.h"

int is_data_correct(char *str)
{
    int i;

    i = 0;
    while(--i <= NBR_MOVES)
    {
        if (!ft_strcmp(str,LIST_MOVES[i]))
            return (1);
    }
    return (0);
}

int exec_instruction (t_stack **stacks, char *str)
{
    
}

void input_moves(t_stack **stacks)
{
    char    *str;

    str = getchar()
    while (is_data_correct(str))
    {
        exit =  exec_instruction();
        str = getchar()
    }

    return ;
}
