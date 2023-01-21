#include "push_swap.h"

int is_data_correct(char *str)
{
    int i;

    i = 0;
    read(1, str, 20);
    while (str[i] != '\n')
        i++;
    str[i] = '\0';
    i = -1;
    while (++i < NBR_MOVES)
    {
        if (!ft_strncmp(str, (char *)LIST_MOVES[i], ft_strlen(str)))
            return (1);
    }
    return (0);
}

int make_move(int (*move)(t_stack**), t_stack **stacks)
{
    return (move(stacks));
}

void input_moves(t_stack **stacks)
{
    int cont;
    int     i;
    char    str[20];

    print_stacks(stacks);
    cont = 1;
    while (1)
    {
        cont = is_data_correct(str);
        if (cont)
        {
            i = 0;
            while (i <= 10)
            {
                if (!ft_strncmp(str, (char *)LIST_MOVES[i], ft_strlen(str)))
                {
                    make_move(FCN_MOVES[i], stacks);
                    print_stacks(stacks);
                }
                i++;
            }
        }
        else
            return;
    }
    return;
}
