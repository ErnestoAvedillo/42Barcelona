#include<unistd.h>
int main (int av, char **ac)
{
	int i;
	int end;
	if (av == 2)
	{
		i = 0;
		while (ac[1][i])
			i++;
		i--;
		while (ac[1][i] == ' ' || ac[1][i] == '\t')
			i--;
		end = i;
		while (ac[1][i] != ' ' && ac[1][i] != '\t')
			i--;
		while(++i <= end)
			write(1, &ac[1][i], 1);
	}
	write(1, "\n", 1);
}