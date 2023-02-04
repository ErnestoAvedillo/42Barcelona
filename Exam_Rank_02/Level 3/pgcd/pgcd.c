#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
int main(int av, char **ac)
{
	int i;
	int a;
	int b;


	if (av == 3)
	{
		a = atoi(ac[1]);
		b = atoi(ac[2]);
		i = ft_min(a, b);
		while(a % i != 0 || b % i != 0)
			i--;
		printf("%i", i);
	}
	printf("\n");
}