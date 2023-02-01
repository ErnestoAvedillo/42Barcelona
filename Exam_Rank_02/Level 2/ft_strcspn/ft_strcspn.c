
#include <stddef.h>
size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	int j;

	j = -1;
	while (reject[++j])
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == reject[j])
				return (i);
			i++;
		}
	}
	return (i);
}
#include <stdio.h>
#include <string.h>
int main (int av, char **ac)
{
	if (av == 3)
	{
	printf("%s--%s---%lu\n", ac[1], ac[2], ft_strcspn(ac[1], ac[2]));
	printf("%s--%s---%lu\n", ac[1], ac[2], strcspn(ac[1], ac[2]));
	}
}