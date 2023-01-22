#include "checker.h"

int is_data_correct(char *str)
{
    int i;

    i = -1;
    while (++i < NBR_MOVES)
    {
        if (!ft_strncmp(str , (char *)LIST_MOVES[i], ft_strlen(str)))
            return (1);
    }
    return (0);
}

int make_move(int (*move)(t_stack**, int), t_stack **stacks, int print_move)
{
    return (move(stacks, print_move));
}

int input_moves(t_stack **stacks)
{
    int     es_ok;
    int     i;
    char    *str;

    print_stacks(stacks);
    es_ok = 1;
    while (es_ok != -1)
    {
        str = get_next_line(0);
        es_ok = is_data_correct(str);
        if (es_ok == 1)
        {
            i = 0;
            while (i < NBR_MOVES)
            {
                if (!ft_strncmp(str, (char *)LIST_MOVES[i], ft_strlen(str)))
                {
                    make_move(FCN_MOVES[i], stacks, 0);
                    print_stacks(stacks);
                }
                i++;
            }
        }
        else
            return(1);
    }
    return (0);
}
