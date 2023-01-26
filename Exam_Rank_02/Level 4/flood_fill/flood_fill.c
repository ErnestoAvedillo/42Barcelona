#include "flood_fill.h"
#include<stdio.h>
void print_tab(char **tab, t_point size)
{
	for (int i = 0; i < size.y; ++i)
	{
		for (int j = 0; j < size.x; ++j)
			printf("%c", tab[i][j]);
		printf("\n");
	}
	printf("\n");
}

void fill(char **tab, t_point size, int x, int y, char c)
{   
//	printf("paso3\n");
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
	{
		printf("paso2\n");
		return;
	}
	printf("paso4 %i -- %i\n",x, y);
//	print_tab(tab, size);
//	printf("paso4 %i\n", tab[begin.x][begin.y]);
//	printf("paso4 %i -- %i  -> %i\n",begin.x, begin.y, tab[begin.x][begin.y]);
//	if (tab[begin.x][begin.y] == c)
//	{
//		printf("paso5\n");
//		tab[begin.x][begin.y] = 'F';
//	}
//	printf("paso1\n");
	fill(tab, size, x + 1, y, c);
	fill(tab, size, x - 1, y, c);
	fill(tab, size, x, y + 1, c);
	fill(tab, size, x, y - 1, c);
}
void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill (tab, size, begin.x, begin.y ,tab[begin.x][begin.y]);
	return;
}