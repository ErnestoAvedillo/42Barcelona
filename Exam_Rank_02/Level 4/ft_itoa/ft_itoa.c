char *itoa(int n);
{
    int i;
    char *out;

    i = 0;
    out = n;
    while( n / 10 > 0)
    {
        out /= 10;;
        i++;
    }
    out = (char *)malloc(i + 1 sizeof(char));
    out[i + 1] = '\0';
    while (i >= 0)
    {
        out[i] = n % 10 + '0';
        n = n/ 10;
        i--;
    }
    return (out);
}