#include<limits.h>
int max(int *tab, unsigned int len)
{
	unsigned int i;
	int max;

	if (!tab || !len)
		return(0);
	i = 0;
	max = INT_MIN;
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
