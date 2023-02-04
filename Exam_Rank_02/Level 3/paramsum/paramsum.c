#include<unistd.h>
void put_nbr(int i)
{
	if (i >= 10)
	{
		i = i / 10;
		put_nbr(i);
	}
	i = i % 10 + '0';
	write(1, &i, 1);
}

int main (int av, char **ac)
{
	int i;

	i = 0;
	if (ac[0][0] == '0')
		i++;
	put_nbr(av - 1);
	write(1, "\n", 1);
}