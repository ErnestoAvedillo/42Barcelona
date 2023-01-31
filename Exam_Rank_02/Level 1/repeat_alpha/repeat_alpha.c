#include<unistd.h>

int main (int av, char **ac)
{
	int i;
	unsigned int j;
	unsigned int c;

	if (av != 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	i = -1;
	while (ac[1][++i])
	{
		c = ac[1][i];
		if (c >= 'a' && c<= 'z')
		{
			j = 'a' - 1;
			while (++j <= c)
				write(1, &c, 1);
		}
		else if (c >= 'A' && c <= 'Z')
		{
			j = 'A' - 1;
			while (++j <= c)
				write(1, &c, 1);
		}
		else
			write(1, &c, 1);
	}
	write(1, "\n", 1);
	return (0);
}