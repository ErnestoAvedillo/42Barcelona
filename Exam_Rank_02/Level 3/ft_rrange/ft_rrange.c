#include<stdlib.h>
int ft_abs ( int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}
int *ft_range(int start, int end)
{
	int i;
	int *tab;
	int sentido;

	tab = (int *)malloc((ft_abs(start - end) + 1) * sizeof(int));
	sentido = 1;
	if (end < start)
		sentido = -1;
	i = 0;
	while (end != start - sentido)
	{
		tab[i] = end;
		end -= sentido;
		i++;
	}
	return (tab);
}


#include<stdio.h>
void print_tab(int *tab, int start, int end)
{
	int i;
	int j;
	i = ft_abs(start - end);
	j = -1;
	while (++j <= i)
		printf("%i,", tab[j]);
	printf("\n");
}
/*
int main()
{
	int *tab;

	tab = ft_range(0, 3);
	print_tab(tab, 0, 3);
	free(tab);
	tab = ft_range(0, -3);
	print_tab(tab, 0, -3);
	free(tab);
	tab = ft_range(-1, 2);
	print_tab(tab, -1, 2);
	free(tab);
	tab = ft_range(3, 3);
	print_tab(tab, 3, 3);
	free(tab);
}*/
