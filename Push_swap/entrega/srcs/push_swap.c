/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:38:08 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 17:38:11 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

void free_double_point (char **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
        free(ptr[i++]);
    free(ptr);
}

int main (int av, char **ac)
{
    t_stack     **stacks;
    char        **str;
    
    if (av == 1 )
    {
        ft_printf("Error\n");
        return(0);
    }
    str = input_data(ac);
    av = len_array(str);
    if (av == 1)
        return;
    if (check_errors(av, str))
    {
        ft_printf("Error\n");
        return(0);
    }
    stacks = createstacks(av,str);
    free_double_point (str);
    if (!stacks)
     {
        ft_printf("Error\n");
        return(0);
    }
    if (check_duplicates(stacks))
    {
        ft_printf("Error\n");
        free_all_stacks(stacks);
        return (0);
    }
    sort_stack_st2(stacks);
    free_all_stacks(stacks);
    return (0);
}