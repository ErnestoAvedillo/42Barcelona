#include<unistd.h>

int is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int get_nbr(char *str)
{
	int i;
	int out;

	out = 0;
	i = -1;
	while (is_digit(str[++i]))
		out = out * 10 + str[i] - '0';
	return (out);
}

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

int is_prime(int n)
{
	int i;

	if (n == 1)
		return (0);
	if (n == 2)
		return (1);
	i = 1;
	while (++i <= n / 2 + 1)
		if (n % i == 0)
			return (0);
	return (1);
}

int sum_primes(int n)
{
	int i;
	int out;

	i = 1;
	out = 0;
	while (++i <= n)
		if (is_prime(i))
		{
			out = out + i;
		}
	return (out);
}

int main (int av, char **ac)
{
	int nbr;
	int sum;
	if (av == 2)
	{
		nbr = get_nbr(ac[1]);
		sum = sum_primes(nbr);
		put_nbr(sum);
	}
	write(1, "\n", 1);
}