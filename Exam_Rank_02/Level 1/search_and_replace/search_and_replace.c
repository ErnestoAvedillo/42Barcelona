#include<unistd.h>

int main (int av, char **ac)
{
	int i;

	i = -1;
	if (av != 4 || ac[2][1] != '\0' || ac[3][1] != '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	while (ac[1][++i])
	{
		if (ac[1][i] == ac[2][0])
			write(1, &ac[3][0], 1);
		else
			write(1, &ac[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}