#include<unistd.h>

void put_nbr(int i)
{
	char c;
	int n;
	if (i >= 10)
	{
			n = (i / 10);
			put_nbr(n);
	}
	c = i % 10 + '0';
	write(1, &c, 1);
}

int main(void)
{
	int i;

	i = 0;
	while (++i <= 100)
	{
		if(i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			put_nbr(i);
			write(1, "\n", 1);
		}
	}
}