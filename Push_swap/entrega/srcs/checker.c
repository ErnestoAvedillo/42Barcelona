/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:38:08 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 17:38:11 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"checker.h"

int main (int av, char **ac)
{
    t_stack     **stacks;
    char        **str;
    int         es_error;
    
    es_error = 0;
    if (av == 1 )
        es_error = 1;
    str = input_data(ac);
    av = len_array(str);
    if (av == 1)
        return (0);
    if (check_errors(av, str))
        es_error = 1;
    stacks = createstacks(av,str);
    free_double_point (str);
    if (!stacks)
        es_error = 1;
    if (check_duplicates(stacks))
        es_error = 1;
    if (!es_error)
        es_error = input_moves(stacks);
    if (es_error)
        ft_printf("Error\n");
    free_all_stacks(stacks);
    return (0);
}