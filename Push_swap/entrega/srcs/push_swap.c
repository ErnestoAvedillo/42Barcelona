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
    t_stack **stacks;
    int     result;

    result = check_errors(av, ac);
    if (result)
    {
        ft_printf("Error\n");
        return(0);
    }
    stacks = createstacks(av,ac);
    if (!stacks)
     {
        ft_printf("Error\n");
        return(0);
    }
    sort_stack_st2(stacks);
    free_all_stacks(stacks);
    return (0);
}