#include<unistd.h>
char capit(char c)
{
    if (c >='a' && c <= 'z')
        c = c - 32;
    return (c);
}
char lower(char c)
{
    if (c >='A' && c <= 'Z')
        c = c + 32;
    return (c);
}

int main (int av, char **ac)
{
    int i;
    int j;
    char c;

    if (av > 1)
    {
        i = 1;
        while (i <= av)
        {
            j = 0;
            while (ac[i][j])
            {
                c = ac[i][j];
                if (ac[i][j + 1] == '\0' || ac[i][j + 1] == ' ' || ac[i][j + 1] == '\t')
                    c = capit(c);
                else
                    c = lower(c);
                write(1, &c, 1);
                j++;
            }
            i++;
            write(1, "\n", 1);
        }
    }
    write(1, "\n", 1);
}