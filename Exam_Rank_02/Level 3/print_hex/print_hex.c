#include<unistd.h>
int ft_atoi(char *str)
{
	int i;
	int out;

	i = -1;
	out = 0;
	while (str[++i])
		out = out * 10 + str[i] - '0';
	return (out);
}
void ft_strcpy(char *dst, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
}
void prt_h(int n)
{
	char hex_cod[17];

	ft_strcpy(hex_cod, "0123456789abcdef");
	if (n >= 16)
	{
		n = n / 16;
		prt_h(n);
	}
	write(1, &hex_cod[n % 16], 1);
}

int main(int av, char **ac)
{
	int val;

	if (av == 2)
	{
		val = ft_atoi(ac[1]);
		prt_h(val);
	}
	write(1, "\n", 1);
}