/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:06:42 by eavedill          #+#    #+#             */
/*   Updated: 2023/03/26 17:01:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int isdelimiter(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

int nr_words(char *s)
{
    int i;
    int out;

    out = 0;
    i = 0;
    while (isdelimiter(s[i]))
        i++;
    if (s[i] == '\0')
        return (0);
    out++;
    while (s[++i])
    {
        while (isdelimiter(s[i]))
            i++;
        if (s[i] != '\0' && isdelimiter(s[i - 1]))
            out++;
    }
    return (out);
}

char **ft_split(char *str)
{
    int i;
    int start;
    int nr;
    int j;
    char **out;

    nr = nr_words(str);
    if (nr == 0)
    {
        out = (char **)malloc(1 * sizeof(char *));
        return (out);
    }
    out = (char **)malloc((nr + 1) * sizeof(char *));
    out[nr] = NULL;
    i = 0;
    nr = 0;
    while (str[i])
    {
        while (isdelimiter(str[i]) && str[i])
            i++;
        if (!str[i])
            return (out);
        start = i;
        while (!isdelimiter(str[i]) && str[i])
            i++;
        out[nr] = (char *)malloc((i - start + 1) * sizeof(char));
        j = 0;
        while (start < i)
            out[nr][j++] = str[start++];
        out[nr][j] = '\0';
        if (!str[i])
            return (out);
        i++;
        nr++;
    }
    return (out);
}
/*
#include "stdio.h"

int main(int av, char **ac)
{
    int i;
    char **out;

    if (av == 2)
    {
        i = 0;
        out = ft_split(ac[1]);
        while (out[i])
        {
            printf("salida %p --  %s --  %i \n", out[i], out[i], i);
            i++;
        }
    }
}

*/