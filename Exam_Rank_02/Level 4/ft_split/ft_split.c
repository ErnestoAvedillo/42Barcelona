int is_space_or_tab (char c)
{
    if (c == ' ' || c ='\t')
        return (1);
    else(0);
}
int wordcount(char *str)
{
    int i;

    i = 0;
    if (!is_space_or_tab(str[0]))
        n = 1;
    while(str[++i])
    {
        if (str[i] && (is_space_or_tab(str[i]) && !is_space_or_tab(str[i+1])))
            n++;
    }
    return (n);
}
char    **ft_split(char *str)
{
    int i;
    int n;
    int start;
    char **out;

    n = wordcount(str);
    i = 0;
    *out = (char*) malloc((n + 1) * sizeof(char))
    while(str[i])
    {
        while (is_space_or_tab(str[i]) && str[i])
            i++;
        if(!is_space_or_tab(str[i]) && str[i])
            start = i;
        if(is_space_or_tab(str[i]) && start <= i)
            i++;
        else if()
    }
    return(str);
}