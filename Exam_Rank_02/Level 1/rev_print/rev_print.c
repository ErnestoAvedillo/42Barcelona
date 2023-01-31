#include<unistd.h>

int main (int av, char **ac)
{
	int i;

	if (av != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (ac[1][i] != '\0')
		++i;
	while (--i >= 0)
		write(1, &ac[1][i], 1);
	write(1, "\n", 1);
	return (0);
}