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
    int     strlen;
    int     compstr;

    ft_printf("Entro CHECK limits\n");
    j = 0;
    if (str[0] = '-')
        j = 1;
    strlen = ft_strlen(str);
    if (strlen > 10 )
    {
        ft_printf("Error 11\n");
        return (1);
    }
    else if (strlen == 10 && j == 0)
        compstr = ft_strncmp(str, INT_STR_UPPER, strlen );
        ft_printf("resultado de la comparativa %d\n", compstr);
        if(ft_strncmp(str, INT_STR_UPPER, j ) > 0)
        {
            ft_printf("Error 12\n");
            return (1);
        }
    else if (strlen == 11 && j == 1)
    {
        mysubstr = ft_substr(str,j,strlen);
        compstr = ft_strncmp(mysubstr, INT_STR_LOWER, strlen );
        ft_printf("resultado de la comparativa %d\n", compstr);
        if (ft_strncmp(str, INT_STR_LOWER, strlen ) < 0)
        {
            free (mysubstr);
            ft_printf("Error 13\n");
            return (1);
        }
        free (mysubstr);
    }
    ft_printf("No Error out of limits\n");
    return (0);
}

int check_errors(int av, char **ac)
{
    int i;
    int j;
    int resultcmp;

    if(av == 1)
        return (1);
    i = 0;
    j = -1;
    while (ac[++i])
    {
        ft_printf ("string %s\n", ac[i]);
        while(ac[i][++j])
        {
            if(!ft_isdigit(ac[i][j]) && ac[i][j] != '-' && ac[i][j] != ' ')
            {
                ft_printf ("error en valor %c\n", ac[i][j]);
                ft_printf("Error 11\n");
                return (1);
            }
            ft_printf ("revisado caracter %c\n", ac[i][j]);
            if (chk_out_of_lim (ac[i]))
            {
                ft_printf("Error 11\n");
                return (1);
            }
        }
        j = -1;
        ft_printf ("No error Check Errors\n");
    }
    return (0);
}
