#include <stdio.h>

int	ft_fibonacci(int index)
{
	int	value;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);	
	if (index == 1)
		return (1);

	value = ft_fibonacci (index - 1) + ft_fibonacci (index - 2);
	return (value);
}