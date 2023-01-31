#include<unistd.h>

int main (int av, char **ac)
{
	int i;
	unsigned int c;

	if (av != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = -1;
	while (ac[1][++i])
	{
		c = ac[1][i];
		if (c >='a' && c <='z')
			c -= 32;
		else if (c >= 'A' && c <= 'Z')
			c += 32;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
	return (0);
}