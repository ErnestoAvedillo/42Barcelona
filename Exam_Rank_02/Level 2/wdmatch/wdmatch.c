#include<unistd.h>
int main(int av, char **ac)
{
	int i;
	int j;
	int found;

	if (av == 3)
	{
		i = -1;
		j = 0;
		found = 1;
		while (ac[1][++i])
		{
			if (found)
			{
				found = 0;
				while (ac[2][j] && !found)
				{
					if (ac[1][i] == ac[2][j])
					{
						found = 1;
					}
					j++;
				}
			}
		}
		if (found && !ac[1][i])
		{
			i = -1;
			while (ac[1][++i])
				write(1, &ac[1][i], 1);
		}
	}
	write(1, "\n", 1);
}