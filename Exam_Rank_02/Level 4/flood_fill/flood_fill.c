#include "flood_fill.h"
/*
#include<stdio.h>
void print_tab(char **tab, t_point size)
{
	for (int i = 0; i < size.y; ++i)
	{
		for (int j = 0; j < size.x; ++j)
		{
			printf("%c", tab[i][j]);
			printf("(%i,%i)", i, j);
		}
		printf("\n");
	}
	printf("\n");
}
*/

void fill(char **tab, t_point size, int x, int y, char c)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y || tab[y][x] != c)
	{
		return;
	}
	if (tab[y][x] == c)
	{
		tab[y][x] = 'F';
	}
	fill(tab, size, x + 1, y, c);
	fill(tab, size, x - 1, y, c);
	fill(tab, size, x, y + 1, c);
	fill(tab, size, x, y - 1, c);
}
void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin.x, begin.y, tab[begin.y][begin.x]);
	return;
}