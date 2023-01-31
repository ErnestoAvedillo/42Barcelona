#include<unistd.h>
#include<stdio.h>

int main (int av, char **ac)
{
	int i;
	unsigned int c;

	if (av != 2)
		return (0);
	i = -1;
	while (ac[1][++i])
	{
		c = ac[1][i];
		//printf("inicio %i", c);
		if (c >= 'A' && c <= 'Z')
		{
			c += 13;
			if (c > 'Z')
				c -= 26;
		}
		else if (c >= 'a' && c <= 'z')
		{
			c += 13;
			if (c > 'z')
				c -= 26;
		}
		//printf("sallida %i -- %c \n", c, c);
				write(1, &c, 1);
	}
	write(1, "\n", 1);
}