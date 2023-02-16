#include<unistd.h>
#include<stdio.h>
int is_tab_or_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

int pos_second_word(char *str)
{
    int i;

    i = 0;
    while(is_tab_or_space(str[i]) && str[i])
        i++;
    while(!is_tab_or_space(str[i]) && str[i])
        i++;
    while(is_tab_or_space(str[i]) && str[i])
        i++;
    return (i);
}

int ft_strlen (char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
int main(int av, char **ac)
{
    int i;
    int end;
    int one_word;
    if (av >= 2)
    {
        one_word = 1;
        i = ft_strlen(ac[1]) - 1;
        while (is_tab_or_space(ac[1][i]))
            i--;
        end = i;
        i = pos_second_word(ac[1]);
        while(i <= end && ac[1][i])
        {
            if (is_tab_or_space(ac[1][i]))  
            {
                write(1, " ", 1);
                while(is_tab_or_space(ac[1][i]))
                    i++;
            }
            else
            {
                write(1, &ac[1][i++], 1);
                one_word = 0;
            }
        }
        if (!one_word)
            write(1, " ", 1);
        i = 0;
        while (is_tab_or_space(ac[1][i]) && ac[1][i])
            i++;
        while (!is_tab_or_space(ac[1][i]) && ac[1][i])
            write(1, &ac[1][i++], 1);        
    }
    write(1, "\n", 1);
}