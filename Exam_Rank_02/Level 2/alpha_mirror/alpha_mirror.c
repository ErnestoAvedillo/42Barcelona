#include<unistd.h>

int main (int av,  char **ac)
{
	int i;
	unsigned int c;

	if (av == 2)
	{
		i = -1;
		while (ac[1][++i])
		{
			c = ac[1][i];
			if (c >= 'a' && c <= 'z')
			{
				c = 'z' + 'a' - c;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				c = 'Z' + 'A' - c;
			}
			write(1, &c, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}