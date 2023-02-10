#include<stdlib.h>
#include<stdio.h>

int is_space_or_tab (char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return(0);
}
int wordcount(char *str)
{
    int i;
    int n;

    i = 0;
    if (!is_space_or_tab(str[0]))
        n = 1;
    while(str[++i])
    {
        if (str[i] && (is_space_or_tab(str[i]) && !is_space_or_tab(str[i + 1])))
            n++;
    }
    return (n);
}
char    **ft_split(char *str)
{
    int i;
    int k;
    int n;
    int start;
    char **out;

    n = wordcount(str);
    i = 0;
    k = -1;
    out = (char**) malloc((n + 1) * sizeof(char));
    out[n + 1] = NULL;
    while(str[i])
    {
        while (str[i] && is_space_or_tab(str[i]) )
            i++;
        if(str[i] && !is_space_or_tab(str[i]))
            start = i;
        while (str[i] && !is_space_or_tab(str[i]))
            i++;
        if (start != i)
        {
            k++;
            out[k] = (char *)malloc ((i - start + 1)* sizeof (char));
            n = -1;
            while (start <= i)
            {
                out[k][++n] = str[start];
                start++;
            }
            out[k][n] = '\0';
        }
    }
    return(out);
}

int main (int av, char **ac)
{
    int i = 0;
    char **str;
    if (av == 2)
    str = ft_split (ac[1]);
    printf ("era %s\n", ac[1]);
    while (str[i] != NULL)
    {
        printf("spliteado %i --- %p ---- %s\n", i, str[i], str[i]);
        i++;
    }
    printf("paso\n");
    free (str);
}