int is_power_of_2(unsigned int n)
{
	while (n % 2 == 0)
	{
		n /= 2;
		if (n == 1)
			return(1);
	}
	return (0);
}

#include<stdio.h>
int main ()
{
	printf("256 es pot 2? %i\n", is_power_of_2(256));
	printf("253 es pot 2? %i\n", is_power_of_2(253));
}