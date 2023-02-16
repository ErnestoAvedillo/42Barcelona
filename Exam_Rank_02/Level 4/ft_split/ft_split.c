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
        if (str[i + 1] && (is_space_or_tab(str[i]) && !is_space_or_tab(str[i + 1])))
            n++;
    }
    return (n);
}
char    **ft_split(char *str)
{
    int i;
    int k;
    int n;
    int pal;
    int start;
    char **out;

    pal = wordcount(str);
    printf(" palabras %i\n", pal);
    i = 0;
    k = 0;
    out = (char**) malloc((pal + 1) * sizeof(char));
    out[pal] = NULL;
    while(str[i])
    {
        printf("copmleto pr %c --- %s \n", str[i], out[0]);
        while (str[i] && is_space_or_tab(str[i]))
            i++;
        if(str[i] && !is_space_or_tab(str[i]))
            start = i;
        while (str[i] && !is_space_or_tab(str[i]))
            i++;
        printf("start %i i %i k %i pal %i\n", start, i, k , pal);
        if (start < i && k < pal)
        {
            out[k] = (char *)malloc ((i - start + 1)* sizeof (char));
            n = -1;
            printf("inicio out %p\n", &out[k][0]);
            while (start <= i)
            {
                out[k][++n] = str[start];
                printf("spliteado %i , %i --- %c ---- %c\n", k, n, out[k][n], str[start]);
                start++;
            }
            out[k][n] = '\0';
            printf("copmleto bis %i --- %s \n", k, out[k]);
            k++;
        }
    }
    return(out);
}

int main (int av, char **ac)
{
    int i = 0;
    char **str;
    if (av == 2)
    {
        str = ft_split (ac[1]);
        printf ("era %s\n", ac[1]);
        while (str[i] != NULL)
        {
            printf("control %i ---- %p\n", i, str[i]);
            printf("spliteado %i ---- %p ---- %s\n", i, str[i], str[i]);
            i++;
        }
        printf("paso\n");
        free (str);
    }
}