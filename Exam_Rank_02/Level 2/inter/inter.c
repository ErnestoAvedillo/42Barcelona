#include<unistd.h>
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int main (int av, char **ac)
{
	int i;
	int j;
	int k;
	int lenj;
	int dup;

	if (av == 3)
	{
		lenj = ft_strlen(ac[2]);
		i = -1;
		while (ac[1][++i])
		{
			j = -1;
			while (ac[2][++j])
			{
				if (ac[1][i] == ac[2][j])
				{
					dup = 0;
					k = -1;
					while (++k < i)
						if (ac[1][k] == ac[1][i])
							dup = 1;
					if (!dup)
						{
							write(1, &ac[1][i], 1);
							j = lenj -1;
							k = i;
						}
				}
			}	
		}
	}
	write(1, "\n", 1);
}