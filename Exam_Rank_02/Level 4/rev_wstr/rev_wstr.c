#include "unistd.h"

int main(int av, char **ac)
{
    int i;
    int start;
    int end;
    
    if (av != 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    i = 0;
    while (ac[1][i])
        ++i;
    end = i;
    while (--i >= 0)
    {
        if (ac[1][i] == ' ' || ac[1][i] == '\t' || i == 0)
        {
            start = i;
            while (start < end)
                write(1, &ac[1][start++], 1);
            end = i;
            if (i != 0)
                write (1, " ", 1);
        }
    }
}