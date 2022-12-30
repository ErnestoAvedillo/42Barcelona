/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:46:13 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 17:46:18 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

int check_errors(int av, char **ac)
{
    int i;
    int j;

    if(av == 1)
        return (1);
    i = -1;
    j = -1;
    while (ac[++i])
        while(ac[i][++j])
        {
            if(!ft_isdigit(ac[i][k]) && ac[i][j] != ' ')
                return (1);
        }
    return (0);
}
