#include<stdlib.h>
#include<limits.h>
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
char *ft_strdup(char *str)
{
    int i;
    char *out;

    i = ft_strlen(str);
    out = (char *)malloc((i + 1) * sizeof(char));
    i = -1;
    while(str[++i])
        out[i] = str [i];
    out[i] = '\0';
    return (out);
}
char	*ft_itoa(int nbr)
{
    int i;
    int k;
    int signo;
    char *out;

    i = 0;
    signo = 0;
    if (nbr == INT_MIN)
    {
        out = ft_strdup("-2147483648");
        return (out);
    }
    if (nbr < 0)
    {
        signo = -1;
        i++;
        nbr *= -1;
    }
    k = nbr;
    while( k / 10 > 0)
    {
        k /= 10;;
        i++;
    }
    out = (char *)malloc((i + 1) * sizeof(char));
    if (signo < 0)
        out[0] = '-';
    out[i + 1] = '\0';
    while (i > 0)
    {
        out[i] = nbr % 10 + '0';
        nbr = nbr/ 10;
        i--;
    }
    return (out);
}
