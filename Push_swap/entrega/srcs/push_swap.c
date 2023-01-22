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

int main (int av, char **ac)
{
    t_stack     **stacks;
    char        **str;
    int         error;

    error = 0;
    str = input_data(ac);
    av = len_array(str);
    if (check_errors(av, str))
        error = 1;
    if (av == 1 && !error)
        return (0);
    if (av == 0 && !error)
        error = 1;
    stacks = createstacks(av, str);
    free_double_point (str);
    if (!stacks && !error)
        error = 1;
    if (check_duplicates(stacks) && !error)
        error = 1;
    if (error)
    {
        ft_printf("Error\n");
        free_all_stacks(stacks);
        return (0);
    }
    if (!basic_input(stacks))
        sort_stack_st3(stacks);
    free_all_stacks(stacks);
    return (0);
}