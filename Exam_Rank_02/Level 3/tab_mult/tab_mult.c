#include<unistd.h>

void put_nbr(int n)
{
    unsigned int i;

    if (n >= 10)
    {
        i = n / 10;
        put_nbr(i);
    }
    i= n % 10 + '0';
    write(1, &i, 1);
}

int atoi(char *str)
{
    int i;
    unsigned int out;
    
    out = 0;
    i = 0;
    while(str[i])
    {
        out = out * 10 + str[i] - '0';
        i++;
    }
    return (out);
}

int main (int av, char **ac)
{
    int i;
    int j;
    if (av != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = atoi(ac[1]);
    j = 1;
    while (j < 10)
    {
        put_nbr(j);
        write(1, " x ", 3);
        put_nbr(i);
        write(1, " = ", 3);
        put_nbr(i * j);
        write(1, "\n", 1);
        j++;
    }
}