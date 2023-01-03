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

int chk_out_of_lim (char *str)
{
    int     j;
    char    *mysubstr;

    j = 0;
    if (str[0] = '-')
        j = 1;
    resultcmp = ft_strlen(str)
    if (resultcmp > 10 )
        return (1);
    else if (resultcmp == 10 && j == 0;
        if(ft_strncmp(ac[i], INT_STR_UPPER, j ) > 0)
            return (1);
    else if (resultcmp == 11 && j == 1;
    {
        mysubstr = ft_substr(str,j,resultcmp)
        if(ft_strncmp(ac[i], INT_STR_LOWER, resultcmp ) < 0)
        {
            free (mysubstr);
            return (1);
        }
        free (mysubstr);
    }
    return (0);
}

int check_errors(int av, char **ac)
{
    int i;
    int j;
    int resultcmp;

    if(av == 1)
        return (1);
    i = -1;
    j = -1;
    while (ac[++i])
    {
        while(ac[i][++j])
        {
            if(!ft_isdigit(ac[i][k]) && (ac[i][j] != '-' || ac[i][j] != ' ' ))
                return (1);
            if (chk_out_of_lim (ac[i]))
                return (1);
        }
    }
    return (0);
}
