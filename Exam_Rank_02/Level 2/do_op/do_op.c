#include<unistd.h>
#include<stdlib.h>

void put_nbr(int n)
{
	int i;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10 )
	{
		i = n / 10;
		put_nbr(i);
	}
	i = n % 10 + '0';
	write(1, &i, 1);
}
int main(int av, char **ac)
{
	int i;
	int a;
	int b;

	i = 0;
	if (av == 4)
	{
		a = atoi(ac[1]);
		b = atoi(ac[3]);
		if (ac[2][0] == '+')
			i = a + b;
		else if (ac[2][0] == '-')
			i = a - b;
		else if (ac[2][0] == '*')
			i = a * b;
		else if (ac[2][0] == '/')
			i = a / b;
		put_nbr(i);
	}

	write(1, "\n", 1);
	return (0);
}