#include "push_swap.h"

int is_data_correct(char *str)
{
    int i;

    i = 0;
    while(--i <= NBR_MOVES)
    {
        if (!ft_strncmp(str,LIST_MOVES[i][1],ft_strlen(str)))
            return (1);
    }
    return (0);
}

int exec_instruction (t_stack **stacks, char *str)
{
    int i;

    i = -1;
    while (++i <= NBR_INTRUCTIONS )
    {
        if (!ft_strcmp(str,LIST_MOVES[i][1]))
        {
            (*LIST_MOVES[i][2])
            return (1);
        }
    }
    return (0);
}

void input_moves(t_stack **stacks)
{
    char    *str;

    str = getchar()
    while (is_data_correct(str))
    {
        exit =  exec_instruction(stacks,str);
        str = getchar();
    }

    return ;
}
