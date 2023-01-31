#include<unistd.h>

int main(int av, char **ac)
{
	int i;

	if (av != 2)
		return (0);
	i = 0;
	while ((ac[1][i] == ' ' || ac[1][i] == '\t') && ac[1][i])
		i++;
	while (ac[1][i] != ' ' && ac[1][i] != '\t' && ac[1][i])
	{
		write(1, &ac[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}