#include<unistd.h>
#include<stdlib.h>
void put_nbr(int n)
{
    int i;

    if (n >= 10)
    {
        i = n / 10;
        put_nbr(i);
    }
    i = n % 10 + '0';
    write(1, &i, 1);
}

int main (int av, char **ac)
{
    int i;
    int n;

    if (av == 2)
    {
        n =  atoi(ac[1]);
        if (n <= 0)
        {
            write(1, "\n", 1);
            return (0);
        }
        if (n == 1)
            write(1, "1", 1);
        i = 2;
        while (n != 1)
        {
            while (n % i == 0)
            {
                put_nbr(i);
                n /= i;
                if (n != 1)
                    write (1, "*", 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}