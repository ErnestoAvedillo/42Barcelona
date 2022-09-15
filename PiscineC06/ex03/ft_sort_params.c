#include <unistd.h>
#include <stdio.h>

void	put_char (char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	write(1, "\n", 1);
	return;
}

int	ft_strcmp(char *s1, char *s2)

{
	int	cont1;

	cont1 = 0;
	while (s1[cont1] != '\0')
	{
		if (s1[cont1] != s2[cont1])
			return (s1[cont1] - s2[cont1]);
		cont1++;
	}
	return (0);
}

int	get_first_last_str(int av, char **ac, int is_first )
{
	int	count;
	int	current;

	count = 1;
	current = count;
	while (count <= av -1)
	{
		if (is_first)
		{
			if (ft_strcmp(ac[count],ac[current]) < 0)
				current = count;
		}
		else 
			if (ft_strcmp(ac[count],ac[current]) > 0)
				current = count;

		count++;
	}
	return (current);
}

int main(int av, char **ac)
{
	int	cont1;
	int	cont2;
	int	current;
	int	first;
	int	last;
	int	nr_repetitions;

	cont1 = 1;
	current = cont1;
	first = get_first_last_str(av, ac, 1);
	last = get_first_last_str(av, ac, 0);
	put_char (ac[first]);
	while (cont1 <= av-3)
	{
		//printf("cont1 %d av %d\n", cont1 ,av);
		cont2 = 1;
		current = last;
		nr_repetitions = 1;
		while(cont2 <= av - 1)
		{
			printf("--->entrada %s %s %s %d %d\n", ac[cont2], ac[current], ac[first], ft_strcmp(ac[cont2],ac[current]) <= 0, ft_strcmp(ac[cont2],ac[first]) > 0);
			if ((ft_strcmp(ac[cont2],ac[current]) <= 0) & (ft_strcmp(ac[cont2],ac[first]) > 0))
			{
				printf("entrada en if current vs cont2%d\n", ac[current] == ac[cont2]);
				if (ft_strcmp(ac[cont2],ac[current]) == 0)
				{
					nr_repetitions++;
					printf("entro en repeticiones %s %s %s %d %d\n", ac[cont2], ac[current], ac[first], ft_strcmp(ac[cont2],ac[current]), ft_strcmp(ac[cont2],ac[first]));
				}
				else
				{
					current = cont2;
					nr_repetitions = 1;
				}
			}
			printf("salida %s %s %s %d %d\n", ac[cont2], ac[current], ac[first], ft_strcmp(ac[cont2],ac[current]), ft_strcmp(ac[cont2],ac[last]));
			cont2++;
		}
		first = current;
		cont2 = 1;
		while (cont2 <= nr_repetitions)
			{
				put_char (ac[first]);
				cont2++;
				cont1++;
			}
		//cont1++;
	}
	put_char(ac[last]);

	return (0);
}